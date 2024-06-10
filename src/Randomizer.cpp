#include "Randomizer.h"

void Randomizer::ItemPickup(RE2RItem *itemToReplace, const RE2RItem &currentItem, GUID &itemPositionGuid)
{
	if (itemToReplace == nullptr)
		return;

	logger.LogMessage("[RE2R-R] Randomizer::ItemPickup(%s: %p, *%s: %s, *%s: %s) called.\n",
	                  NAMEOF(itemToReplace), itemToReplace,
	                  NAMEOF(currentItem), currentItem.ToString().c_str(),
	                  NAMEOF(itemPositionGuid), GUIDToString(itemPositionGuid).c_str());
	logger.LogMessage("[RE2R-R] originalItemMapping returned: %s.\n",
	                  this->originalItemMapping[this->seed.gameMode][itemPositionGuid].ToString().c_str());
	logger.LogMessage("[RE2R-R] seedData returned: %s.\n",
	                  this->seed.seedData[itemPositionGuid].ReplacementItem.ToString().c_str());
	SetLast(this->originalItemMapping[this->seed.gameMode][itemPositionGuid], this->seed.seedData[itemPositionGuid].ReplacementItem, itemPositionGuid);
	RandomizeItem(itemToReplace, this->originalItemMapping[this->seed.gameMode][itemPositionGuid], this->seed.seedData[itemPositionGuid].ReplacementItem);
}

void Randomizer::SetLast(const RE2RItem &item, const RE2RItem &randomizedItem, GUID &itemPositionGuid)
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

GUID &Randomizer::GetLastInteractedItemPositionGuid()
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

RE2RREnums::FloorID Randomizer::GetFloorID()
{
	return floorId;
}

const std::string &Randomizer::GetFloorName()
{
	return GetFloorNameById(floorId);
}

RE2RREnums::MapID Randomizer::GetMapID()
{
	return mapId;
}

const std::string &Randomizer::GetMapName()
{
	return GetMapNameById(mapId);
}

RE2RREnums::MapPartsID Randomizer::GetMapPartsID()
{
	return mapPartsId;
}

const std::string &Randomizer::GetMapPartsName()
{
	return GetMapPartsNameById(mapPartsId);
}

void Randomizer::RandomizeItem(RE2RItem *itemToReplace, const RE2RItem &originalItem, const RE2RItem &newItem)
{
	logger.LogMessage("[RE2R-R] Randomizer::RandomizeItem().\n\tOld (%p): %s.\n\tNew: %s.\n\t%s -> %s\n", itemToReplace, originalItem.ToString().c_str(), newItem.ToString().c_str(), RE2RREnums::EnumItemTypeToString(originalItem.ItemId).c_str(), RE2RREnums::EnumItemTypeToString(newItem.ItemId).c_str());
	*itemToReplace = newItem;
}

void Randomizer::Randomize(const RE2RREnums::Difficulty &difficulty, const RE2RREnums::Scenario &scenario, int_fast32_t initialSeed)
{
	logger.LogMessage("[RE2R-R] Randomizer::Randomize(%s: %s, %s: %s, %s: %d) called.\n",
	                  NAMEOF(difficulty), RE2RREnums::EnumDifficultyToString(difficulty).c_str(),
	                  NAMEOF(scenario), RE2RREnums::EnumScenarioToString(scenario).c_str(),
	                  NAMEOF(initialSeed), initialSeed);

	seed = Seed{.gameMode = GameModeKey{.Scenario = scenario, .Difficulty = difficulty}, .seedData = {}};
	std::mt19937 gen(initialSeed);

	HandleSoftLocks(gen);

	std::vector<RandomizedItem> values;
	for (const auto &[key, value] : originalItemMapping[seed.gameMode])
	{
		if (!seed.seedData.contains(key))
			values.push_back(RandomizedItem{.OriginalGUID = key, .ReplacementItem = value});
	}

	std::shuffle(values.begin(), values.end(), gen);

	auto value = values.begin();
	for (const auto &[key, _] : originalItemMapping[seed.gameMode])
	{
		if (!seed.seedData.contains(key))
			seed.seedData.insert(std::make_pair(key, *value++));
	}
}

