#ifndef RE2RR_STRINGS_H
#define RE2RR_STRINGS_H

#include "Common.h"
#include <memory>
#include <string>

#ifndef TSTRING
#ifdef UNICODE
#define TSTRING std::wstring
#else
#define TSTRING std::string
#endif
#endif

#ifndef TSTRICMP
#ifdef UNICODE
#define TSTRICMP wcsicmp
#else
#define TSTRICMP stricmp
#endif
#endif

#ifndef TSTRCMP
#ifdef UNICODE
#define TSTRCMP wcscmp
#else
#define TSTRCMP strcmp
#endif
#endif

#ifndef GetStringSize
#ifdef UNICODE
#define GetStringSize GetStringSizeW
#else
#define GetStringSize GetStringSizeA
#endif
#endif

LIBRARY_EXPORT_API size_t GetStringSizeA(std::string string);

LIBRARY_EXPORT_API size_t GetStringSizeW(std::wstring string);

LIBRARY_EXPORT_API std::unique_ptr<std::string> GUIDToString(const GUID &guid);

#endif
