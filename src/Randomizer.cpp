#include "Randomizer.h"

void Randomizer::ItemPickup(RE2RItem *itemToReplace, const RE2RItem &currentItem, const GUID &itemPositionGuid)
{
	if (logger == nullptr || itemToReplace == nullptr)
		return;

	logger->LogMessage("[RE2R-R] Randomizer::ItemPickup(%s: %p, *%s: %s, *%s: %s) called.\n",
	                   NAMEOF(itemToReplace), itemToReplace,
	                   NAMEOF(currentItem), currentItem.ToString().c_str(),
	                   NAMEOF(itemPositionGuid), GUIDToString(itemPositionGuid).c_str());
	logger->LogMessage("[RE2R-R] originalItemMapping returned: %s.\n",
	                   this->originalItemMapping[this->seed.gameMode][itemPositionGuid].ToString().c_str());
	logger->LogMessage("[RE2R-R] seedData returned: %s.\n",
	                   this->seed.seedData[itemPositionGuid].ToString().c_str());
	SetLast(this->originalItemMapping[this->seed.gameMode][itemPositionGuid], this->seed.seedData[itemPositionGuid], itemPositionGuid);
	RandomizeItem(itemToReplace, this->seed.seedData[itemPositionGuid]);
}

void Randomizer::SetLast(const RE2RItem &item, const RE2RItem &randomizedItem, const GUID &itemPositionGuid)
{
	this->lastInteractedItem = item;
	this->lastRandomizedItem = randomizedItem;
	this->lastInteractedItemPositionGuid = itemPositionGuid;
}

const RE2RItem &Randomizer::GetLastInteractedItem()
{
	return this->lastInteractedItem;
}

const RE2RItem &Randomizer::GetLastRandomizedItem()
{
	return this->lastRandomizedItem;
}

