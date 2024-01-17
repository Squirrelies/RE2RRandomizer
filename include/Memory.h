#ifndef RE2RR_MEMORY_H
#define RE2RR_MEMORY_H

#ifndef UNICODE
#define UNICODE
#endif

#ifndef _UNICODE
#define _UNICODE
#endif

#ifndef WIN32_LEAD_AND_MEAN
#define WIN32_LEAD_AND_MEAN
#endif

#include <windows.h>

#include "Process.h"
#include "Strings.h"
#include <psapi.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <vector>

#define RE2RRMEMORYAPI __declspec(dllexport)

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
	RE2RRMEMORYAPI bool TryFindPatternOffset(TCHAR *moduleName, std::vector<char16_t> pattern, uint64_t *offset, uint64_t startOffset = 0ULL);

	/// @brief Attempts to find the first memory address for the pattern in the given module.
	/// @param moduleName The module to search the pattern within.
	/// @param pattern The pattern to search for.
	/// @param address The first address, if found.
	/// @param startOffset A starting offset, if supplied.
	/// @return Whether or not we succeeded in finding the pattern.
	RE2RRMEMORYAPI bool TryFindPatternAddress(TCHAR *moduleName, std::vector<char16_t> pattern, uintptr_t *address, uint64_t startOffset = 0ULL);

#ifdef __cplusplus
}
#endif

#endif
