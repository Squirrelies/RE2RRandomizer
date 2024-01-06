#ifndef MEMORY_H
#define MEMORY_H

#ifndef WIN32_LEAD_AND_MEAN
#define WIN32_LEAD_AND_MEAN
#endif

#include <windows.h>

#include "Process.h"
#include "Strings.h"
#include <psapi.h>
#include <stdint.h>
#include <stdio.h>
#include <vector>

#define MEMORYAPI __declspec(dllexport)

#ifdef __cplusplus
extern "C"
{
#endif

	/// @brief Attempts to find the first memory offset for the pattern relative to the base address of the given module.
	/// @param moduleName The module to search the pattern within.
	/// @param pattern The pattern to search for.
	/// @param offset The first offset, if found.
	/// @param startOffset A starting offset, if supplied.
	/// @return Whether or not we succeeded in finding the pattern.
	MEMORYAPI bool TryFindPatternOffset(TCHAR *moduleName, std::vector<char16_t> pattern, uint64_t *offset, uint64_t startOffset = 0ULL)
	{
		MODULEINFO moduleInfo;
		if (!TryGetModuleInfo(moduleName, &moduleInfo))
			return false;

		auto base = reinterpret_cast<uintptr_t>(moduleInfo.lpBaseOfDll) + startOffset;
		auto size = (uint64_t)moduleInfo.SizeOfImage;
		auto patternLength = (uint64_t)pattern.size();

		for (unsigned int i = 0; i < size - patternLength; ++i)
		{
			bool found = true;
			for (uint64_t j = 0; j < patternLength; ++j)
				found &= pattern[j] >= (char16_t)0x100 || pattern[j] == *(uint8_t *)(base + i + j);
			if (found)
			{
				*offset = i;
				return true;
			}
		}

		return false;
	}

	/// @brief Attempts to find the first memory address for the pattern in the given module.
	/// @param moduleName The module to search the pattern within.
	/// @param pattern The pattern to search for.
	/// @param address The first address, if found.
	/// @param startOffset A starting offset, if supplied.
	/// @return Whether or not we succeeded in finding the pattern.
	MEMORYAPI bool TryFindPatternAddress(TCHAR *moduleName, std::vector<char16_t> pattern, uintptr_t *address, uint64_t startOffset = 0ULL)
	{
		MODULEINFO moduleInfo;
		if (!TryGetModuleInfo(moduleName, &moduleInfo))
			return false;

		uint64_t offset;
		if (!TryFindPatternOffset(moduleName, pattern, &offset, startOffset))
			return false;

		*address = reinterpret_cast<uintptr_t>(moduleInfo.lpBaseOfDll) + offset;
		return true;
	}

#ifdef __cplusplus
}
#endif

#endif
