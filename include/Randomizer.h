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
	app_ropeway_gamemastering_InventoryManager_PrimitiveItem lastInteractedItem = {};
	GUID lastInteractedItemPositionGuid = {};
	FILE *itemLogFile;
	ImmediateLogger *itemLog;

	static app_ropeway_gamemastering_InventoryManager_PrimitiveItem GetItemByPositionGuid(GUID *);
	void RandomizeItem(app_ropeway_gamemastering_InventoryManager_PrimitiveItem *, app_ropeway_gamemastering_InventoryManager_PrimitiveItem);
	app_ropeway_gamemastering_InventoryManager_PrimitiveItem GetItemByType(uint32_t);
	void SetItemByGUID(app_ropeway_gamemastering_InventoryManager_PrimitiveItem *, GUID *);
	void SetLastInteracted(app_ropeway_gamemastering_InventoryManager_PrimitiveItem *, GUID *);

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

		const char *logFileNameFormat = "RE2RRItemLog_%s%s.csv";
		int logFileNameSize = snprintf(nullptr, 0, logFileNameFormat, RE2RREnums::EnumScenarioToString(*scenario).c_str(), RE2RREnums::EnumDifficultyToString(*difficulty).c_str()) + sizeof(char);
		char *logFileName = (char *)malloc(logFileNameSize);
		snprintf(logFileName, logFileNameSize, logFileNameFormat, RE2RREnums::EnumScenarioToString(*scenario).c_str(), RE2RREnums::EnumDifficultyToString(*difficulty).c_str());
		bool itemLogFileExists = RE2RRFile::FileExists(logFileName);
		this->itemLogFile = fopen(logFileName, "a");
		this->itemLog = new ImmediateLogger(this->itemLogFile, this->logger->GetUILog());
		if (!itemLogFileExists)
			this->itemLog->LogMessage("\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\"\n",
			                          "ItemId (Name)", "ItemId (uint32_t)", "ItemId (hex)", "WeaponId (Name)", "WeaponId (uint32_t)", "WeaponId (hex)", "WeaponParts (uint32_t)", "WeaponParts (hex)", "BulletId (uint32_t)", "BulletId (hex)", "Count (uint32_t)", "Count (hex)", "ItemPositionGuid (Guid)", "MapPartsId", "MapId", "FloorId");
		free(logFileName);

		logger->LogMessage("[RE2R-R] Randomizer::ctor(%s: %p, %s: %p, %s: %s, %s: %s) called.\n",
		                   RE2RR_NAMEOF(logger), (void *)logger,
		                   RE2RR_NAMEOF(seed), (void *)&seed,
		                   RE2RR_NAMEOF(difficulty), RE2RREnums::EnumDifficultyToString(*difficulty).c_str(),
		                   RE2RR_NAMEOF(scenario), RE2RREnums::EnumScenarioToString(*scenario).c_str());
	}
	~Randomizer()
	{
		delete this->itemLog;
		this->itemLog = nullptr;

		fclose(this->itemLogFile);
		this->itemLogFile = nullptr;

		this->logger = nullptr;

		// this->seed = nullptr;
		this->seed.clear();

		this->difficulty = nullptr;

		this->scenario = nullptr;
	}

	void ItemPickup(app_ropeway_gamemastering_InventoryManager_PrimitiveItem *, app_ropeway_gamemastering_InventoryManager_PrimitiveItem *, GUID *);
	bool ChangeArea(RE2RREnums::MapPartsID, RE2RREnums::MapID, RE2RREnums::FloorID);
	RE2RREnums::Difficulty GetDifficulty();
	RE2RREnums::Scenario GetScenario();
	RE2RREnums::MapPartsID GetMapPartsID();
	RE2RREnums::MapID GetMapID();
	RE2RREnums::FloorID GetFloorID();
	app_ropeway_gamemastering_InventoryManager_PrimitiveItem *GetLastInteractedItem();
	GUID *GetLastInteractedItemPositionGuid();
};

std::string GUIDToString(GUID *);

#endif
