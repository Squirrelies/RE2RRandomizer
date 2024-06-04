#ifndef RE2RR_RANDOMIZER_H
#define RE2RR_RANDOMIZER_H

#include "Common.h"
#include "File.h"
#include "Logging.h"
#include "Types.h"
#include <algorithm>
#include <future>
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
	ImmediateLogger *logger;
	static RE2RItem defaultItemEntry;
	static std::unordered_map<GameModeKey, std::unordered_map<GUID, RE2RItem, std::hash<GUID>, std::equal_to<GUID>>, std::hash<GameModeKey>, std::equal_to<GameModeKey>> originalItemMapping;
	Seed seed;
	RE2RREnums::MapPartsID mapPartsId;
	RE2RREnums::MapID mapId;
	RE2RREnums::FloorID floorId;
	RE2RItem lastInteractedItem = {};
	RE2RItem lastRandomizedItem = {};
	GUID lastInteractedItemPositionGuid = {};

	static RE2RItem &GetItemByGameModeKeyAndGUID(const GameModeKey &, GUID &);
	void RandomizeItem(RE2RItem *, const RE2RItem &, const RE2RItem &);
	RE2RItem GetItemByType(uint32_t);
	void SetItemByGUID(RE2RItem *, GUID *);
	void SetLast(const RE2RItem &, const RE2RItem &, GUID &);
	void HandleSoftLocks(std::mt19937 &);
	/// @brief Adds a key item to a random one of the item drop candidates.
	/// @param original The original item's drop location.
	/// @param destinations The candidate item drop locations we want this item to potentially be placed.
	/// @param gen The random number generator instance.
	void AddKeyItem(GUID &original, std::vector<GUID> &destinations, std::mt19937 &gen);

protected:
public:
	Randomizer(ImmediateLogger *logger)
	{
		this->logger = logger;
		this->seed = {};
		this->mapPartsId = RE2RREnums::MapPartsID::Invalid;
		this->mapId = RE2RREnums::MapID::Invalid;
		this->floorId = RE2RREnums::FloorID::None;

		logger->LogMessage("[RE2R-R] Randomizer::ctor(%s: %p) called.\n",
		                   NAMEOF(logger), (void *)logger);
	}
	~Randomizer(void)
	{
		this->logger = nullptr;
	}

	void ItemPickup(RE2RItem *, const RE2RItem &, GUID &);
	bool ChangeArea(RE2RREnums::MapPartsID, RE2RREnums::MapID, RE2RREnums::FloorID);
	RE2RREnums::Difficulty GetDifficulty(void);
	RE2RREnums::Scenario GetScenario(void);
	RE2RREnums::MapPartsID GetMapPartsID(void);
	RE2RREnums::MapID GetMapID(void);
	RE2RREnums::FloorID GetFloorID(void);
	const RE2RItem &GetLastInteractedItem(void);
	const RE2RItem &GetLastRandomizedItem(void);
	GUID &GetLastInteractedItemPositionGuid(void);
	void Randomize(const RE2RREnums::Difficulty &, const RE2RREnums::Scenario &, int_fast32_t);
	const Seed &GetSeed(void);
};

std::string GUIDToString(GUID &);

#endif
