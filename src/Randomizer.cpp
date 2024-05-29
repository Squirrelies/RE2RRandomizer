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
	SetLast(currentItem, &this->seed.seedData[*itemPositionGuid], itemPositionGuid);
	logger->LogMessage("[RE2R-R] originalItemMapping returned: %s.\n",
	                   this->originalItemMapping[this->seed.gameMode][*itemPositionGuid].ToString().c_str());
	logger->LogMessage("[RE2R-R] seedData returned: %s.\n",
	                   this->seed.seedData[*itemPositionGuid].ToString().c_str());
	RandomizeItem(itemToReplace, this->seed.seedData[*itemPositionGuid]);
}

void Randomizer::SetLast(RE2RItem *item, RE2RItem *randomizedItem, GUID *itemPositionGuid)
{
	this->lastInteractedItem = *item;
	this->lastRandomizedItem = *randomizedItem;
	this->lastInteractedItemPositionGuid = *itemPositionGuid;
}

RE2RItem *Randomizer::GetLastInteractedItem()
{
	return &this->lastInteractedItem;
}

RE2RItem *Randomizer::GetLastRandomizedItem()
{
	return &this->lastRandomizedItem;
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
	return seed.gameMode.Difficulty;
}

RE2RREnums::Scenario Randomizer::GetScenario()
{
	return seed.gameMode.Scenario;
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

void Randomizer::Randomize(RE2RREnums::Difficulty *difficulty, RE2RREnums::Scenario *scenario, int_fast32_t initialSeed)
{
	logger->LogMessage("[RE2R-R] Randomizer::Randomize(%s: %s, %s: %s, %s: %d) called.\n",
	                   NAMEOF(difficulty), RE2RREnums::EnumDifficultyToString(*difficulty).c_str(),
	                   NAMEOF(scenario), RE2RREnums::EnumScenarioToString(*scenario).c_str(),
	                   NAMEOF(initialSeed), initialSeed);

	seed = Seed{.gameMode = GameModeKey{.Scenario = *scenario, .Difficulty = *difficulty}, .seedData = {}};

	std::vector<RE2RItem> values;
	for (const auto &[_, value] : originalItemMapping[seed.gameMode])
	{
		values.push_back(value);
	}

	std::mt19937 gen(initialSeed);
	std::shuffle(values.begin(), values.end(), gen);

	auto value = values.begin();
	for (const auto &[key, _] : originalItemMapping[seed.gameMode])
	{
		seed.seedData[key] = *value++;
	}
}

Seed &Randomizer::GetSeed(void)
{
	logger->LogMessage("[RE2R-R] Randomizer::GetSeed() called.\n");
	return this->seed;
}
