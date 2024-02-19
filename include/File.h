#ifndef RE2RR_FILE_H
#define RE2RR_FILE_H

#include <stdio.h>

#define RE2RRFILEAPI __declspec(dllexport)

#ifdef __cplusplus
extern "C"
{
#endif

	/// @brief Checks if a file exists.
	/// @param filePath The path to the file to check.
	/// @return True if the file exists, false if it does not.
	RE2RRFILEAPI bool FileExists(const char *filePath);

#ifdef __cplusplus
}
#endif

#endif
