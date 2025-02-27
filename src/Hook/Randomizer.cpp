#include "Randomizer.h"

void Randomizer::ItemPickup(RE2RR::Types::RE2RItem &itemToReplace, const GUID &itemPositionGuid)
{
	logger.LogMessage("[RE2R-R] Randomizer::ItemPickup(%s: %p, *%s: %s) called.\n",
	                  NAMEOF(itemToReplace), &itemToReplace,
	                  NAMEOF(itemPositionGuid), RE2RR::Common::Guid::ToString(itemPositionGuid).c_str());

	SetLast(this->originalItemInformation[itemPositionGuid].Item, this->seed.seedData[itemPositionGuid].ReplacementItem, itemPositionGuid);

	if (!debugSkipRandomization)
		RandomizeItem(itemToReplace, this->originalItemInformation[itemPositionGuid].Item, this->seed.seedData[itemPositionGuid].ReplacementItem);
}

void Randomizer::RandomizeItem(RE2RR::Types::RE2RItem &itemToReplace, const RE2RR::Types::RE2RItem &originalItem, const RE2RR::Types::RE2RItem &newItem)
{
	logger.LogMessage("[RE2R-R] Randomizer::RandomizeItem(%s: %p, %s: %p, %s: %p).\n",
	                  NAMEOF(itemToReplace), &itemToReplace,
	                  NAMEOF(originalItem), &originalItem,
	                  NAMEOF(newItem), &newItem);

	// Bail out of this is an invalid address for any of these parameters.
	// It may not be important for originalItem as we only use that for logging but for now, bail-a-saurus rex!
	if (!RE2RR::Common::Memory::TryValidatePointerStart(&itemToReplace, NAMEOF(itemToReplace), logger) ||
	    !RE2RR::Common::Memory::TryValidatePointerStart(&originalItem, NAMEOF(originalItem), logger) ||
	    !RE2RR::Common::Memory::TryValidatePointerStart(&newItem, NAMEOF(newItem), logger))
		return;

	logger.LogMessage("\t%s\n\t%s\n",
	                  originalItem.ToString().get()->c_str(),
	                  newItem.ToString().get()->c_str());

	try
	{
		// itemToReplace = newItem;
		memmove(&itemToReplace, &newItem, sizeof(RE2RR::Types::RE2RItem));
	}
	catch (const std::exception &ex)
	{
		RE2RR::Common::lastExceptionMessage = ex.what();
		logger.LogMessage("[RE2R-R] Randomizer::RandomizeItem() Exception: %s\n",
		                  RE2RR::Common::lastExceptionMessage);
	}
}

void Randomizer::Randomize(const RE2RR::Types::Enums::Difficulty &difficulty, const RE2RR::Types::Enums::Scenario &scenario, int_fast32_t initialSeed)
{
	logger.LogMessage("[RE2R-R] Randomizer::Randomize(%s: %s, %s: %s, %s: %d) called.\n",
	                  NAMEOF(difficulty), RE2RR::Types::Enums::EnumDifficultyToString(difficulty).get()->c_str(),
	                  NAMEOF(scenario), RE2RR::Types::Enums::EnumScenarioToString(scenario).get()->c_str(),
	                  NAMEOF(initialSeed), initialSeed);

	seed = RE2RR::Types::Seed{.initialSeedValue = initialSeed, .gameMode = RE2RR::Types::GameModeKey{.Scenario = scenario, .Difficulty = difficulty}, .seedData = {}};
	auto filteredItemDB = RE2RR::Database::GetItemDB() |
	                      std::views::filter([difficulty, scenario](const RE2RR::Types::ItemInformation &i)
	                                         {
												using namespace RE2RR::Common::Guid::Guid_Literals;
												auto scenarioComparison = i.Scenario == scenario;
												auto difficultyComparison = i.Difficulty == difficulty;
												auto comparison = scenarioComparison && difficultyComparison;
												return comparison; }) |
	                      std::views::transform([](const RE2RR::Types::ItemInformation &i)
	                                            { return std::make_pair(i.ItemPositionGUID, i); });
	originalItemInformation = std::unordered_map<GUID, RE2RR::Types::ItemInformation, std::hash<GUID>, std::equal_to<GUID>>(filteredItemDB.begin(), filteredItemDB.end());

	std::mt19937 gen(seed.initialSeedValue);
	HandleSoftLocks(gen);

	std::vector<RE2RR::Types::RandomizedItem> values;
	for (const auto &[key, value] : originalItemInformation)
	{
		if (!std::ranges::any_of(seed.seedData, [&key](const std::pair<GUID, RE2RR::Types::RandomizedItem> &kv)
		                         { return key == kv.second.OriginalGUID; }))
			values.push_back(RE2RR::Types::RandomizedItem{.OriginalGUID = key, .ReplacementItem = value.Item});
	}

	std::shuffle(values.begin(), values.end(), gen);

	auto value = values.begin();
	for (const auto &[key, _] : originalItemInformation)
	{
		if (!seed.seedData.contains(key))
			seed.seedData.insert(std::make_pair(key, *value++));
	}
}

