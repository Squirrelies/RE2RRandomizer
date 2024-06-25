#include "Randomizer.h"

void Randomizer::ItemPickup(RE2RItem &itemToReplace, const GUID &itemPositionGuid)
{
	logger.LogMessage("[RE2R-R] Randomizer::ItemPickup(%s: %p, *%s: %s) called.\n",
	                  NAMEOF(itemToReplace), &itemToReplace,
	                  NAMEOF(itemPositionGuid), GUIDToString(itemPositionGuid).get()->c_str());

	SetLast(this->originalItemMapping[this->seed.gameMode][itemPositionGuid], this->seed.seedData[itemPositionGuid].ReplacementItem, itemPositionGuid);

	if (!debugSkipRandomization)
		RandomizeItem(itemToReplace, this->originalItemMapping[this->seed.gameMode][itemPositionGuid], this->seed.seedData[itemPositionGuid].ReplacementItem);
}

void Randomizer::RandomizeItem(RE2RItem &itemToReplace, const RE2RItem &originalItem, const RE2RItem &newItem)
{
	logger.LogMessage("[RE2R-R] Randomizer::RandomizeItem(%s: %p, ...).\n\t%s\n\t%s\n",
	                  NAMEOF(itemToReplace), &itemToReplace,
	                  originalItem.ToString().get()->c_str(),
	                  newItem.ToString().get()->c_str());

	// itemToReplace = newItem;
	memcpy(&itemToReplace, &newItem, sizeof(RE2RItem));
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
	std::vector<GUID> originals;
	std::vector<GUID> candidates;

	logger.LogMessage("[RE2R-R] Randomizer::HandleSoftLocks: Non-randomized items section.\n");
	for (const auto &[key, value] : originalItemMapping[seed.gameMode])
	{
		if (value.ItemId == RE2RREnums::ItemType::KeyCardParkingGarage ||
		    value.ItemId == RE2RREnums::ItemType::PlugBishop ||
		    value.ItemId == RE2RREnums::ItemType::PlugKing ||
		    value.ItemId == RE2RREnums::ItemType::PlugKnight ||
		    value.ItemId == RE2RREnums::ItemType::PlugPawn ||
		    value.ItemId == RE2RREnums::ItemType::PlugQueen ||
		    value.ItemId == RE2RREnums::ItemType::PlugRook)
			seed.seedData.insert(std::make_pair(key, RandomizedItem{.OriginalGUID = key, .ReplacementItem = value}));
	}

	if (seed.gameMode.Scenario == RE2RREnums::Scenario::CLAIRE_A || seed.gameMode.Scenario == RE2RREnums::Scenario::LEON_A) // A scenarios
	{
		for (const auto &[key, value] : originalItemMapping[seed.gameMode])
		{
			if (value.ItemId == RE2RREnums::ItemType::KeyStorageRoom ||
			    value.ItemId == RE2RREnums::ItemType::KeySpade ||
			    value.ItemId == RE2RREnums::ItemType::BoltCutter)
				seed.seedData.insert(std::make_pair(key, RandomizedItem{.OriginalGUID = key, .ReplacementItem = value}));
		}
		logger.LogMessage("[RE2R-R] Randomizer::HandleSoftLocks: A scenario section.\n");

		originals.append_range(std::initializer_list<GUID>{*StringToGUIDA("09749BFC-D1B4-09EA-3723-AC256D7E5630").get()});
		candidates.append_range(std::initializer_list<GUID>{*StringToGUIDA("09749BFC-D1B4-09EA-3723-AC256D7E5630").get()});
		AddKeyItem(originals, candidates, gen);
	}
	else // B scenarios
	{
		logger.LogMessage("[RE2R-R] Randomizer::HandleSoftLocks: B scenario section.\n");

		// BoltCutter or KeyCourtyard
		originals.append_range(std::initializer_list<GUID>{*StringToGUIDA("B70C9C24-93B9-4A2A-824A-A75700C67277").get(),
		                                                   *StringToGUIDA("E49A8008-0A1F-4944-BF1E-F8DA443B82AD").get()});

		candidates.append_range(std::initializer_list<GUID>{
		    *StringToGUIDA("65F7FE6D-5046-4E7D-B5AA-24747AAB03BB").get(),
		    *StringToGUIDA("B70C9C24-93B9-4A2A-824A-A75700C67277").get(),
		    *StringToGUIDA("D79F6C57-3330-4396-82EC-EDD8A4CBE27F").get()});
		AddKeyItem(originals, candidates, gen);

		// If BoltCutter is left, randomize it to these locations.
		if (originals[0] == *StringToGUIDA("B70C9C24-93B9-4A2A-824A-A75700C67277").get())
		{
			candidates.append_range(std::initializer_list<GUID>{
			    *StringToGUIDA("CB32491D-679A-0168-07B4-D26FE88EBC72").get(),
			    *StringToGUIDA("4A8A159A-EFDA-0123-3D96-01C9FBF9019A").get(),
			    *StringToGUIDA("FA8A099B-2BE6-4196-936F-B53C9382F455").get(),
			    *StringToGUIDA("D8C1E40B-DB48-42B0-AA16-B4F366245998").get(),
			    *StringToGUIDA("85F0708C-E754-4A1A-ABF6-1DEE1CB1097E").get(),
			    *StringToGUIDA("FC707A9A-F8BF-461A-8B83-EF90C00BAAF1").get()});
			AddKeyItem(originals, candidates, gen);
		}
		// If KeyCourtyard is left, randomize it to these locations.
		else if (originals[0] == *StringToGUIDA("E49A8008-0A1F-4944-BF1E-F8DA443B82AD").get())
		{
			candidates.append_range(std::initializer_list<GUID>{
			    *StringToGUIDA("E27DF9E6-5944-47EA-AE8B-5B1097FA4AF2").get(),
			    *StringToGUIDA("389292E7-42DB-49CE-8CF7-E42B324E46A2").get(),
			    *StringToGUIDA("E49A8008-0A1F-4944-BF1E-F8DA443B82AD").get(),
			    *StringToGUIDA("D4C49F95-9AB9-4CB3-9AAE-EC7A62B5A39B").get()});
			AddKeyItem(originals, candidates, gen);
		}
	}

	logger.LogMessage("[RE2R-R] Randomizer::HandleSoftLocks: Completed.\n");
}

