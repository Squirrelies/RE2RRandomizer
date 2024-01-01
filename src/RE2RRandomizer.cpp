#include "RE2RRandomizer.h"
#include <tlhelp32.h>

// int wmain(int argc, wchar_t *argv[])
int wmain(void)
{
	DWORD pid = GetProcessIdByName(L"re2.exe");
	if (pid == 0)
		return 1;

	std::wstring dllPath = std::filesystem::current_path().native() + L"\\libRE2RRandomizerHook.dll";
	size_t dllPathSize = GetStringSize(dllPath);
	HANDLE handle = OpenProcess(PROCESS_VM_WRITE | PROCESS_VM_OPERATION | PROCESS_CREATE_THREAD, FALSE, pid);
	LPVOID pDllPath = VirtualAllocEx(handle, 0, dllPathSize, MEM_COMMIT, PAGE_READWRITE);
	WriteProcessMemory(handle, pDllPath, (LPVOID)dllPath.c_str(), dllPathSize, nullptr);
	LPTHREAD_START_ROUTINE addressKernel32LoadLibrary = reinterpret_cast<LPTHREAD_START_ROUTINE>(GetProcAddress(GetModuleHandle(L"Kernel32.dll"), "LoadLibraryW"));
	HANDLE hLoadThread = CreateRemoteThread(handle, 0, 0, addressKernel32LoadLibrary, pDllPath, 0, 0);
	WaitForSingleObject(hLoadThread, INFINITE);
	VirtualFreeEx(handle, pDllPath, 0, MEM_RELEASE);
	CloseHandle(handle);

	return 0;
}

template <typename charT>
size_t GetStringSize(std::__cxx11::basic_string<charT> string)
{
	return (string.length() * sizeof(charT)) + sizeof(charT);
}

DWORD GetProcessIdByName(const TCHAR *name)
{
	DWORD pid = 0;

	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	PROCESSENTRY32 process;
	process.dwSize = sizeof(process);
	if (Process32First(snapshot, &process))
	{
		do
		{
			if (!_tcscmp(process.szExeFile, name))
			{
				pid = process.th32ProcessID;
				break;
			}
		} while (Process32Next(snapshot, &process));
	}
	CloseHandle(snapshot);

	return pid;
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
