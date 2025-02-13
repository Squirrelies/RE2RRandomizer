#ifndef RE2RR_DATABASE_H
#define RE2RR_DATABASE_H

#include "Common.h"
#include "Guid.h"
#include "Types.h"
#include <ranges>
#include <unordered_map>
#include <vector>

namespace RE2RR::Database
{
	extern std::unordered_map<RE2RR::Types::Enums::FloorID, std::string> floorNames;
	extern std::unordered_map<RE2RR::Types::Enums::MapID, std::string> mapNames;
	extern std::unordered_map<RE2RR::Types::Enums::MapPartsID, std::string> mapPartNames;
	extern std::vector<RE2RR::Types::ItemInformation> itemDB;
}

#endif
