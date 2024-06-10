#ifndef RE2RR_HASHES_H
#define RE2RR_HASHES_H

#include "Common.h"
#include "File.h"
#include "Logging.h"
#include "Types.h"
#include <stdint.h>
#include <vector>

namespace RE2RRHashes
{
	/// @brief Detects the game version using a SHA256 checksum hash.
	/// @param filePath The path to the game executable.
	/// @param logger The ImmediateLogger instance to log messages to.
	/// @return A enumeration value representing the detected version of the game.
	RE2RREnums::RE2RGameVersion DetectVersion(const char *filePath, ImmediateLogger &logger);
}

#endif