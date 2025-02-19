#include "Memory.h"

namespace RE2RR::Common::Memory
{
	bool TryFindPatternOffset(HANDLE hProcess, HMODULE hModule, std::vector<char16_t> pattern, uint64_t *offset, uint64_t startOffset)
	{
		MODULEINFO moduleInfo;
		if (!RE2RR::Common::Process::TryGetModuleInfo(hProcess, hModule, &moduleInfo))
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

	bool TryFindPatternOffset(HANDLE hProcess, TCHAR *moduleName, std::vector<char16_t> pattern, uint64_t *offset, uint64_t startOffset)
	{
		HMODULE hModule;
		if (!(hModule = RE2RR::Common::Process::GetProcessModuleByName(hProcess, moduleName)))
			return false;

		return TryFindPatternOffset(hProcess, moduleName, pattern, offset, startOffset);
	}

	bool TryFindPatternAddress(HANDLE hProcess, HMODULE hModule, std::vector<char16_t> pattern, uintptr_t *address, uint64_t startOffset)
	{
		MODULEINFO moduleInfo;
		if (!RE2RR::Common::Process::TryGetModuleInfo(hProcess, hModule, &moduleInfo))
			return false;

		uint64_t offset;
		if (!TryFindPatternOffset(hProcess, hModule, pattern, &offset, startOffset))
			return false;

		*address = reinterpret_cast<uintptr_t>(moduleInfo.lpBaseOfDll) + offset;
		return true;
	}

	bool TryFindPatternAddress(HANDLE hProcess, TCHAR *moduleName, std::vector<char16_t> pattern, uintptr_t *address, uint64_t startOffset)
	{
		HMODULE hModule;
		if (!(hModule = RE2RR::Common::Process::GetProcessModuleByName(hProcess, moduleName)))
			return false;

		return TryFindPatternAddress(hProcess, hModule, pattern, address, startOffset);
	}

	bool TryReadPointer(const void *pointer, const std::vector<uint32_t> &&offsets, void **object, const char *pointerName, RE2RR::Common::Logging::ImmediateLogger &logger)
	{
		logger.LogMessage("[TrySetPointer: %s] Begin %s: %p\n", pointerName, NAMEOF(pointer), pointer);
		try
		{
			*object = (void *)pointer;
			for (size_t i = 0; i < offsets.size(); ++i)
			{
				if ((void *)((uintptr_t)*object + offsets[i]) == nullptr)
				{
					logger.LogMessage("[TrySetPointer: %s] Failure %s: %p\n", pointerName, NAMEOF(object), *object);
					return false;
				}
				*object = (void *)((uintptr_t)*object + offsets[i]);
			}
			logger.LogMessage("[TrySetPointer: %s] Success %s: %p\n", pointerName, NAMEOF(object), *object);
			return true;
		}
		catch (const std::exception &ex)
		{
			RE2RR::Common::lastExceptionMessage = ex.what();
			logger.LogMessage("[TrySetPointer: %s] Exception: %s\n",
			                  pointerName,
			                  RE2RR::Common::lastExceptionMessage);
			return false;
		}
	}

	consteval uint16_t EndianSwap(const uint16_t value) noexcept
	{
		return static_cast<uint16_t>((value & 0xFFU) << 8 | (value & 0xFF00U) >> 8);
	}

	consteval uint32_t EndianSwap(const uint32_t value) noexcept
	{
		return static_cast<uint32_t>((value & 0x000000FFU) << 24 | (value & 0x0000FF00U) << 8 | (value & 0x00FF0000U) >> 8 | (value & 0xFF000000U) >> 24);
	}

	consteval uint64_t EndianSwap(const uint64_t value) noexcept
	{
		return static_cast<uint64_t>((value & 0x00000000000000FFUL) << 56 | (value & 0x000000000000FF00UL) << 40 | (value & 0x0000000000FF0000UL) << 24 | (value & 0x00000000FF000000UL) << 8 | (value & 0x000000FF00000000UL) >> 8 | (value & 0x0000FF0000000000UL) >> 24 | (value & 0x00FF000000000000UL) >> 40 | (value & 0xFF00000000000000UL) >> 56);
	}
}
