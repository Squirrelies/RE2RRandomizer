#include "ExeInjector.h"

// int wmain(int argc, wchar_t *argv[])
int wmain(void)
{
	DWORD pid = GetProcessIdByName(L"re2.exe");
	if (pid == 0)
		return 1;

	std::wstring dllPath = std::filesystem::current_path().native() + L"\\libRE2RRandomizerHook.dll";
	size_t dllPathSize = GetStringSize(dllPath);
	HANDLE handle = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION | PROCESS_CREATE_THREAD, FALSE, pid);

	char *gameExePath = GetProcessModulePathByNameA(handle, "re2.exe");
	uint8_t *gameExeSHA256Hash = RE2RRFile::GetFileHashSHA256(gameExePath);
	std::vector<uint8_t> hashVector = RE2RRFile::HashSHA256ToVector(gameExeSHA256Hash);
	free(gameExeSHA256Hash);
	printf("Game hash: { %s };\n", RE2RRFile::VectorToHexString(hashVector).c_str());

	// { 0xF2, 0x6C, 0xDE, 0xBF, 0xFE, 0x66, 0x55, 0xD0, 0x5B, 0xF0, 0x04, 0x7F, 0x79, 0x39, 0xEA, 0x5E, 0x38, 0x36, 0x08, 0xAF, 0xF4, 0x60, 0x3C, 0xA3, 0xF0, 0xF3, 0x6A, 0x12, 0xDC, 0x56, 0x23, 0xCA }
	// { 242, 108, 222, 191, 254, 102, 85, 208, 91, 240, 4, 127, 121, 57, 234, 94, 56, 54, 8, 175, 244, 96, 60, 163, 240, 243, 106, 18, 220, 86, 35, 202 }

	LPVOID pDllPath = VirtualAllocEx(handle, 0, dllPathSize, MEM_COMMIT, PAGE_READWRITE);
	WriteProcessMemory(handle, pDllPath, (LPVOID)dllPath.c_str(), dllPathSize, nullptr);
	HANDLE hLoadThread = CreateRemoteThread(handle, 0, 0, (LPTHREAD_START_ROUTINE)(void *)GetProcAddress(GetModuleHandle(L"Kernel32.dll"), "LoadLibraryW"), pDllPath, 0, 0);
	WaitForSingleObject(hLoadThread, INFINITE);
	VirtualFreeEx(handle, pDllPath, 0, MEM_RELEASE);
	CloseHandle(handle);

	return 0;
}
