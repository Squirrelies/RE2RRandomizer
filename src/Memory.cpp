#include "Memory.h"

bool TryFindPatternOffset(TCHAR *moduleName, std::vector<char16_t> pattern, uint64_t *offset, uint64_t startOffset)
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

bool TryFindPatternAddress(TCHAR *moduleName, std::vector<char16_t> pattern, uintptr_t *address, uint64_t startOffset)
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