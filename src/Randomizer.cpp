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
	memmove(&itemToReplace, &newItem, sizeof(RE2RItem));
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
// Seed (CLAIRE_B NORMAL): 566284478
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
		    value.ItemId == RE2RREnums::ItemType::KeyOrphanage ||
		    value.ItemId == RE2RREnums::ItemType::StuffedDoll ||
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
		originals.append_range(std::initializer_list<GUID>{
		    *StringToGUIDA("B70C9C24-93B9-4A2A-824A-A75700C67277").get(),
		    *StringToGUIDA("E49A8008-0A1F-4944-BF1E-F8DA443B82AD").get(),
		});

		candidates.append_range(std::initializer_list<GUID>{
		    // East Courtyard
		    *StringToGUIDA("65F7FE6D-5046-4E7D-B5AA-24747AAB03BB").get(),
		    *StringToGUIDA("B70C9C24-93B9-4A2A-824A-A75700C67277").get(),
		    *StringToGUIDA("D79F6C57-3330-4396-82EC-EDD8A4CBE27F").get(),
		});
		AddKeyItem(originals, candidates, gen);

		// If BoltCutter is left, randomize it to these locations. (TODO: This can actually be expanded to east hall and safe room)
		if (originals[0] == *StringToGUIDA("B70C9C24-93B9-4A2A-824A-A75700C67277").get())
		{
			candidates.append_range(std::initializer_list<GUID>{
			    // Art room
			    *StringToGUIDA("CB32491D-679A-0168-07B4-D26FE88EBC72").get(), // This is the statue arm that is on the table.
			    //*StringToGUIDA("D8C1E40B-DB48-42B0-AA16-B4F366245998").get(), // This is the statue arm that is inserted into the statue already
			    *StringToGUIDA("FA8A099B-2BE6-4196-936F-B53C9382F455").get(),
			    // 2nd floor east hallway
			    *StringToGUIDA("85F0708C-E754-4A1A-ABF6-1DEE1CB1097E").get(),
			    *StringToGUIDA("FC707A9A-F8BF-461A-8B83-EF90C00BAAF1").get(),
			    // East staiurwell
			    *StringToGUIDA("F66D5A99-E6D5-4B32-B86F-ED8BC4D0B37F").get(),
			    *StringToGUIDA("64B130EE-53DD-4F5B-822F-5A5A77730EAC").get(),
			    // East Office
			    *StringToGUIDA("49AF34BC-067C-4BB4-97A9-94FB6F83FBC1").get(),
			    *StringToGUIDA("76C43A01-0C25-4F3F-9F22-1762C9CF5577").get(),
			    *StringToGUIDA("AD84247C-A192-4EBA-B99D-412BD6F245B1").get(),
			    *StringToGUIDA("B15B8A2C-19D6-465F-A4BA-2B1CC9E1306A").get(),
			    *StringToGUIDA("DA2805DC-F487-0942-3C3D-5C4C65B04107").get(),
			    *StringToGUIDA("E47F659D-99A0-42BE-B1C8-E59FC1383708").get(),
			    // East Closet
			    *StringToGUIDA("21FA606C-B4D6-45C4-B097-2F439920F36C").get(),
			    *StringToGUIDA("B39EC79F-23A5-4B84-8E26-4C82B1A5D4CE").get(),
			    // Press Room
			    *StringToGUIDA("F71DDBE7-8CE3-4B98-B103-3F7AC4EC633F").get(),
			    // East Break Room (Save)
			    *StringToGUIDA("1E33C3D4-8971-4BA8-8F97-1FDA9E2F3F32").get(),
			    *StringToGUIDA("2456358F-71BD-4F97-94CF-B225EF4018AF").get(),
			    *StringToGUIDA("15F1C4E1-93B7-4AA3-9CFD-297C9E2C51CD").get(),
			    *StringToGUIDA("4E68F4C7-8AEB-418F-B089-7F7CB2751783").get(),
			    *StringToGUIDA("92A9F2F6-4CC4-449A-9B68-B94874D72816").get(),
			    *StringToGUIDA("03659087-CCD3-4032-A375-5DCCA3C339EE").get(),
			});
			AddKeyItem(originals, candidates, gen);
		}
		// If KeyCourtyard is left, randomize it to these locations.
		else if (originals[0] == *StringToGUIDA("E49A8008-0A1F-4944-BF1E-F8DA443B82AD").get())
		{
			candidates.append_range(std::initializer_list<GUID>{
			    // East Guard Room
			    *StringToGUIDA("E27DF9E6-5944-47EA-AE8B-5B1097FA4AF2").get(),
			    *StringToGUIDA("389292E7-42DB-49CE-8CF7-E42B324E46A2").get(),
			    *StringToGUIDA("E49A8008-0A1F-4944-BF1E-F8DA443B82AD").get(),
			    *StringToGUIDA("D4C49F95-9AB9-4CB3-9AAE-EC7A62B5A39B").get(),
			});
			AddKeyItem(originals, candidates, gen);
		}

		// Main Hall Fuse or Spade Key
		originals.append_range(std::initializer_list<GUID>{
		    *StringToGUIDA("15F1C4E1-93B7-4AA3-9CFD-297C9E2C51CD").get(),
		    *StringToGUIDA("1E671313-7622-0DB1-318D-4D3B5C9B1CA0").get(),
		});
		AddKeyItem(originals, candidates, gen);

		// If Main Hall Fuse is left, randomize it to these locations.
		if (originals[0] == *StringToGUIDA("15F1C4E1-93B7-4AA3-9CFD-297C9E2C51CD").get())
		{
			candidates.append_range(std::initializer_list<GUID>{
			    //*StringToGUIDA("").get(),
			});
			AddKeyItem(originals, candidates, gen);
		}
		// If Spade Key is left, randomize it to these locations.
		else if (originals[0] == *StringToGUIDA("1E671313-7622-0DB1-318D-4D3B5C9B1CA0").get())
		{
			candidates.append_range(std::initializer_list<GUID>{
			    //*StringToGUIDA("").get(),
			});
			AddKeyItem(originals, candidates, gen);
		}
	}

	logger.LogMessage("[RE2R-R] Randomizer::HandleSoftLocks: Completed.\n");
}

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
