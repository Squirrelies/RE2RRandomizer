#ifndef RE2RR_STRINGS_H
#define RE2RR_STRINGS_H

#ifndef UNICODE
#define UNICODE
#endif

#ifndef _UNICODE
#define _UNICODE
#endif

#ifndef WIN32_LEAD_AND_MEAN
#define WIN32_LEAD_AND_MEAN
#endif

#include <string>

#define RE2RRSTRINGSAPI __declspec(dllexport)

#ifdef __cplusplus
extern "C"
{
#endif

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

	RE2RRSTRINGSAPI size_t GetStringSizeA(std::string string);

	RE2RRSTRINGSAPI size_t GetStringSizeW(std::wstring string);

#ifdef __cplusplus
}
#endif

#endif
