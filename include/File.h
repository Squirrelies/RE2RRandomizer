#ifndef RE2RR_FILE_H
#define RE2RR_FILE_H

#include "Types.h"
#include "sha-256.h"
#include <memory>
#include <stdio.h>

#define RE2RRFILEAPI __declspec(dllexport)

#ifdef __cplusplus
extern "C"
{
#endif

	namespace RE2RRFile
	{
		/// @brief Checks if a file exists.
		/// @param filePath The path to the file to check.
		/// @return True if the file exists, false if it does not.
		RE2RRFILEAPI bool FileExists(const char *filePath);

		/// @brief Gets the file size for the given file.
		/// @param filePath The file to retrieve the size for.
		/// @return The file size as an int64_t. Returns -1LL on failure to open or seek.
		RE2RRFILEAPI int64_t GetFileSize(const char *filePath);

		/// @brief Calculates the SHA256 hash for a given file.
		/// @param filePath The file to calculate the SHA256 hash for.
		/// @return The SHA256 hash as an uint8_t array. This array will always be 32-bytes or 256-bits.
		RE2RRFILEAPI uint8_t *GetFileHashSHA256(const char *filePath);
	};

#ifdef __cplusplus
}
#endif

#endif
