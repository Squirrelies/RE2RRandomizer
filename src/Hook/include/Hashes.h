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
	bool DetectVersion(const char *filePath, RE2RREnums::RE2RGameVersion &gameVersion, RE2RREnums::RE2RGameEdition &gameEdition, RE2RREnums::RE2RGameDXVersion &gameDXVersion, ImmediateLogger &logger);
}

#endif