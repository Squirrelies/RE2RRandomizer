#include "ExeInjector.h"

int wmain(void)
{
	std::wcout << L"Searching for running process named re2.exe... ";
	DWORD pid = RE2RR::Common::Process::GetProcessIdByName(L"re2.exe");
	if (pid == 0)
	{
		std::wcout << L"not found!" << std::endl;
		std::wcout << L"Failure, exiting..." << std::endl;
		return 1;
	}
	std::wcout << L"found! PID: " << pid << std::endl;

	HANDLE handle = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION | PROCESS_CREATE_THREAD, FALSE, pid);
	{
		std::wstring basePath = std::filesystem::current_path().native();
		std::wstring dllPaths[] = {
		    basePath + L"\\RE2RR.Common.dll",
		    basePath + L"\\RE2RR.Types.dll",
		    basePath + L"\\RE2RR.Database.dll",
		    basePath + L"\\RE2RR.Hook.dll"};
		size_t dllPathsLength = sizeof(dllPaths) / sizeof(dllPaths[0]);

		size_t dllPathSize;
		LPVOID pDllPath;
		HANDLE hDllThread;

		std::wcout << L"Injecting DLLs..." << std::endl;
		for (size_t i = 0; i < dllPathsLength; ++i)
		{
			std::wcout << L"\tDLL: " << dllPaths[i] << " ";
			dllPathSize = RE2RR::Common::Strings::GetStringSize(dllPaths[i]);
			pDllPath = VirtualAllocEx(handle, 0, dllPathSize, MEM_COMMIT, PAGE_READWRITE);
			WriteProcessMemory(handle, pDllPath, (LPVOID)dllPaths[i].c_str(), dllPathSize, nullptr);
			hDllThread = CreateRemoteThread(handle, 0, 0, (LPTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandle(L"Kernel32.dll"), "LoadLibraryW"), pDllPath, 0, 0);
			WaitForSingleObject(hDllThread, INFINITE);
			VirtualFreeEx(handle, pDllPath, 0, MEM_RELEASE);
			CloseHandle(hDllThread);
			std::wcout << L"complete." << std::endl;
		}
		std::wcout << L"DLL injection completed." << std::endl;
	}
	CloseHandle(handle);

	std::wcout << L"Success, exiting..." << std::endl;
	return 0;
}
