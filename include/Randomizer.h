#ifndef RE2RR_RANDOMIZER_H
#define RE2RR_RANDOMIZER_H

#include "Common.h"
#include "File.h"
#include "Logging.h"
#include "Types.h"
#include <future>
#include <list>
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
	std::vector<uint32_t> seed;
	RE2RREnums::Difficulty difficulty;
	RE2RREnums::Scenario scenario;
	RE2RREnums::MapPartsID mapPartsId;
	RE2RREnums::MapID mapId;
	RE2RREnums::FloorID floorId;
	RE2RItem lastInteractedItem = {};
	GUID lastInteractedItemPositionGuid = {};

	static RE2RItem &GetItemByGameModeKeyAndGUID(const GameModeKey &, const GUID &);
	void RandomizeItem(RE2RItem *, RE2RItem);
	RE2RItem GetItemByType(uint32_t);
	void SetItemByGUID(RE2RItem *, GUID *);
	void SetLastInteracted(RE2RItem *, GUID *);

protected:
public:
	Randomizer(ImmediateLogger *logger)
	{
		this->logger = logger;
		this->seed = {};
		this->difficulty = RE2RREnums::Difficulty::EASY;
		this->scenario = RE2RREnums::Scenario::INVALID;
		this->mapPartsId = RE2RREnums::MapPartsID::Invalid;
		this->mapId = RE2RREnums::MapID::Invalid;
		this->floorId = RE2RREnums::FloorID::None;

		logger->LogMessage("[RE2R-R] Randomizer::ctor(%s: %p) called.\n",
		                   NAMEOF(logger), (void *)logger);
	}
	~Randomizer(void)
	{
		this->logger = nullptr;
		this->seed.clear();
	}

	void ItemPickup(RE2RItem *, RE2RItem *, GUID *);
	bool ChangeArea(RE2RREnums::MapPartsID, RE2RREnums::MapID, RE2RREnums::FloorID);
	RE2RREnums::Difficulty GetDifficulty(void);
	RE2RREnums::Scenario GetScenario(void);
	RE2RREnums::MapPartsID GetMapPartsID(void);
	RE2RREnums::MapID GetMapID(void);
	RE2RREnums::FloorID GetFloorID(void);
	RE2RItem *GetLastInteractedItem(void);
	GUID *GetLastInteractedItemPositionGuid(void);
	void GenerateSeed(RE2RREnums::Difficulty *difficulty, RE2RREnums::Scenario *scenario);
	std::vector<uint32_t> &GetSeed(void);
};

std::string GUIDToString(GUID *);

#endif