void Randomizer::HandleSoftLocks(std::mt19937 &gen)
{
	logger.LogMessage("[RE2R-R] Randomizer::HandleSoftLocks(%s: %p) called.\n",
	                  NAMEOF(gen), gen);

	std::vector<GUID> candidates;
	if (seed.gameMode.Scenario == RE2RREnums::Scenario::CLAIRE_A || seed.gameMode.Scenario == RE2RREnums::Scenario::LEON_A) // A scenarios
	{
		logger.LogMessage("[RE2R-R] Randomizer::HandleSoftLocks: A scenario section.\n");

		// Knife
		candidates.append_range(std::initializer_list<GUID>{StringToGUIDA("09749BFC-D1B4-09EA-3723-AC256D7E5630"),
		                                                    StringToGUIDA("17761516-0B95-0710-16D2-EDDF56F1866D"),
		                                                    StringToGUIDA("F1E708F9-318D-4D29-8351-EB1AA8218188"),
		                                                    StringToGUIDA("0C4C5EC2-0EE6-0175-15E3-74B9F4A22F91"),
		                                                    StringToGUIDA("59F3E4BF-ACB0-40B5-B7B6-01480EEC855F"),
		                                                    StringToGUIDA("09749BFC-D1B4-09EA-3723-AC256D7E5630"),
		                                                    StringToGUIDA("6A098F7F-81A3-4B2C-9144-8C28C9506C90"),
		                                                    StringToGUIDA("C0888EF1-C0AA-47B1-B241-CDE8A11AA29C"),
		                                                    StringToGUIDA("1FABF80A-A8B2-44CA-A8B6-D9DC1BC8BC4D"),
		                                                    StringToGUIDA("03659087-CCD3-4032-A375-5DCCA3C339EE"),
		                                                    StringToGUIDA("8AE2134C-5EFD-0227-3A61-0462F2C5CC5D"),
		                                                    StringToGUIDA("21FA606C-B4D6-45C4-B097-2F439920F36C")});
		AddKeyItem(StringToGUIDA("09749BFC-D1B4-09EA-3723-AC256D7E5630"), candidates, gen);

		// Spade Key
		// candidates.append_range(std::initializer_list<GUID>{});
		// AddKeyItem(NULL, candidates, gen);
	}
	else // B scenarios
	{
		logger.LogMessage("[RE2R-R] Randomizer::HandleSoftLocks: B scenario section.\n");
	}

	logger.LogMessage("[RE2R-R] Randomizer::HandleSoftLocks: Non-randomized items section.\n");
	for (const auto &[key, value] : originalItemMapping[seed.gameMode])
	{
		if (value.ItemId == RE2RREnums::ItemType::KeyStorageRoom ||
		    value.ItemId == RE2RREnums::ItemType::PlugBishop ||
		    value.ItemId == RE2RREnums::ItemType::PlugKing ||
		    value.ItemId == RE2RREnums::ItemType::PlugKnight ||
		    value.ItemId == RE2RREnums::ItemType::PlugPawn ||
		    value.ItemId == RE2RREnums::ItemType::PlugQueen ||
		    value.ItemId == RE2RREnums::ItemType::PlugRook)
			seed.seedData.insert(std::make_pair(key, RandomizedItem{.OriginalGUID = key, .ReplacementItem = value}));
	}

	logger.LogMessage("[RE2R-R] Randomizer::HandleSoftLocks: Completed.\n");
}

void Randomizer::AddKeyItem(GUID &original, std::vector<GUID> &destinations, std::mt19937 &gen)
{
	size_t index = std::uniform_int_distribution<size_t>(0, destinations.size() - 1)(gen);

	logger.LogMessage("[RE2R-R] Randomizer::AddRandomItem[%d]\n\t%s (%s)\n\t%s (%s)\n",
	                  index,
	                  originalItemMapping[seed.gameMode][destinations[index]].ToString().c_str(),
	                  GUIDToString(destinations[index]).c_str(),
	                  originalItemMapping[seed.gameMode][original].ToString().c_str(),
	                  GUIDToString(original).c_str());

	// Seed (LEON_A NORMAL): 384451726
	seed.seedData.insert(std::make_pair(destinations[index], RandomizedItem{.OriginalGUID = original, .ReplacementItem = originalItemMapping[seed.gameMode][destinations[index]]}));
	destinations.erase(destinations.begin() + index); // Remove this entry as a candidate since we're using it now.
}

const Seed &Randomizer::GetSeed(void)
{
	logger.LogMessage("[RE2R-R] Randomizer::GetSeed() called.\n");
	return this->seed;
}

void Randomizer::ExportCheatSheet(int_fast32_t initialSeed)
{
	std::string filename = std::format("RE2RR_CheatSheet_{:d}.txt", initialSeed);
	std::ofstream file(filename, std::ios::out);

	if (!file.is_open())
	{
		logger.LogMessage("Unable to open file for writing: %s\n", filename.c_str());
		return;
	}

	for (const auto &[key, value] : originalItemMapping[seed.gameMode])
	{
		file << "[" << GUIDToString(key) << "] -> [" << GUIDToString(seed.seedData[key].OriginalGUID) << "]" << std::endl
		     << "\tFrom: " << RE2RREnums::EnumItemTypeToString(value.ItemId).c_str() << " / " << RE2RREnums::EnumWeaponTypeToString(value.WeaponId).c_str() << std::endl
		     << "\tTo  : " << RE2RREnums::EnumItemTypeToString(seed.seedData[key].ReplacementItem.ItemId).c_str() << " / " << RE2RREnums::EnumWeaponTypeToString(seed.seedData[key].ReplacementItem.WeaponId).c_str() << std::endl
		     << std::endl;
	}

	file.flush();
	file.close();
}
