#ifndef UNICODE
#define UNICODE
#endif

#ifndef _UNICODE
#define _UNICODE
#endif

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <minwindef.h>

#ifndef LIBRARY_EXPORT_API
// Windows Static or non-Windows
#if defined(BUILD_STATIC_LIBS) || !defined(WIN32) || !defined(WIN64)
#define LIBRARY_EXPORT_API
// Windows Shared (Build/Export)
#elif defined(BUILD_SHARED_LIBS)
#define LIBRARY_EXPORT_API __declspec(dllexport)
// Windows Shared (Usage/Import)
#else
#define LIBRARY_EXPORT_API __declspec(dllimport)
#endif
#endif

#ifndef CONCATENATION
#define CONCATENATION(left, right) left##right
#endif

#ifndef DEFINE_CONCATENATION
#define DEFINE_CONCATENATION(left, right) CONCATENATION(left, right)
#endif

#ifndef NAMEOF
#define NAMEOF(name) #name
#endif

#ifdef __GNUC__
#define UNUSED(x) UNUSED_##x __attribute__((__unused__))
#else
#define UNUSED(x) UNUSED_##x
#endif

#ifdef __GNUC__
#define UNUSED_FUNCTION(x) __attribute__((__unused__)) UNUSED_##x
#else
#define UNUSED_FUNCTION(x) UNUSED_##x
#endif

// Major version number. This is defined at compile time so this is just a placeholder.
#ifndef RE2RR_VERSION_MAJOR
#define RE2RR_VERSION_MAJOR 0
#endif

// Minor version number. This is defined at compile time so this is just a placeholder.
#ifndef RE2RR_VERSION_MINOR
#define RE2RR_VERSION_MINOR 1
#endif

// Patch version number. This is defined at compile time so this is just a placeholder.
#ifndef RE2RR_VERSION_PATCH
#define RE2RR_VERSION_PATCH 0
#endif

// Revision version number. This is defined at compile time so this is just a placeholder.
#ifndef RE2RR_VERSION_REV
#define RE2RR_VERSION_REV 0
#endif
