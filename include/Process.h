#ifndef RE2RR_PROCESS_H
#define RE2RR_PROCESS_H

#include "Common.h"
#include "Strings.h"
#include <psapi.h>
#include <stdio.h>
#include <tchar.h>
#include <tlhelp32.h>
#include <windows.h>

#ifdef __cplusplus
extern "C"
{
#endif

	/// @brief Retrieves the process identifier by the process name.
	/// @param name The process name to find the identifier for.
	/// @return The process identifier if found, otherwise 0.
	LIBRARY_EXPORT_API DWORD GetProcessIdByName(const TCHAR *name);

	/// @brief Gets the module handle for the given name within the provided process.
	/// @param hProcess The process to find the module in.
	/// @param moduleName The module name to retrieve a handle for.
	/// @return The module handle if found. Otherwise this will be NULL.
	LIBRARY_EXPORT_API HMODULE GetProcessModuleByName(HANDLE hProcess, TCHAR moduleName[]);

	/// @brief Gets the full path for the given module name within the provided process.
	/// @param hProcess The process to find the module in.
	/// @param moduleName The module name to retrieve the path for.
	/// @return The module's full path if found. Otherwise this will be NULL.
	LIBRARY_EXPORT_API char *GetProcessModulePathByNameA(HANDLE hProcess, const char moduleName[]);

	/// @brief Gets the full path for the given module name within the provided process.
	/// @param hProcess The process to find the module in.
	/// @param moduleName The module name to retrieve the path for.
	/// @return The module's full path if found. Otherwise this will be NULL.
	LIBRARY_EXPORT_API wchar_t *GetProcessModulePathByNameW(HANDLE hProcess, const wchar_t moduleName[]);

#ifndef GetProcessModulePathByName
#ifdef UNICODE
#define GetProcessModulePathByName GetProcessModulePathByNameW
#else
#define GetProcessModulePathByName GetProcessModulePathByNameA
#endif
#endif

	/// @brief Attempts to get the module info for the given module handle within the provided process.
	/// @param hProcess The process to get the module info from.
	/// @param hModule The module to retrieve module info for.
	/// @param moduleInfo The module info, if found.
	/// @return Whether or not we succeeded in locating the module info.
	LIBRARY_EXPORT_API bool TryGetModuleInfo(HANDLE hProcess, HMODULE hModule, MODULEINFO *moduleInfo);

#ifdef __cplusplus
}
#endif

#endif