const GUID &Randomizer::GetLastInteractedItemPositionGuid()
{
	return this->lastInteractedItemPositionGuid;
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

void Randomizer::RandomizeItem(RE2RItem *currentItem, const RE2RItem &newItem)
{
	logger->LogMessage("[RE2R-R] Randomizer::RandomizeItem().\n\tOld: %s.\n\tNew: %s.\n\t%s -> %s\n", currentItem->ToString().c_str(), newItem.ToString().c_str(), RE2RREnums::EnumItemTypeToString(currentItem->ItemId).c_str(), RE2RREnums::EnumItemTypeToString(newItem.ItemId).c_str());
	*currentItem = newItem;
}

std::string GUIDToString(const GUID &guid)
{
	char guid_string[(sizeof(GUID) * 2) + 4 + 1]; // (16 bytes (4+2+2+8) * 2 for character representation) + 4 hyphens + 1 null terminator = 37 bytes/chars.

	snprintf(
	    guid_string, sizeof(guid_string),
	    "%08lX-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X",
	    guid.Data1,
	    guid.Data2,
	    guid.Data3,
	    guid.Data4[0], guid.Data4[1],
	    guid.Data4[2], guid.Data4[3], guid.Data4[4], guid.Data4[5], guid.Data4[6], guid.Data4[7]);
	return std::string(guid_string);
}

void Randomizer::Randomize(const RE2RREnums::Difficulty &difficulty, const RE2RREnums::Scenario &scenario, int_fast32_t initialSeed)
{
	logger->LogMessage("[RE2R-R] Randomizer::Randomize(%s: %s, %s: %s, %s: %d) called.\n",
	                   NAMEOF(difficulty), RE2RREnums::EnumDifficultyToString(difficulty).c_str(),
	                   NAMEOF(scenario), RE2RREnums::EnumScenarioToString(scenario).c_str(),
	                   NAMEOF(initialSeed), initialSeed);

	seed = Seed{.gameMode = GameModeKey{.Scenario = scenario, .Difficulty = difficulty}, .seedData = {}};
	std::mt19937 gen(initialSeed);

	HandleSoftLocks(difficulty, scenario, gen);

	std::vector<RE2RItem> values;
	for (const auto &[key, value] : originalItemMapping[seed.gameMode])
	{
		if (!seed.seedData.contains(key))
			values.push_back(value);
	}

	std::shuffle(values.begin(), values.end(), gen);

	auto value = values.begin();
	for (const auto &[key, _] : originalItemMapping[seed.gameMode])
	{
		if (!seed.seedData.contains(key))
			seed.seedData.insert(std::make_pair(key, *value++));
	}
}

/// @brief
/// @param difficulty The difficulty of the playthrough we're randomizing. This parameter is unused at this time.
/// @param scenario The scenario of the playthrough we're randomizing.
/// @param initialSeed The initial seed to feed to the randomizer.
void Randomizer::HandleSoftLocks(const RE2RREnums::Difficulty &difficulty, const RE2RREnums::Scenario &scenario, std::mt19937 &gen)
{
	logger->LogMessage("[RE2R-R] Randomizer::HandleSoftLocks(%s: %s, %s: %s, %s: %p) called.\n",
	                   NAMEOF(difficulty), RE2RREnums::EnumDifficultyToString(difficulty).c_str(),
	                   NAMEOF(scenario), RE2RREnums::EnumScenarioToString(scenario).c_str(),
	                   NAMEOF(gen), gen);

	std::vector<GUID> candidates;
	if (scenario == RE2RREnums::Scenario::CLAIRE_A || scenario == RE2RREnums::Scenario::LEON_A) // A scenarios
	{
		logger->LogMessage("[RE2R-R] Randomizer::HandleSoftLocks: A scenario section.\n");

		// KeyStorageRoom
		candidates = {*StringToGUIDA("FF9122A6-7CCE-04E4-3317-103F06B2D2E5")};
		std::shuffle(candidates.begin(), candidates.end(), gen);
		seed.seedData.insert(std::make_pair(candidates[0], originalItemMapping[seed.gameMode][*StringToGUIDA("FF9122A6-7CCE-04E4-3317-103F06B2D2E5")]));

		// Knife
		candidates = {*StringToGUIDA("09749BFC-D1B4-09EA-3723-AC256D7E5630"), *StringToGUIDA("17761516-0B95-0710-16D2-EDDF56F1866D"), *StringToGUIDA("F1E708F9-318D-4D29-8351-EB1AA8218188"), *StringToGUIDA("0C4C5EC2-0EE6-0175-15E3-74B9F4A22F91"), *StringToGUIDA("59F3E4BF-ACB0-40B5-B7B6-01480EEC855F"), *StringToGUIDA("09749BFC-D1B4-09EA-3723-AC256D7E5630"), *StringToGUIDA("6A098F7F-81A3-4B2C-9144-8C28C9506C90"), *StringToGUIDA("C0888EF1-C0AA-47B1-B241-CDE8A11AA29C"), *StringToGUIDA("1FABF80A-A8B2-44CA-A8B6-D9DC1BC8BC4D"), *StringToGUIDA("03659087-CCD3-4032-A375-5DCCA3C339EE"), *StringToGUIDA("8AE2134C-5EFD-0227-3A61-0462F2C5CC5D"), *StringToGUIDA("21FA606C-B4D6-45C4-B097-2F439920F36C")};
		std::shuffle(candidates.begin(), candidates.end(), gen);
		seed.seedData.insert(std::make_pair(candidates[0], originalItemMapping[seed.gameMode][*StringToGUIDA("09749BFC-D1B4-09EA-3723-AC256D7E5630")]));
	}
	else // B scenarios
	{
		logger->LogMessage("[RE2R-R] Randomizer::HandleSoftLocks: B scenario section.\n");
	}

	logger->LogMessage("[RE2R-R] Randomizer::HandleSoftLocks: Non-randomized items section.\n");
	for (const auto &[key, value] : originalItemMapping[seed.gameMode])
	{
		if (value.ItemId == RE2RREnums::ItemType::PlugBishop ||
		    value.ItemId == RE2RREnums::ItemType::PlugKing ||
		    value.ItemId == RE2RREnums::ItemType::PlugKnight ||
		    value.ItemId == RE2RREnums::ItemType::PlugPawn ||
		    value.ItemId == RE2RREnums::ItemType::PlugQueen ||
		    value.ItemId == RE2RREnums::ItemType::PlugRook)
			seed.seedData.insert(std::make_pair(key, value));
	}

	logger->LogMessage("[RE2R-R] Randomizer::HandleSoftLocks: Completed.\n");
}

const Seed &Randomizer::GetSeed(void)
{
	logger->LogMessage("[RE2R-R] Randomizer::GetSeed() called.\n");
	return this->seed;
}