// Seed (LEON_A NORMAL): 384451726
// Seed (CLAIRE_B NORMAL): 566284478
void Randomizer::HandleSoftLocks(std::mt19937 &gen)
{
	using namespace RE2RR::Common::Guid::Guid_Literals;
	logger.LogMessage("[RE2R-R] Randomizer::HandleSoftLocks(%s: %p) called.\n",
	                  NAMEOF(gen), gen);
	std::vector<GUID> originals;
	std::vector<GUID> candidates;

	logger.LogMessage("[RE2R-R] Randomizer::HandleSoftLocks: Non-randomized items section.\n");
	for (const auto &[_, value] : originalItemInformation)
	{
		// if (value.Floor == RE2RR::Types::Enums::FloorID::OrphanAsylum_A ||
		//     value.Floor == RE2RR::Types::Enums::FloorID::OrphanAsylum_B ||
		//     value.Floor == RE2RR::Types::Enums::FloorID::OrphanAsylum_C)
		// 	seed.seedData.insert(std::make_pair(value.ItemPositionGUID, RandomizedItem{.OriginalGUID = value.ItemPositionGUID, .ReplacementItem = value.Item}));

		// Do not randomize these items.
		if (value.Item.ItemId == RE2RR::Types::Enums::ItemType::KeyCardParkingGarage ||
		    value.Item.ItemId == RE2RR::Types::Enums::ItemType::KeyOrphanage ||
		    value.Item.ItemId == RE2RR::Types::Enums::ItemType::StuffedDoll ||
		    value.Item.ItemId == RE2RR::Types::Enums::ItemType::PlugBishop ||
		    value.Item.ItemId == RE2RR::Types::Enums::ItemType::PlugKing ||
		    value.Item.ItemId == RE2RR::Types::Enums::ItemType::PlugKnight ||
		    value.Item.ItemId == RE2RR::Types::Enums::ItemType::PlugPawn ||
		    value.Item.ItemId == RE2RR::Types::Enums::ItemType::PlugQueen ||
		    value.Item.ItemId == RE2RR::Types::Enums::ItemType::PlugRook)
			seed.seedData.insert(std::make_pair(value.ItemPositionGUID, RE2RR::Types::RandomizedItem{.OriginalGUID = value.ItemPositionGUID, .ReplacementItem = value.Item}));
	}

	if (seed.gameMode.Scenario == RE2RR::Types::Enums::Scenario::CLAIRE_A || seed.gameMode.Scenario == RE2RR::Types::Enums::Scenario::LEON_A) // A scenarios
	{
		logger.LogMessage("[RE2R-R] Randomizer::HandleSoftLocks: A scenario section.\n");

		// TODO: Redo this. Some of these can probably be randomized (KeySpade, BoltCutter).
		for (const auto &[_, value] : originalItemInformation)
		{
			if (value.Item.ItemId == RE2RR::Types::Enums::ItemType::KeyStorageRoom ||
			    value.Item.ItemId == RE2RR::Types::Enums::ItemType::KeySpade ||
			    value.Item.ItemId == RE2RR::Types::Enums::ItemType::BoltCutter)
				seed.seedData.insert(std::make_pair(value.ItemPositionGUID, RE2RR::Types::RandomizedItem{.OriginalGUID = value.ItemPositionGUID, .ReplacementItem = value.Item}));
		}

		// Marvin's CombatKnife
		originals.append_range(std::initializer_list<GUID>{"09749BFC-D1B4-09EA-3723-AC256D7E5630"_guid});
		candidates.append_range(std::initializer_list<GUID>{"09749BFC-D1B4-09EA-3723-AC256D7E5630"_guid});
		AddKeyItem(originals, candidates, gen);
	}
	else // B scenarios
	{
		logger.LogMessage("[RE2R-R] Randomizer::HandleSoftLocks: B scenario section.\n");

		// BoltCutter or KeyCourtyard
		originals.append_range(std::initializer_list<GUID>{
		    "B70C9C24-93B9-4A2A-824A-A75700C67277"_guid,
		    "E49A8008-0A1F-4944-BF1E-F8DA443B82AD"_guid,
		});

		candidates.append_range(std::initializer_list<GUID>{
		    // East Courtyard
		    "65F7FE6D-5046-4E7D-B5AA-24747AAB03BB"_guid,
		    "B70C9C24-93B9-4A2A-824A-A75700C67277"_guid,
		    "D79F6C57-3330-4396-82EC-EDD8A4CBE27F"_guid,
		});
		AddKeyItem(originals, candidates, gen);

		// If BoltCutter is left, randomize it to these locations. (TODO: This can actually be expanded to east hall and safe room)
		if (originals[0] == "B70C9C24-93B9-4A2A-824A-A75700C67277"_guid)
		{
			candidates.append_range(std::initializer_list<GUID>{
			    // Art room
			    "CB32491D-679A-0168-07B4-D26FE88EBC72"_guid, // This is the statue arm that is on the table.
			    // "D8C1E40B-DB48-42B0-AA16-B4F366245998"_guid, // This is the statue arm that is inserted into the statue already
			    "FA8A099B-2BE6-4196-936F-B53C9382F455"_guid,
			    // 2nd floor east hallway
			    "85F0708C-E754-4A1A-ABF6-1DEE1CB1097E"_guid,
			    "FC707A9A-F8BF-461A-8B83-EF90C00BAAF1"_guid,
			    // East staiurwell
			    "F66D5A99-E6D5-4B32-B86F-ED8BC4D0B37F"_guid,
			    "64B130EE-53DD-4F5B-822F-5A5A77730EAC"_guid,
			    // // East Office
			    // "49AF34BC-067C-4BB4-97A9-94FB6F83FBC1"_guid,
			    // "76C43A01-0C25-4F3F-9F22-1762C9CF5577"_guid,
			    // "AD84247C-A192-4EBA-B99D-412BD6F245B1"_guid,
			    // "B15B8A2C-19D6-465F-A4BA-2B1CC9E1306A"_guid,
			    // "DA2805DC-F487-0942-3C3D-5C4C65B04107"_guid,
			    // "E47F659D-99A0-42BE-B1C8-E59FC1383708"_guid,
			    // East Closet
			    "21FA606C-B4D6-45C4-B097-2F439920F36C"_guid,
			    "B39EC79F-23A5-4B84-8E26-4C82B1A5D4CE"_guid,
			    // Press Room
			    "F71DDBE7-8CE3-4B98-B103-3F7AC4EC633F"_guid,
			    // East Break Room (Save)
			    "1E33C3D4-8971-4BA8-8F97-1FDA9E2F3F32"_guid,
			    "2456358F-71BD-4F97-94CF-B225EF4018AF"_guid,
			    "15F1C4E1-93B7-4AA3-9CFD-297C9E2C51CD"_guid,
			    "4E68F4C7-8AEB-418F-B089-7F7CB2751783"_guid, // This is LEON only...!
			    "92A9F2F6-4CC4-449A-9B68-B94874D72816"_guid,
			    "03659087-CCD3-4032-A375-5DCCA3C339EE"_guid,
			});
			AddKeyItem(originals, candidates, gen);
		}
		// If KeyCourtyard is left, randomize it to these locations.
		else if (originals[0] == "E49A8008-0A1F-4944-BF1E-F8DA443B82AD"_guid)
		{
			candidates.append_range(std::initializer_list<GUID>{
			    // East Guard Room
			    "E27DF9E6-5944-47EA-AE8B-5B1097FA4AF2"_guid,
			    "389292E7-42DB-49CE-8CF7-E42B324E46A2"_guid,
			    "E49A8008-0A1F-4944-BF1E-F8DA443B82AD"_guid,
			    "D4C49F95-9AB9-4CB3-9AAE-EC7A62B5A39B"_guid,
			});
			AddKeyItem(originals, candidates, gen);
		}

		// Main Hall Fuse or Spade Key
		originals.append_range(std::initializer_list<GUID>{
		    "15F1C4E1-93B7-4AA3-9CFD-297C9E2C51CD"_guid,
		    "1E671313-7622-0DB1-318D-4D3B5C9B1CA0"_guid,
		});
		AddKeyItem(originals, candidates, gen);

		// If Main Hall Fuse is left, randomize it to these locations.
		if (originals[0] == "15F1C4E1-93B7-4AA3-9CFD-297C9E2C51CD"_guid)
		{
			candidates.append_range(std::initializer_list<GUID>{
			    // ""_guid,
			    // pretty much anywhere up to maiden medallion or stars office area.
			});
			AddKeyItem(originals, candidates, gen);
		}
		// If Spade Key is left, randomize it to these locations.
		else if (originals[0] == "1E671313-7622-0DB1-318D-4D3B5C9B1CA0"_guid)
		{
			candidates.append_range(std::initializer_list<GUID>{
			    // Main Hall
			    "6002D460-036A-4CEA-BB6B-BC589EAFC3D5"_guid,
			    "65CE3F5E-37B7-4F64-995B-3301EA6DFB9D"_guid,
			    "F1E708F9-318D-4D29-8351-EB1AA8218188"_guid,
			    "0C4C5EC2-0EE6-0175-15E3-74B9F4A22F91"_guid,
			    "4E718EA1-5BB3-4E98-A6F8-FD012C058DE5"_guid,
			    // 2nd floor waiting room
			    "6A098F7F-81A3-4B2C-9144-8C28C9506C90"_guid,
			    "C0888EF1-C0AA-47B1-B241-CDE8A11AA29C"_guid,
			    // Operations Room
			    "65DB71B3-1BC3-4074-80FA-282C363DA0A0"_guid,
			    "8A880186-D623-4B03-8820-DC06781D527F"_guid,
			    "2D717007-20AC-4BD6-8563-138F3EECBD29"_guid,
			    "4AD55D3D-CF04-0CC2-2563-6045F552BF7B"_guid,
			    "A1B4B37D-7916-4F7B-B290-9E1500527828"_guid,
			    // West Hallway 1st floor
			    "3B1822E5-3C5F-40E9-A7CC-2EA0E0869454"_guid,
			    "A9FB31F3-03CE-4369-B897-3C25461F6634"_guid,
			    "297ACBFC-1ECE-4079-824E-A8B0469E074F"_guid,
			    // West Office
			    "2A907E12-7FE3-4559-9AF4-3051473F8FAA"_guid,
			    "89524D9A-972D-4608-A4D2-9DF8FD77F057"_guid,
			    "9F00CC80-24E4-448D-B72D-78B39E4A5808"_guid,
			    "E823B55D-3226-0FA9-2742-E0CEB2A3E4AD"_guid,
			    // Darkroom (West Save Room)
			    "A66B843C-DB59-49A8-B7DA-774944EB7298"_guid,
			    "A8C3FD34-3F01-47E1-831D-784EF6822707"_guid,
			    "FAF9B2E8-5373-48B7-AA5A-7554AB1A613C"_guid,
			    // lobby, etc.
			});
			AddKeyItem(originals, candidates, gen);
		}
	}

	logger.LogMessage("[RE2R-R] Randomizer::HandleSoftLocks: Completed.\n");
}

