#ifndef RE2RR_RANDOMIZER_H
#define RE2RR_RANDOMIZER_H

#include "Common.h"
#include "File.h"
#include "Logging.h"
#include "Strings.h"
#include "Types.h"
#include <algorithm>
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
	ImmediateLogger &logger;
	bool &debugSkipRandomization;
	static RE2RItem defaultItemEntry;
	static std::unordered_map<GameModeKey, std::unordered_map<GUID, RE2RItem, std::hash<GUID>, std::equal_to<GUID>>, std::hash<GameModeKey>, std::equal_to<GameModeKey>> originalItemMapping;
	static std::unordered_map<RE2RREnums::FloorID, std::string> floorIdToName;
	static std::unordered_map<RE2RREnums::MapID, std::string> mapIdToName;
	static std::unordered_map<RE2RREnums::MapPartsID, std::string> mapPartsIdToName;
	Seed seed;
	RE2RREnums::FloorID floorId;
	RE2RREnums::MapID mapId;
	RE2RREnums::MapPartsID mapPartsId;
	RE2RItem lastInteractedItem = {};
	RE2RItem lastRandomizedItem = {};
	GUID lastInteractedItemPositionGuid = {};

	// static RE2RItem &GetItemByGameModeKeyAndGUID(const GameModeKey &, GUID &);
	static const std::string &GetFloorNameById(const RE2RREnums::FloorID &);
	static const std::string &GetMapNameById(const RE2RREnums::MapID &);
	static const std::string &GetMapPartsNameById(const RE2RREnums::MapPartsID &);
	void RandomizeItem(RE2RItem &, const RE2RItem &, const RE2RItem &);
	RE2RItem GetItemByType(uint32_t);
	void SetItemByGUID(RE2RItem *, GUID *);
	void SetLast(const RE2RItem &, const RE2RItem &, const GUID &);
	/// @brief
	/// @param gen
	void HandleSoftLocks(std::mt19937 &gen);
	/// @brief Adds a key item to a random one of the item drop candidates.
	/// @param originals The original items' drop location.
	/// @param destinations The candidate item drop locations we want this item to potentially be placed.
	/// @param gen The random number generator instance.
	// void AddKeyItem(const GUID &original, std::vector<GUID> &destinations, std::mt19937 &gen);
	void AddKeyItem(std::vector<GUID> &originals, std::vector<GUID> &destinations, std::mt19937 &gen);

protected:
public:
	Randomizer(ImmediateLogger &logger, bool &debugSkipRandomization) : logger(logger), debugSkipRandomization(debugSkipRandomization)
	{
		this->seed = {};
		this->mapPartsId = RE2RREnums::MapPartsID::Invalid;
		this->mapId = RE2RREnums::MapID::Invalid;
		this->floorId = RE2RREnums::FloorID::None;

		logger.LogMessage("[RE2R-R] Randomizer::ctor(%s: %p) called.\n",
		                  NAMEOF(logger), (void *)&logger);
	}
	~Randomizer(void)
	{
	}

	void ItemPickup(RE2RItem &, const GUID &);
	bool ChangeArea(RE2RREnums::MapPartsID, RE2RREnums::MapID, RE2RREnums::FloorID);
	RE2RREnums::Difficulty GetDifficulty(void);
	RE2RREnums::Scenario GetScenario(void);

	RE2RREnums::FloorID GetFloorID(void);
	const std::string &GetFloorName(void);
	RE2RREnums::MapID GetMapID(void);
	const std::string &GetMapName(void);
	RE2RREnums::MapPartsID GetMapPartsID(void);
	const std::string &GetMapPartsName(void);
	const RE2RItem &GetLastInteractedItem(void);
	const RE2RItem &GetLastRandomizedItem(void);
	GUID &GetLastInteractedItemPositionGuid(void);
	void Randomize(const RE2RREnums::Difficulty &, const RE2RREnums::Scenario &, int_fast32_t);
	const Seed &GetSeed(void);
	void ExportCheatSheet(int_fast32_t);
};

#endif
