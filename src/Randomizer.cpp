#include "Randomizer.h"

void Randomizer::ItemPickup(RE2RItem *itemToReplace, RE2RItem *currentItem, GUID *itemPositionGuid)
{
	if (logger == nullptr ||
	    itemToReplace == nullptr || currentItem == nullptr || itemPositionGuid == nullptr)
		return;

	logger->LogMessage("[RE2R-R] Randomizer::ItemPickup(%s: %p, *%s: %s, *%s: %s) called.\n",
	                   NAMEOF(itemToReplace), itemToReplace,
	                   NAMEOF(currentItem), currentItem->ToString().c_str(),
	                   NAMEOF(itemPositionGuid), GUIDToString(itemPositionGuid).c_str());
	logger->LogMessage("[RE2R-R] GetItemByGameModeKeyAndGUID() returned: %s.\n",
	                   GetItemByGameModeKeyAndGUID(GameModeKey{.Scenario = this->scenario, .Difficulty = this->difficulty}, *itemPositionGuid).ToString().c_str());
	SetLastInteracted(currentItem, itemPositionGuid);
}

void Randomizer::SetLastInteracted(RE2RItem *item, GUID *itemPositionGuid)
{
	this->lastInteractedItem = *item;
	this->lastInteractedItemPositionGuid = *itemPositionGuid;
}

RE2RItem *Randomizer::GetLastInteractedItem()
{
	return &this->lastInteractedItem;
}

GUID *Randomizer::GetLastInteractedItemPositionGuid()
{
	return &this->lastInteractedItemPositionGuid;
}

bool Randomizer::ChangeArea(RE2RREnums::MapPartsID mapPartsId, RE2RREnums::MapID mapId, RE2RREnums::FloorID floorId)
{
	bool returnValue = this->mapPartsId != mapPartsId || this->mapId != mapId || this->floorId != floorId;
	if (returnValue)
	{
		this->mapPartsId = mapPartsId;
		this->mapId = mapId;
		this->floorId = floorId;
	}
	return returnValue;
}

RE2RREnums::Difficulty Randomizer::GetDifficulty()
{
	return difficulty;
}

RE2RREnums::Scenario Randomizer::GetScenario()
{
	return scenario;
}

RE2RREnums::MapPartsID Randomizer::GetMapPartsID()
{
	return mapPartsId;
}

RE2RREnums::MapID Randomizer::GetMapID()
{
	return mapId;
}

RE2RREnums::FloorID Randomizer::GetFloorID()
{
	return floorId;
}

void Randomizer::RandomizeItem(RE2RItem *currentItem, RE2RItem newItem)
{
	if (currentItem == nullptr)
		return;

	logger->LogMessage("[RE2R-R] Randomizer::RandomizeItem().\n\tOld: %s.\n\tNew: %s.\n\t%s -> %s\n", currentItem->ToString().c_str(), newItem.ToString().c_str(), RE2RREnums::EnumItemTypeToString(currentItem->ItemId).c_str(), RE2RREnums::EnumItemTypeToString(newItem.ItemId).c_str());
	*currentItem = newItem;
}

std::string GUIDToString(GUID *guid)
{
	if (guid == nullptr)
		return {};

	char guid_string[(sizeof(GUID) * 2) + 4 + 1]; // (16 bytes (4+2+2+8) * 2 for character representation) + 4 hyphens + 1 null terminator = 37 bytes/chars.

	snprintf(
	    guid_string, sizeof(guid_string),
	    "%08lX-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X",
	    guid->Data1,
	    guid->Data2,
	    guid->Data3,
	    guid->Data4[0], guid->Data4[1],
	    guid->Data4[2], guid->Data4[3], guid->Data4[4], guid->Data4[5], guid->Data4[6], guid->Data4[7]);
	return std::string(guid_string);
}

void Randomizer::GenerateSeed(RE2RREnums::Difficulty *difficulty, RE2RREnums::Scenario *scenario)
{
	logger->LogMessage("[RE2R-R] Randomizer::GenerateSeed(%s: %s, %s: %s) called.",
	                   NAMEOF(difficulty), RE2RREnums::EnumDifficultyToString(*difficulty).c_str(),
	                   NAMEOF(scenario), RE2RREnums::EnumScenarioToString(*scenario).c_str());

	this->difficulty = *difficulty;
	this->scenario = *scenario;

	auto SeedGenerator = [this](unsigned int threadNumber) -> std::vector<uint32_t>
	{
		logger->LogMessage("[RE2R-R] SeedGenerator(%s: %d) called.",
		                   NAMEOF(threadNumber), threadNumber);

		return {};
	};

	std::vector<std::future<std::vector<uint32_t>>> potentialSeeds;
	unsigned int threadCount = std::thread::hardware_concurrency();
	for (unsigned int threadNumber = 0; threadNumber < threadCount; ++threadNumber)
	{
		potentialSeeds.push_back(std::async(SeedGenerator, threadNumber));
	}

	// Check async status...
	//
}

std::vector<uint32_t> &Randomizer::GetSeed(void)
{
	logger->LogMessage("[RE2R-R] Randomizer::GetSeed() called.");
	return this->seed;
}