void Randomizer::AddKeyItem(std::vector<GUID> &originals, std::vector<GUID> &destinations, std::mt19937 &gen)
{
	// Remove any GUIDs that aren't in originalItemInformation that may have slipped through.
	originals.erase(
	    std::remove_if(originals.begin(), originals.end(),
	                   [this](const GUID &guid)
	                   { return !originalItemInformation.contains(guid); }),
	    originals.end());

	destinations.erase(
	    std::remove_if(destinations.begin(), destinations.end(),
	                   [this](const GUID &guid)
	                   { return !originalItemInformation.contains(guid); }),
	    destinations.end());

	// Don't proceed if we're empty...
	if (originals.empty() || destinations.empty())
	{
		logger.LogMessage("[RE2R-R] Randomizer::AddKeyItem: No valid GUIDs available after filtering\n");
		return;
	}

	size_t origIndex = std::uniform_int_distribution<size_t>(0, originals.size() - 1)(gen);
	size_t destIndex = std::uniform_int_distribution<size_t>(0, destinations.size() - 1)(gen);

	logger.LogMessage("[RE2R-R] Randomizer::AddKeyItem[%d]\n\t%s (%s)\n\t%s (%s)\n",
	                  destIndex,
	                  originalItemInformation[destinations[destIndex]].Item.ToString().get()->c_str(),
	                  RE2RR::Common::Guid::ToString(destinations[destIndex]).c_str(),
	                  originalItemInformation[originals[origIndex]].Item.ToString().get()->c_str(),
	                  RE2RR::Common::Guid::ToString(originals[origIndex]).c_str());

	seed.seedData.insert(std::make_pair(destinations[destIndex], RE2RR::Types::RandomizedItem{.OriginalGUID = originals[origIndex], .ReplacementItem = originalItemInformation[originals[origIndex]].Item}));

	originals.erase(originals.begin() + origIndex);       // Remove this entry as an original since we've handled it now.
	destinations.erase(destinations.begin() + destIndex); // Remove this entry as a candidate since we're using it now.
}

