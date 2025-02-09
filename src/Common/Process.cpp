#include "Process.h"

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
			if (!TSTRICMP(process.szExeFile, name))
			{
				pid = process.th32ProcessID;
				break;
			}
		} while (Process32Next(snapshot, &process));
	}
	CloseHandle(snapshot);

	return pid;
}

HMODULE GetProcessModuleByName(HANDLE hProcess, TCHAR moduleName[])
{
	HMODULE hMods[1024];
	DWORD cbNeeded;
	unsigned int i;

	// Get a list of all the modules in this process.
	if (EnumProcessModules(hProcess, hMods, sizeof(hMods), &cbNeeded))
	{
		for (i = 0; i < (cbNeeded / sizeof(HMODULE)); i++)
		{
			TCHAR szModName[MAX_PATH];
			// Get the full path to the module's file.
			if (GetModuleFileNameEx(hProcess, hMods[i], szModName, sizeof(szModName) / sizeof(TCHAR)))
			{
				if (TSTRICMP(szModName, moduleName))
					return hMods[i];
			}
		}
	}

	return NULL;
}

std::unique_ptr<char[]> GetProcessModulePathByNameA(HANDLE hProcess, const char moduleName[])
{
	HMODULE hMods[1024];
	DWORD cbNeeded;
	unsigned int i;

	// Get a list of all the modules in this process.
	if (EnumProcessModules(hProcess, hMods, sizeof(hMods), &cbNeeded))
	{
		size_t szModNameSize = (MAX_PATH * sizeof(char)) + sizeof(char);
		std::unique_ptr<char[]> szModName = std::make_unique<char[]>(szModNameSize);
		for (i = 0; i < (cbNeeded / sizeof(HMODULE)); i++)
		{
			// Get the full path to the module's file.
			if (GetModuleFileNameExA(hProcess, hMods[i], szModName.get(), szModNameSize))
			{
				if (stricmp(szModName.get(), moduleName))
					return szModName;
			}
		}
	}

	return nullptr;
}

std::unique_ptr<wchar_t[]> GetProcessModulePathByNameW(HANDLE hProcess, wchar_t moduleName[])
{
	HMODULE hMods[1024];
	DWORD cbNeeded;
	unsigned int i;

	// Get a list of all the modules in this process.
	if (EnumProcessModules(hProcess, hMods, sizeof(hMods), &cbNeeded))
	{
		size_t szModNameSize = (MAX_PATH * sizeof(wchar_t)) + sizeof(wchar_t);
		std::unique_ptr<wchar_t[]> szModName = std::make_unique<wchar_t[]>(szModNameSize);
		for (i = 0; i < (cbNeeded / sizeof(HMODULE)); i++)
		{
			// Get the full path to the module's file.
			if (GetModuleFileNameExW(hProcess, hMods[i], szModName.get(), szModNameSize))
			{
				if (wcsicmp(szModName.get(), moduleName))
					return szModName;
			}
		}
	}

	return nullptr;
}

bool TryGetModuleInfo(HANDLE hProcess, HMODULE hModule, MODULEINFO *moduleInfo)
{
	if (!GetModuleInformation(hProcess, hModule, moduleInfo, sizeof(MODULEINFO)))
	{
		printf("Failed to retrieve module information!\n");
		return false;
	}

	return true;
}
