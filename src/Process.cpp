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

HMODULE GetProcessModuleByName(TCHAR moduleName[])
{
	HMODULE hMods[1024];
	HANDLE hProcess = GetCurrentProcess();
	DWORD cbNeeded;
	unsigned int i;

	// Get a list of all the modules in this process.
	if (EnumProcessModules(GetCurrentProcess(), hMods, sizeof(hMods), &cbNeeded))
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

bool TryGetModuleInfo(TCHAR *moduleName, MODULEINFO *moduleInfo)
{
	HMODULE hModule;
	if ((hModule = GetModuleHandle(moduleName)) == NULL)
	{
#ifdef UNICODE
		printf("Module \"%ls\" not found!\n", moduleName);
#else
		printf("Module \"%s\" not found!\n", moduleName);
#endif
		return false;
	}

	if (!GetModuleInformation(GetCurrentProcess(), hModule, moduleInfo, sizeof(MODULEINFO)))
	{
#ifdef UNICODE
		printf("Failed to retrieve module information for \"%ls\"!\n", moduleName);
#else
		printf("Failed to retrieve module information for \"%s\"!\n", moduleName);
#endif
		return false;
	}

	return true;
}
