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
	extern LIBRARY_EXPORT_API const std::span<const RE2RR::Types::ItemInformation> GetItemDB();
	extern LIBRARY_EXPORT_API const std::span<const std::pair<const RE2RR::Types::Enums::FloorID, const char *>> GetFloorIDNames();
	extern LIBRARY_EXPORT_API const std::span<const std::pair<const RE2RR::Types::Enums::MapID, const char *>> GetMapIDNames();
	extern LIBRARY_EXPORT_API const std::span<const std::pair<const RE2RR::Types::Enums::MapPartsID, const char *>> GetMapPartsIDNames();

	template <typename K>
	concept AllowedLookupKeyTypes = std::same_as<K, RE2RR::Types::Enums::FloorID> ||
	                                std::same_as<K, RE2RR::Types::Enums::MapID> ||
	                                std::same_as<K, RE2RR::Types::Enums::MapPartsID>;

	template <AllowedLookupKeyTypes K>
	LIBRARY_EXPORT_API const char *GetLookupValue(const std::span<const std::pair<const K, const char *>> &map, const K &key)
	{
		if (auto it = std::ranges::find_if(map, [&key](const auto &p)
		                                   { return p.first == key; });
		    it != map.end())
			return it->second;
		else
			throw new std::out_of_range("Key not found in span pair");
	}

	template <AllowedLookupKeyTypes K>
	LIBRARY_EXPORT_API const char *GetLookupValue(const std::span<const std::pair<const K, const char *>> &map, const K &key, const char (&defaultValue)[])
	{
		if (auto it = std::ranges::find_if(map, [&key](const auto &p)
		                                   { return p.first == key; });
		    it != map.end())
			return it->second;
		else
			return defaultValue;
	}

	template <AllowedLookupKeyTypes K>
	LIBRARY_EXPORT_API const bool Contains(const std::span<const std::pair<const K, const char *>> &map, const K &key)
	{
		auto it = std::ranges::find_if(map, [&key](const auto &p)
		                               { return p.first == key; });
		return it != map.end();
	}
}

#endif
