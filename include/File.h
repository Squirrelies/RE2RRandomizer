#ifndef RE2RR_FILE_H
#define RE2RR_FILE_H

#include "Common.h"
#include "Types.h"
#include "sha-256.h"
#include <memory>
#include <stdio.h>
#include <vector>

namespace RE2RRFile
{
	/// @brief Checks if a file exists.
	/// @param filePath The path to the file to check.
	/// @return True if the file exists, false if it does not.
	LIBRARY_EXPORT_API bool FileExists(const char *filePath);

	/// @brief Gets the file size for the given file.
	/// @param filePath The file to retrieve the size for.
	/// @return The file size as an int64_t. Returns -1LL on failure to open or seek.
	LIBRARY_EXPORT_API size_t GetFileSizeT(const char *filePath);

	/// @brief Calculates the SHA256 hash for a given file.
	/// @param filePath The file to calculate the SHA256 hash for.
	/// @return The SHA256 hash as an uint8_t array. This array will always be 32-bytes or 256-bits.
	LIBRARY_EXPORT_API std::unique_ptr<uint8_t[]> GetFileHashSHA256(const char *filePath);

	LIBRARY_EXPORT_API std::vector<uint8_t> HashSHA256ToVector(const uint8_t *hash);

	LIBRARY_EXPORT_API std::unique_ptr<std::string> VectorToHexString(std::vector<uint8_t> &vector);
};

#endif
