#ifndef RE2RR_PROCESS_H
#define RE2RR_PROCESS_H

#ifndef UNICODE
#define UNICODE
#endif

#ifndef _UNICODE
#define _UNICODE
#endif

#ifndef WIN32_LEAD_AND_MEAN
#define WIN32_LEAD_AND_MEAN
#endif

#include <windows.h>

#include "Strings.h"
#include <psapi.h>
#include <stdio.h>
#include <tchar.h>
#include <tlhelp32.h>

#define RE2RRPROCESSAPI __declspec(dllexport)

#ifdef __cplusplus
extern "C"
{
#endif

	/// @brief Retrieves the process identifier by the process name.
	/// @param name The process name to find the identifier for.
	/// @return The process identifier if found, otherwise 0.
	RE2RRPROCESSAPI DWORD GetProcessIdByName(const TCHAR *name);

	/// @brief Gets the module handle for the given name within the current process.
	/// @param moduleName The module name to retrieve a handle for.
	/// @return The module handle if found. Otherwise this will be NULL.
	RE2RRPROCESSAPI HMODULE GetProcessModuleByName(TCHAR moduleName[]);

	/// @brief Attempts to get the module info for the given name within the current process.
	/// @param moduleName The module name to retrieve module info for.
	/// @param moduleInfo The module info, if found.
	/// @return Whether or not we succeeded in locating the module info.
	RE2RRPROCESSAPI bool TryGetModuleInfo(TCHAR *moduleName, MODULEINFO *moduleInfo);

#ifdef __cplusplus
}
#endif

#endif
