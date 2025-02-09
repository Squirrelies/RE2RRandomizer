#ifndef RE2RR_DATABASE_H
#define RE2RR_DATABASE_H

#include "Common.h"
#include "Types.h"
#include <ranges>
#include <unordered_map>
#include <vector>

extern std::unordered_map<RE2RREnums::FloorID, std::string> floorNames;
extern std::unordered_map<RE2RREnums::MapID, std::string> mapNames;
extern std::unordered_map<RE2RREnums::MapPartsID, std::string> mapPartNames;
extern std::vector<ItemInformation> itemDB;

#endif
