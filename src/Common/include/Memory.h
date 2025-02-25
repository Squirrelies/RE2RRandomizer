#ifndef RE2RR_MEMORY_H
#define RE2RR_MEMORY_H

#include "Common.h"
#include "Logging.h"
#include "Process.h"
#include "Strings.h"
#include <psapi.h>
#include <stdbool.h>
#include <stdexcept>
#include <stdint.h>
#include <stdio.h>
#include <vector>
#include <windows.h>

namespace RE2RR::Common::Memory
{
	/// @brief Attempts to find the first memory offset for the pattern relative to the base address of the given module.
	/// @param hProcess The process to search the pattern within.
	/// @param hModule The module to search the pattern within.
	/// @param pattern The pattern to search for.
	/// @param offset The first offset, if found.
	/// @param startOffset A starting offset, if supplied.
	/// @return Whether or not we succeeded in finding the pattern.
	LIBRARY_EXPORT_API bool TryFindPatternOffset(HANDLE hProcess, HMODULE hModule, std::vector<char16_t> pattern, uint64_t *offset, uint64_t startOffset = 0ULL);

	/// @brief Attempts to find the first memory offset for the pattern relative to the base address of the given module.
	/// @param hProcess The process to search the pattern within.
	/// @param moduleName The module to search the pattern within.
	/// @param pattern The pattern to search for.
	/// @param offset The first offset, if found.
	/// @param startOffset A starting offset, if supplied.
	/// @return Whether or not we succeeded in finding the pattern.
	LIBRARY_EXPORT_API bool TryFindPatternOffset(HANDLE hProcess, TCHAR *moduleName, std::vector<char16_t> pattern, uint64_t *offset, uint64_t startOffset = 0ULL);

	/// @brief Attempts to find the first memory address for the pattern in the given module.
	/// @param hProcess The process to search the pattern within.
	/// @param hModule The module to search the pattern within.
	/// @param pattern The pattern to search for.
	/// @param address The first address, if found.
	/// @param startOffset A starting offset, if supplied.
	/// @return Whether or not we succeeded in finding the pattern.
	LIBRARY_EXPORT_API bool TryFindPatternAddress(HANDLE hProcess, HMODULE hModule, std::vector<char16_t> pattern, uintptr_t *address, uint64_t startOffset = 0ULL);

	/// @brief Attempts to find the first memory address for the pattern in the given module.
	/// @param hProcess The process to search the pattern within.
	/// @param moduleName The module to search the pattern within.
	/// @param pattern The pattern to search for.
	/// @param address The first address, if found.
	/// @param startOffset A starting offset, if supplied.
	/// @return Whether or not we succeeded in finding the pattern.
	LIBRARY_EXPORT_API bool TryFindPatternAddress(HANDLE hProcess, TCHAR *moduleName, std::vector<char16_t> pattern, uintptr_t *address, uint64_t startOffset = 0ULL);

	/// @brief Sets the object parameter by crawling from start through the offsets.
	/// @param pointer The pointer to start the read from.
	/// @param offsets The offsets to use as we traverse the pointer chain.
	/// @param object The pointer pointer to set to the pointer we discovered at the end of the chain.
	/// @param pointerName The name of the pointer for logging purposes.
	/// @param logger An instance of ImmediateLogger to log messages to.
	/// @return A boolean indicating whether we succeeded in traversing the pointer chain.
	LIBRARY_EXPORT_API bool TryReadPointer(const void *pointer, const std::vector<uint32_t> &&offsets, void **object, const char *pointerName, RE2RR::Common::Logging::ImmediateLogger &logger);

	/// @brief Tries to validate whether the pointer is valid or not to avoid access violation errors.
	/// @param pointer The pointer to validate.
	/// @param pointerName The name of the pointer for logging purposes.
	/// @param logger An instance of ImmediateLogger to log messages to.
	/// @return A boolean indicating whether the start of the pointer is valid.
	LIBRARY_EXPORT_API bool TryValidatePointerStart(const void *pointer, const char *pointerName, RE2RR::Common::Logging::ImmediateLogger &logger);

	/// @brief Swaps the endianness of a 16-bit unsigned integer.
	/// @param value The value to swap endianness on.
	/// @return The endian swapped value.
	LIBRARY_EXPORT_API consteval uint16_t EndianSwap(const uint16_t value) noexcept;

	/// @brief Swaps the endianness of a 32-bit unsigned integer.
	/// @param value The value to swap endianness on.
	/// @return The endian swapped value.
	LIBRARY_EXPORT_API consteval uint32_t EndianSwap(const uint32_t value) noexcept;

	/// @brief Swaps the endianness of a 64-bit unsigned integer.
	/// @param value The value to swap endianness on.
	/// @return The endian swapped value.
	LIBRARY_EXPORT_API consteval uint64_t EndianSwap(const uint64_t value) noexcept;
}

#endif
