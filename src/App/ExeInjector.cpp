#include "ExeInjector.h"

int wmain(void)
{
	DWORD pid = GetProcessIdByName(L"re2.exe");
	if (pid == 0)
		return 1;

	HANDLE handle = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION | PROCESS_CREATE_THREAD, FALSE, pid);
	{
		std::wstring basePath = std::filesystem::current_path().native();
		std::wstring dllPaths[] = {
		    basePath + L"\\RE2RR_Common.dll",
		    basePath + L"\\RE2RR_Types.dll",
		    basePath + L"\\RE2RR_Database.dll",
		    basePath + L"\\RE2RR_Hook.dll"};
		size_t dllPathsLength = sizeof(dllPaths) / sizeof(dllPaths[0]);

		size_t dllPathSize;
		LPVOID pDllPath;
		HANDLE hDllThread;

		for (size_t i = 0; i < dllPathsLength; ++i)
		{
			dllPathSize = GetStringSize(dllPaths[i]);
			pDllPath = VirtualAllocEx(handle, 0, dllPathSize, MEM_COMMIT, PAGE_READWRITE);
			WriteProcessMemory(handle, pDllPath, (LPVOID)dllPaths[i].c_str(), dllPathSize, nullptr);
			hDllThread = CreateRemoteThread(handle, 0, 0, (LPTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandle(L"Kernel32.dll"), "LoadLibraryW"), pDllPath, 0, 0);
			WaitForSingleObject(hDllThread, INFINITE);
			VirtualFreeEx(handle, pDllPath, 0, MEM_RELEASE);
			CloseHandle(hDllThread);
		}
	}
	CloseHandle(handle);

	return 0;
}
