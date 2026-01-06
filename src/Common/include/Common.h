#ifndef RE2RR_COMMON_H
#define RE2RR_COMMON_H

#include <format>
#include <minwindef.h>
#include <string_view>

#ifndef UNICODE
#define UNICODE
#endif

#ifndef _UNICODE
#define _UNICODE
#endif

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#ifndef LIBRARY_EXPORT_API
#if defined(_WIN32) || defined(_WIN64)
#define LIBRARY_EXPORT_API __declspec(dllexport)
#else
#define LIBRARY_EXPORT_API
#endif
#endif

#ifdef _MSC_VER
#ifndef PACKED_STRUCT
#define PACKED_STRUCT(name) __pragma(pack(push, 1)) struct name
#endif
#ifndef END_PACKED_STRUCT
#define END_PACKED_STRUCT __pragma(pack(pop))
#endif
#else
#ifndef PACKED_STRUCT
#define PACKED_STRUCT(name) struct __attribute__((packed)) name
#endif
#ifndef END_PACKED_STRUCT
#define END_PACKED_STRUCT
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

#if defined(__GNUC__) || defined(__clang__)
#define UNUSED(x) UNUSED_##x __attribute__((__unused__))
#else
#define UNUSED(x) UNUSED_##x
#endif

#if defined(__GNUC__) || defined(__clang__)
#define UNUSED_FUNCTION(x) __attribute__((__unused__)) UNUSED_##x
#else
#define UNUSED_FUNCTION(x) UNUSED_##x
#endif

namespace RE2RR::Common
{
#ifdef DEBUG
	constinit const bool IsDebug = true;
#else
	constinit const bool IsDebug = false;
#endif

	extern std::string lastExceptionMessage;
	LIBRARY_EXPORT_API std::string GetLastExceptionMessage();

	namespace Version
	{
// Major version number. This is defined at compile time so this is just a placeholder.
#ifndef RE2RR_VERSION_MAJOR
#define RE2RR_VERSION_MAJOR 0
#endif
		constinit const uint8_t Major = RE2RR_VERSION_MAJOR;

// Minor version number. This is defined at compile time so this is just a placeholder.
#ifndef RE2RR_VERSION_MINOR
#define RE2RR_VERSION_MINOR 1
#endif
		constinit const uint8_t Minor = RE2RR_VERSION_MINOR;

// Patch version number. This is defined at compile time so this is just a placeholder.
#ifndef RE2RR_VERSION_PATCH
#define RE2RR_VERSION_PATCH 0
#endif
		constinit const uint8_t Patch = RE2RR_VERSION_PATCH;

// Build number. This is defined at compile time so this is just a placeholder.
#ifndef RE2RR_VERSION_BUILD
#define RE2RR_VERSION_BUILD 1
#endif
		constinit const uint8_t Build = RE2RR_VERSION_BUILD;

// Pre-release tag. This is defined at compile time so this is just a placeholder.
#ifndef RE2RR_VERSION_PRERELEASE_TAG
#define RE2RR_VERSION_PRERELEASE_TAG ""
#endif
		constinit const std::string_view PreReleaseTag = RE2RR_VERSION_PRERELEASE_TAG;

// Build SHA hash. This is defined at compile time so this is just a placeholder.
#ifndef RE2RR_VERSION_BUILD_HASH
#define RE2RR_VERSION_BUILD_HASH ""
#endif
		constinit const std::string_view BuildHash = RE2RR_VERSION_BUILD_HASH;

// Semantic Versioning string. This is defined at compile time so this is just a placeholder.
#ifndef RE2RR_VERSION_SEMVER
#define RE2RR_VERSION_SEMVER "0.1.0+1"
#endif
		constinit const std::string_view SemVer = RE2RR_VERSION_SEMVER;
	}
}

#endif