const RE2RR::Types::Seed &Randomizer::GetSeed(void)
{
	logger.LogMessage("[RE2R-R] Randomizer::GetSeed() called.\n");
	return this->seed;
}

void Randomizer::ExportCheatSheet()
{
	if (seed.gameMode.Scenario == RE2RR::Types::Enums::Scenario::INVALID)
	{
		logger.LogMessage("Seed not yet initialized!\n");
		return;
	}

	std::string filename = std::format("RE2RR_CheatSheet_{:d}.txt", seed.initialSeedValue);
	std::ofstream file(filename, std::ios::out);

	if (!file.is_open())
	{
		logger.LogMessage("Unable to open file for writing: %s\n", filename.c_str());
		return;
	}

	file
	    << "Resident Evil 2 (2019) Randomizer" << std::endl
	    << std::format("v{:d}.{:d}.{:d} (Build #{:d})", RE2RR_VERSION_MAJOR, RE2RR_VERSION_MINOR, RE2RR_VERSION_PATCH, RE2RR_VERSION_BUILD) << std::endl
	    << "Seed: " << seed.initialSeedValue << std::endl
	    << "Scenario: " << *RE2RR::Types::Enums::EnumScenarioToString(seed.gameMode.Scenario).get() << std::endl
	    << "Difficulty: " << *RE2RR::Types::Enums::EnumDifficultyToString(seed.gameMode.Difficulty).get() << std::endl
	    << std::endl;

	constexpr const char unlabeledSection[] = "N/A";
	for (const auto &[key, value] : originalItemInformation)
	{
		const GUID &oldItemGUID = key;
		const RE2RR::Types::ItemInformation &oldItemInfo = value;
		const GUID &newItemGUID = seed.seedData[key].OriginalGUID;
		const RE2RR::Types::ItemInformation &newItemInfo = originalItemInformation[newItemGUID];

		file
		    << std::format("From: {:<40} ", *oldItemInfo.Item.GetName().get())
		    << std::format("{:<50} ", std::format("Floor [{} ({})]", RE2RR::Database::GetLookupValue(floorNames, oldItemInfo.Floor, unlabeledSection), *RE2RR::Types::Enums::EnumFloorIDToString(oldItemInfo.Floor).get()))
		    << std::format("{:<60} ", std::format("Map [{} ({})]", RE2RR::Database::GetLookupValue(mapNames, oldItemInfo.Map, unlabeledSection), *RE2RR::Types::Enums::EnumMapIDToString(oldItemInfo.Map).get()))
		    << std::format("{:<50} ", std::format("Map Parts [{} ({})]", RE2RR::Database::GetLookupValue(mapPartNames, oldItemInfo.MapPart, unlabeledSection), *RE2RR::Types::Enums::EnumMapPartsIDToString(oldItemInfo.MapPart).get()))
		    << std::format("Guid [{}]", RE2RR::Common::Guid::ToString(oldItemGUID))
		    << std::endl

		    << std::format("To  : {:<40} ", *newItemInfo.Item.GetName().get())
		    << std::format("{:<50} ", std::format("Floor [{} ({})]", RE2RR::Database::GetLookupValue(floorNames, newItemInfo.Floor, unlabeledSection), *RE2RR::Types::Enums::EnumFloorIDToString(newItemInfo.Floor).get()))
		    << std::format("{:<60} ", std::format("Map [{} ({})]", RE2RR::Database::GetLookupValue(mapNames, newItemInfo.Map, unlabeledSection), *RE2RR::Types::Enums::EnumMapIDToString(newItemInfo.Map).get()))
		    << std::format("{:<50} ", std::format("Map Parts [{} ({})]", RE2RR::Database::GetLookupValue(mapPartNames, newItemInfo.MapPart, unlabeledSection), *RE2RR::Types::Enums::EnumMapPartsIDToString(newItemInfo.MapPart).get()))
		    << std::format("Guid [{}]", RE2RR::Common::Guid::ToString(newItemGUID))
		    << std::endl

		    << std::endl;
	}

	file.flush();
	file.close();
}

