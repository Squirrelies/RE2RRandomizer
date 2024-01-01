#ifndef RE2RRANDOMIZER_H
#define RE2RRANDOMIZER_H

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

#define RE2RRANDOMIZERAPI __declspec(dllexport)

#include <filesystem>
#include <tchar.h>
#include <tlhelp32.h>

template <typename charT>
RE2RRANDOMIZERAPI size_t GetStringSize(std::__cxx11::basic_string<charT> string);
RE2RRANDOMIZERAPI DWORD GetProcessIdByName(const TCHAR *name);
// RE2RRANDOMIZERAPI void *DetourFunction64(void *pSource, void *pDestination, uint32_t length);

#endif
