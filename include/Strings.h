#ifndef STRINGS_H
#define STRINGS_H

#include <string>

#define STRINGSAPI __declspec(dllexport)

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

	STRINGSAPI size_t GetStringSizeA(std::string string)
	{
		return (string.length() * sizeof(char)) + sizeof(char);
	}

	STRINGSAPI size_t GetStringSizeW(std::wstring string)
	{
		return (string.length() * sizeof(wchar_t)) + sizeof(wchar_t);
	}

#ifdef __cplusplus
}
#endif

#endif