void Randomizer::SetLast(const RE2RR::Types::RE2RItem &item, const RE2RR::Types::RE2RItem &randomizedItem, const GUID &itemPositionGuid)
{
	this->lastInteractedItem = item;
	this->lastRandomizedItem = randomizedItem;
	this->lastInteractedItemPositionGuid = itemPositionGuid;
}

const RE2RR::Types::RE2RItem &Randomizer::GetLastInteractedItem()
{
	return this->lastInteractedItem;
}

const RE2RR::Types::RE2RItem &Randomizer::GetLastRandomizedItem()
{
	return this->lastRandomizedItem;
}

GUID &Randomizer::GetLastInteractedItemPositionGuid()
{
	return this->lastInteractedItemPositionGuid;
}

bool Randomizer::ChangeArea(RE2RR::Types::Enums::MapPartsID mapPartsId, RE2RR::Types::Enums::MapID mapId, RE2RR::Types::Enums::FloorID floorId)
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

RE2RR::Types::Enums::Difficulty Randomizer::GetDifficulty()
{
	return seed.gameMode.Difficulty;
}

RE2RR::Types::Enums::Scenario Randomizer::GetScenario()
{
	return seed.gameMode.Scenario;
}

RE2RR::Types::Enums::FloorID Randomizer::GetFloorID()
{
	return floorId;
}

