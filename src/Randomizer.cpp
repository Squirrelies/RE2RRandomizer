#include "Randomizer.h"

void Randomizer::ItemPickup(RE2RItem &itemToReplace, const RE2RItem &currentItem, const GUID &itemPositionGuid)
{
	logger.LogMessage("[RE2R-R] Randomizer::ItemPickup(%s: %p, *%s: %s, *%s: %s) called.\n",
	                  NAMEOF(itemToReplace), &itemToReplace,
	                  NAMEOF(currentItem), currentItem.ToString().get()->c_str(),
	                  NAMEOF(itemPositionGuid), GUIDToString(itemPositionGuid).get()->c_str());
	logger.LogMessage("[RE2R-R] originalItemMapping returned: %s.\n",
	                  this->originalItemMapping[this->seed.gameMode][itemPositionGuid].ToString().get()->c_str());
	logger.LogMessage("[RE2R-R] seedData returned: %s.\n",
	                  this->seed.seedData[itemPositionGuid].ReplacementItem.ToString().get()->c_str());
	SetLast(this->originalItemMapping[this->seed.gameMode][itemPositionGuid], this->seed.seedData[itemPositionGuid].ReplacementItem, itemPositionGuid);
	if (!debugSkipRandomization)
		RandomizeItem(itemToReplace, this->originalItemMapping[this->seed.gameMode][itemPositionGuid], this->seed.seedData[itemPositionGuid].ReplacementItem);
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

void Randomizer::RandomizeItem(RE2RItem &itemToReplace, const RE2RItem &originalItem, const RE2RItem &newItem)
{
	logger.LogMessage("[RE2R-R] Randomizer::RandomizeItem().\n\tOld (%p): %s.\n\tNew: %s.\n\t%s -> %s\n", &itemToReplace, originalItem.ToString().get()->c_str(), newItem.ToString().get()->c_str(), RE2RREnums::EnumItemTypeToString(originalItem.ItemId).get()->c_str(), RE2RREnums::EnumItemTypeToString(newItem.ItemId).get()->c_str());
	itemToReplace = newItem;
}

void Randomizer::Randomize(const RE2RREnums::Difficulty &difficulty, const RE2RREnums::Scenario &scenario, int_fast32_t initialSeed)
{
	logger.LogMessage("[RE2R-R] Randomizer::Randomize(%s: %s, %s: %s, %s: %d) called.\n",
	                  NAMEOF(difficulty), RE2RREnums::EnumDifficultyToString(difficulty).get()->c_str(),
	                  NAMEOF(scenario), RE2RREnums::EnumScenarioToString(scenario).get()->c_str(),
	                  NAMEOF(initialSeed), initialSeed);

	seed = Seed{.gameMode = GameModeKey{.Scenario = scenario, .Difficulty = difficulty}, .seedData = {}};
	std::mt19937 gen(initialSeed);

	HandleSoftLocks(gen);

	std::vector<RandomizedItem> values;
	for (const auto &[key, value] : originalItemMapping[seed.gameMode])
	{
		if (!std::ranges::any_of(seed.seedData, [&key](const std::pair<GUID, RandomizedItem> &kv)
		                         { return key == kv.second.OriginalGUID; }))
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

// Seed (LEON_A NORMAL): 384451726
void Randomizer::HandleSoftLocks(std::mt19937 &gen)
{
	logger.LogMessage("[RE2R-R] Randomizer::HandleSoftLocks(%s: %p) called.\n",
	                  NAMEOF(gen), gen);

	std::vector<GUID> candidates;
	if (seed.gameMode.Scenario == RE2RREnums::Scenario::CLAIRE_A || seed.gameMode.Scenario == RE2RREnums::Scenario::LEON_A) // A scenarios
	{
		logger.LogMessage("[RE2R-R] Randomizer::HandleSoftLocks: A scenario section.\n");

		// Knife
		candidates.append_range(std::initializer_list<GUID>{
		    StringToGUIDA("09749BFC-D1B4-09EA-3723-AC256D7E5630"),
		    StringToGUIDA("17761516-0B95-0710-16D2-EDDF56F1866D"),
		    StringToGUIDA("F1E708F9-318D-4D29-8351-EB1AA8218188"),
		    StringToGUIDA("0C4C5EC2-0EE6-0175-15E3-74B9F4A22F91"),
		    StringToGUIDA("59F3E4BF-ACB0-40B5-B7B6-01480EEC855F"),
		    StringToGUIDA("6A098F7F-81A3-4B2C-9144-8C28C9506C90"),
		    StringToGUIDA("C0888EF1-C0AA-47B1-B241-CDE8A11AA29C"),
		    StringToGUIDA("1FABF80A-A8B2-44CA-A8B6-D9DC1BC8BC4D"),
		    StringToGUIDA("03659087-CCD3-4032-A375-5DCCA3C339EE"),
		    StringToGUIDA("8AE2134C-5EFD-0227-3A61-0462F2C5CC5D"),
		    StringToGUIDA("21FA606C-B4D6-45C4-B097-2F439920F36C")});
		AddKeyItem(StringToGUIDA("09749BFC-D1B4-09EA-3723-AC256D7E5630"), candidates, gen);

		// Spade Key
		candidates.append_range(std::initializer_list<GUID>{
		    StringToGUIDA("1E671313-7622-0DB1-318D-4D3B5C9B1CA0"),
		    StringToGUIDA("792CD162-B4FD-44F0-B10E-2576B241C815"),
		    StringToGUIDA("B98024D4-BD20-02DC-228E-2718F9F4E693"),
		    StringToGUIDA("725BFD68-10C7-04EC-120D-2D8EEA24A933"),
		    StringToGUIDA("CA039CC1-DFC3-4B2A-9918-92B9E8D93BBB"),
		    StringToGUIDA("923B3354-E5C4-4A5F-BFF1-DD76FC643317"),
		    StringToGUIDA("E823B55D-3226-0FA9-2742-E0CEB2A3E4AD"),
		    StringToGUIDA("BF8A39DB-8BB1-0E78-0DEA-8DA0C264476E"),
		    StringToGUIDA("2A907E12-7FE3-4559-9AF4-3051473F8FAA"),
		    StringToGUIDA("9F00CC80-24E4-448D-B72D-78B39E4A5808"),
		    StringToGUIDA("FAF9B2E8-5373-48B7-AA5A-7554AB1A613C"),
		    StringToGUIDA("A66B843C-DB59-49A8-B7DA-774944EB7298"),
		    StringToGUIDA("A8C3FD34-3F01-47E1-831D-784EF6822707"),
		    StringToGUIDA("89E3BCFB-964D-4068-9248-219A4F52FBAF"),
		    StringToGUIDA("3B1822E5-3C5F-40E9-A7CC-2EA0E0869454"),
		    StringToGUIDA("A9FB31F3-03CE-4369-B897-3C25461F6634"),
		    StringToGUIDA("C132B6AB-AF0B-49A5-8D34-0531BBFFEA1A"),
		    StringToGUIDA("5B941AC8-03C9-4C51-9F56-8C44D8B08218"),
		    StringToGUIDA("4176F7D5-727D-43AD-AE01-B01D1E3D99A6"),
		    StringToGUIDA("759E8645-B0B3-4AB2-92CF-31035AF835CC"),
		    StringToGUIDA("02A2983C-F3F2-46A3-B681-07FAE38B72AC"),
		    StringToGUIDA("F842B0CF-4D7C-0112-2CFE-6574850326A7"),
		    StringToGUIDA("87758B8D-E424-43DD-AFEA-2B5321A769E8"),
		    StringToGUIDA("BAB694FD-96A8-41E8-A261-9436D992B853"),
		    StringToGUIDA("B2FA1538-4D10-4056-84B4-0B5E78D6D82F"),
		    StringToGUIDA("6A43B6B6-9C0A-456C-A0A2-B36BD0BBEE83"),
		    StringToGUIDA("6A098F7F-81A3-4B2C-9144-8C28C9506C90"),
		    StringToGUIDA("C0888EF1-C0AA-47B1-B241-CDE8A11AA29C"),
		});
		AddKeyItem(StringToGUIDA("1E671313-7622-0DB1-318D-4D3B5C9B1CA0"), candidates, gen);
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
	                  originalItemMapping[seed.gameMode][destinations[index]].ToString().get()->c_str(),
	                  GUIDToString(destinations[index]).get()->c_str(),
	                  originalItemMapping[seed.gameMode][original].ToString().get()->c_str(),
	                  GUIDToString(original).get()->c_str());

	seed.seedData.insert(std::make_pair(destinations[index], RandomizedItem{.OriginalGUID = original, .ReplacementItem = originalItemMapping[seed.gameMode][original]}));
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
		     << "\tFrom: " << RE2RREnums::EnumItemTypeToString(value.ItemId).get()->c_str() << " / " << RE2RREnums::EnumWeaponTypeToString(value.WeaponId).get()->c_str() << std::endl
		     << "\tTo  : " << RE2RREnums::EnumItemTypeToString(seed.seedData[key].ReplacementItem.ItemId).get()->c_str() << " / " << RE2RREnums::EnumWeaponTypeToString(seed.seedData[key].ReplacementItem.WeaponId).get()->c_str() << std::endl
		     << std::endl;
	}

	file.flush();
	file.close();
}