// void Randomizer::AddKeyItem(GUID &original, std::vector<GUID> &destinations, std::mt19937 &gen)
void Randomizer::AddKeyItem(std::vector<GUID> &originals, std::vector<GUID> &destinations, std::mt19937 &gen)
{
	size_t origIndex = std::uniform_int_distribution<size_t>(0, originals.size() - 1)(gen);
	size_t destIndex = std::uniform_int_distribution<size_t>(0, destinations.size() - 1)(gen);

	logger.LogMessage("[RE2R-R] Randomizer::AddRandomItem[%d]\n\t%s (%s)\n\t%s (%s)\n",
	                  destIndex,
	                  originalItemMapping[seed.gameMode][destinations[destIndex]].ToString().get()->c_str(),
	                  GUIDToString(destinations[destIndex]).get()->c_str(),
	                  originalItemMapping[seed.gameMode][originals[origIndex]].ToString().get()->c_str(),
	                  GUIDToString(originals[origIndex]).get()->c_str());

	seed.seedData.insert(std::make_pair(destinations[destIndex], RandomizedItem{.OriginalGUID = originals[origIndex], .ReplacementItem = originalItemMapping[seed.gameMode][originals[origIndex]]}));

	originals.erase(originals.begin() + origIndex);       // Remove this entry as an original since we've handled it now.
	destinations.erase(destinations.begin() + destIndex); // Remove this entry as a candidate since we're using it now.
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
