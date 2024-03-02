#ifndef RE2RR_RANDOMIZER_H
#define RE2RR_RANDOMIZER_H

#include "File.h"
#include "Logging.h"
#include "Types.h"
#include <stdexcept>
#include <stdint.h>
#include <unordered_map>
#include <vector>

class Randomizer
{
private:
	ImmediateLogger *logger;
	std::vector<uint32_t> seed;
	RE2RREnums::Difficulty *difficulty;
	RE2RREnums::Scenario *scenario;
	RE2RREnums::MapPartsID mapPartsId;
	RE2RREnums::MapID mapId;
	RE2RREnums::FloorID floorId;
	RE2RItem lastInteractedItem = {};
	GUID lastInteractedItemPositionGuid = {};

	static RE2RItem &GetItemByItemMapKey(const ItemMapKey &itemMapKey);
	void RandomizeItem(RE2RItem *, RE2RItem);
	RE2RItem GetItemByType(uint32_t);
	void SetItemByGUID(RE2RItem *, GUID *);
	void SetLastInteracted(RE2RItem *, GUID *);

protected:
public:
	Randomizer(ImmediateLogger *logger, std::vector<uint32_t> seed, RE2RREnums::Difficulty *difficulty, RE2RREnums::Scenario *scenario)
	{
		this->logger = logger;
		this->seed = seed;
		this->difficulty = difficulty;
		this->scenario = scenario;
		this->mapPartsId = RE2RREnums::MapPartsID::Invalid;
		this->mapId = RE2RREnums::MapID::Invalid;
		this->floorId = RE2RREnums::FloorID::None;

		logger->LogMessage("[RE2R-R] Randomizer::ctor(%s: %p, %s: %p, %s: %s, %s: %s) called.\n",
		                   RE2RR_NAMEOF(logger), (void *)logger,
		                   RE2RR_NAMEOF(seed), (void *)&seed,
		                   RE2RR_NAMEOF(difficulty), RE2RREnums::EnumDifficultyToString(*difficulty).c_str(),
		                   RE2RR_NAMEOF(scenario), RE2RREnums::EnumScenarioToString(*scenario).c_str());
	}
	~Randomizer()
	{
		this->logger = nullptr;

		// this->seed = nullptr;
		this->seed.clear();

		this->difficulty = nullptr;

		this->scenario = nullptr;
	}

	void ItemPickup(RE2RItem *, RE2RItem *, GUID *);
	bool ChangeArea(RE2RREnums::MapPartsID, RE2RREnums::MapID, RE2RREnums::FloorID);
	RE2RREnums::Difficulty GetDifficulty();
	RE2RREnums::Scenario GetScenario();
	RE2RREnums::MapPartsID GetMapPartsID();
	RE2RREnums::MapID GetMapID();
	RE2RREnums::FloorID GetFloorID();
	RE2RItem *GetLastInteractedItem();
	GUID *GetLastInteractedItemPositionGuid();
};

std::string GUIDToString(GUID *);

#endif
