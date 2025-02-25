#ifndef RE2RR_DATABASE_H
#define RE2RR_DATABASE_H

#include "Common.h"
#include "Guid.h"
#include "Types.h"
#include <array>
#include <ranges>
#include <span>
#include <unordered_map>

namespace RE2RR::Database
{
	extern const std::unordered_map<RE2RR::Types::Enums::FloorID, std::string> floorNames;
	extern const std::unordered_map<RE2RR::Types::Enums::MapID, std::string> mapNames;
	extern const std::unordered_map<RE2RR::Types::Enums::MapPartsID, std::string> mapPartNames;

	extern const RE2RR::Types::ItemInformation itemDB[];
	extern const std::span<const RE2RR::Types::ItemInformation> GetItemDB();

	template <typename K>
	concept AllowedLookupKeyTypes = std::same_as<K, RE2RR::Types::Enums::FloorID> ||
	                                std::same_as<K, RE2RR::Types::Enums::MapID> ||
	                                std::same_as<K, RE2RR::Types::Enums::MapPartsID>;

	template <AllowedLookupKeyTypes K>
	LIBRARY_EXPORT_API std::string GetLookupValue(const std::unordered_map<K, std::string> &map, const K &key, const std::string &defaultValue)
	{
		if (auto search = map.find(key); search != map.end())
			return search->second;
		else
			return defaultValue;
	}
}

#endif
