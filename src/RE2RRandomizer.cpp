#include "RE2RRandomizer.h"

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
