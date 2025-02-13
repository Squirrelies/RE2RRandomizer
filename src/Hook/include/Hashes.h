#ifndef RE2RR_HASHES_H
#define RE2RR_HASHES_H

#include "Common.h"
#include "File.h"
#include "Logging.h"
#include "Types.h"
#include <stdint.h>
#include <vector>

namespace RE2RR::Hook::Hashes
{
	bool DetectVersion(const char *filePath, RE2RR::Types::Enums::RE2RGameVersion &gameVersion, RE2RR::Types::Enums::RE2RGameEdition &gameEdition, RE2RR::Types::Enums::RE2RGameDXVersion &gameDXVersion, RE2RR::Common::Logging::ImmediateLogger &logger);
}

#endif