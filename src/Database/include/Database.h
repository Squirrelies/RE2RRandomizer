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
	extern const std::span<const RE2RR::Types::ItemInformation> GetItemDB();
	extern const std::span<const std::pair<const RE2RR::Types::Enums::FloorID, const char *>> GetFloorIDNames();
	extern const std::span<const std::pair<const RE2RR::Types::Enums::MapID, const char *>> GetMapIDNames();
	extern const std::span<const std::pair<const RE2RR::Types::Enums::MapPartsID, const char *>> GetMapPartsIDNames();

	template <typename K>
	concept AllowedLookupKeyTypes = std::same_as<K, RE2RR::Types::Enums::FloorID> ||
	                                std::same_as<K, RE2RR::Types::Enums::MapID> ||
	                                std::same_as<K, RE2RR::Types::Enums::MapPartsID>;

	template <AllowedLookupKeyTypes K>
	LIBRARY_EXPORT_API const char *GetLookupValue(const std::unordered_map<const K, const char *> &map, const K &key, const char (&defaultValue)[])
	{
		if (auto search = map.find(key); search != map.end())
			return search->second;
		else
			return defaultValue;
	}
}

#endif
