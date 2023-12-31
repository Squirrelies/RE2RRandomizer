#include "RE2RRandomizer.h"

int main(void)
{
	return 0;
}

// void *DetourFunction64(void *pSource, void *pDestination, uint32_t length)
// {
// 	constexpr uint32_t minimumLength = 14;

// 	if (length < minimumLength)
// 		return nullptr;

// 	uint8_t opCodeHex[] = {0xFF, 0x25, 0x00, 0x00, 0x00, 0x00};           // jmp qword ptr [$+6]
// 	uint8_t address[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}; // ptr

// 	void *pTrampoline = VirtualAlloc(0, sizeof(opCodeHex) + sizeof(address) + length, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);

// 	uint32_t oldProtect = 0;
// 	VirtualProtect(pSource, length, PAGE_EXECUTE_READWRITE, (PDWORD)&oldProtect);
// 	uint64_t returnTo = (uint64_t)pSource + length;

// 	// trampoline
// 	memcpy(address, &returnTo, sizeof(address));                                // Place address of returnTo into address variable.
// 	memcpy(pTrampoline, pSource, length);                                       // Write pSource address to the start of pTrampoline.
// 	memcpy(pTrampoline + length, opCodeHex, sizeof(opCodeHex));                 // Write opCodeHex afterwards.
// 	memcpy(pTrampoline + length + sizeof(opCodeHex), address, sizeof(address)); // Write address afterwards.

// 	// orig
// 	memcpy(address, &pDestination, sizeof(address));
// 	memcpy(pSource, opCodeHex, sizeof(opCodeHex));
// 	memcpy(pSource + sizeof(opCodeHex), address, sizeof(address));

// 	for (uint32_t i = minimumLength; i < length; ++i)
// 		*(uint8_t *)(pSource + i) = 0x90;

// 	VirtualProtect(pSource, length, oldProtect, (PDWORD)&oldProtect);

// 	return pTrampoline;
// }
