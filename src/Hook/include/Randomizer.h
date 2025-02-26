#ifndef RE2RR_RANDOMIZER_H
#define RE2RR_RANDOMIZER_H

#include "Common.h"
#include "Database.h"
#include "File.h"
#include "Guid.h"
#include "Logging.h"
#include "Strings.h"
#include "Types.h"
#include <algorithm>
#include <format>
#include <fstream>
#include <future>
#include <iostream>
#include <list>
#include <random>
#include <ranges>
#include <stdexcept>
#include <stdint.h>
#include <thread>
#include <unordered_map>
#include <vector>

class Randomizer
{
private:
	std::unordered_map<const RE2RR::Types::Enums::FloorID, const char *> floorNames;
	std::unordered_map<const RE2RR::Types::Enums::MapID, const char *> mapNames;
	std::unordered_map<const RE2RR::Types::Enums::MapPartsID, const char *> mapPartNames;

	RE2RR::Common::Logging::ImmediateLogger &logger;
	bool &debugSkipRandomization;
	std::unordered_map<GUID, RE2RR::Types::ItemInformation, std::hash<GUID>, std::equal_to<GUID>> originalItemInformation;
	RE2RR::Types::Seed seed;
	RE2RR::Types::Enums::FloorID floorId;
	RE2RR::Types::Enums::MapID mapId;
	RE2RR::Types::Enums::MapPartsID mapPartsId;
	RE2RR::Types::RE2RItem lastInteractedItem = {};
	RE2RR::Types::RE2RItem lastRandomizedItem = {};
	GUID lastInteractedItemPositionGuid = {};

	void RandomizeItem(RE2RR::Types::RE2RItem &, const RE2RR::Types::RE2RItem &, const RE2RR::Types::RE2RItem &);
	RE2RR::Types::RE2RItem GetItemByType(uint32_t);
	void SetItemByGUID(RE2RR::Types::RE2RItem *, GUID *);
	void SetLast(const RE2RR::Types::RE2RItem &, const RE2RR::Types::RE2RItem &, const GUID &);
	/// @brief
	/// @param gen
	void HandleSoftLocks(std::mt19937 &gen);
	/// @brief Adds a key item to a random one of the item drop candidates.
	/// @param originals The original items' drop location.
	/// @param destinations The candidate item drop locations we want this item to potentially be placed.
	/// @param gen The random number generator instance.
	void AddKeyItem(std::vector<GUID> &originals, std::vector<GUID> &destinations, std::mt19937 &gen);

protected:
public:
	Randomizer(RE2RR::Common::Logging::ImmediateLogger &logger, bool &debugSkipRandomization) : logger(logger), debugSkipRandomization(debugSkipRandomization)
	{
		auto floorIDNamesSpan = RE2RR::Database::GetFloorIDNames();
		this->floorNames = std::unordered_map<const RE2RR::Types::Enums::FloorID, const char *>(floorIDNamesSpan.begin(), floorIDNamesSpan.end());

		auto mapNamesSpan = RE2RR::Database::GetMapIDNames();
		this->mapNames = std::unordered_map<const RE2RR::Types::Enums::MapID, const char *>(mapNamesSpan.begin(), mapNamesSpan.end());

		auto mapPartNamesSpan = RE2RR::Database::GetMapPartsIDNames();
		this->mapPartNames = std::unordered_map<const RE2RR::Types::Enums::MapPartsID, const char *>(mapPartNamesSpan.begin(), mapPartNamesSpan.end());

		this->seed = {};
		this->mapPartsId = RE2RR::Types::Enums::MapPartsID::Invalid;
		this->mapId = RE2RR::Types::Enums::MapID::Invalid;
		this->floorId = RE2RR::Types::Enums::FloorID::None;

		logger.LogMessage("[RE2R-R] Randomizer::ctor(%s: %p) called.\n",
		                  NAMEOF(logger), (void *)&logger);
	}
	~Randomizer(void)
	{
	}

	void ItemPickup(RE2RR::Types::RE2RItem &, const GUID &);
	bool ChangeArea(RE2RR::Types::Enums::MapPartsID, RE2RR::Types::Enums::MapID, RE2RR::Types::Enums::FloorID);
	RE2RR::Types::Enums::Difficulty GetDifficulty(void);
	RE2RR::Types::Enums::Scenario GetScenario(void);

	RE2RR::Types::Enums::FloorID GetFloorID(void);
	const std::unique_ptr<std::string> GetFloorName(void);
	RE2RR::Types::Enums::MapID GetMapID(void);
	const std::unique_ptr<std::string> GetMapName(void);
	RE2RR::Types::Enums::MapPartsID GetMapPartsID(void);
	const std::unique_ptr<std::string> GetMapPartsName(void);
	const RE2RR::Types::RE2RItem &GetLastInteractedItem(void);
	const RE2RR::Types::RE2RItem &GetLastRandomizedItem(void);
	GUID &GetLastInteractedItemPositionGuid(void);
	void Randomize(const RE2RR::Types::Enums::Difficulty &, const RE2RR::Types::Enums::Scenario &, int_fast32_t);
	const RE2RR::Types::Seed &GetSeed(void);
	void ExportCheatSheet();
};

#endif
