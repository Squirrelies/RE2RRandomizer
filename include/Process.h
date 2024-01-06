#ifndef PROCESS_H
#define PROCESS_H

#ifndef WIN32_LEAD_AND_MEAN
#define WIN32_LEAD_AND_MEAN
#endif

#include <windows.h>

#include "Strings.h"
#include <psapi.h>
#include <stdio.h>
#include <tchar.h>
#include <tlhelp32.h>

#define PROCESSAPI __declspec(dllexport)

#ifdef __cplusplus
extern "C"
{
#endif

	/// @brief Retrieves the process identifier by the process name.
	/// @param name The process name to find the identifier for.
	/// @return The process identifier if found, otherwise 0.
	PROCESSAPI DWORD GetProcessIdByName(const TCHAR *name)
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

	/// @brief Gets the module handle for the given name within the current process.
	/// @param moduleName The module name to retrieve a handle for.
	/// @return The module handle if found. Otherwise this will be NULL.
	PROCESSAPI HMODULE GetProcessModuleByName(TCHAR moduleName[])
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

	/// @brief Attempts to get the module info for the given name within the current process.
	/// @param moduleName The module name to retrieve module info for.
	/// @param moduleInfo The module info, if found.
	/// @return Whether or not we succeeded in locating the module info.
	PROCESSAPI bool TryGetModuleInfo(TCHAR *moduleName, MODULEINFO *moduleInfo)
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

#ifdef __cplusplus
}
#endif

#endif