const std::unique_ptr<std::string> Randomizer::GetFloorName()
{
	if (floorNames.contains(floorId))
		return std::make_unique<std::string>(std::format("{} ({})", floorNames.at(floorId), *RE2RR::Types::Enums::EnumFloorIDToString(floorId).get()));
	else
		return RE2RR::Types::Enums::EnumFloorIDToString(floorId);
}

RE2RR::Types::Enums::MapID Randomizer::GetMapID()
{
	return mapId;
}

const std::unique_ptr<std::string> Randomizer::GetMapName()
{
	if (mapNames.contains(mapId))
		return std::make_unique<std::string>(std::format("{} ({})", mapNames.at(mapId), *RE2RR::Types::Enums::EnumMapIDToString(mapId).get()));
	else
		return RE2RR::Types::Enums::EnumMapIDToString(mapId);
}

RE2RR::Types::Enums::MapPartsID Randomizer::GetMapPartsID()
{
	return mapPartsId;
}

const std::unique_ptr<std::string> Randomizer::GetMapPartsName()
{
	if (mapPartNames.contains(mapPartsId))
		return std::make_unique<std::string>(std::format("{} ({})", mapPartNames.at(mapPartsId), *RE2RR::Types::Enums::EnumMapPartsIDToString(mapPartsId).get()));
	else
		return RE2RR::Types::Enums::EnumMapPartsIDToString(mapPartsId);
}
