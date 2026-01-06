#ifndef RE2RR_RANDOMIZER_H
#define RE2RR_RANDOMIZER_H

#include "Common.h"
#include "Database.h"
#include "File.h"
#include "Guid.h"
#include "Logging.h"
#include "Strings.h"
#include "Types.h"
#include <algorithm>
#include <format>
#include <fstream>
#include <future>
#include <iostream>
#include <list>
#include <random>
#include <ranges>
#include <stdexcept>
#include <stdint.h>
#include <thread>
#include <unordered_map>
#include <vector>

class Randomizer
{
private:
	std::span<const std::pair<const RE2RR::Types::Enums::FloorID, const char *>> floorNames;
	std::span<const std::pair<const RE2RR::Types::Enums::MapID, const char *>> mapNames;
	std::span<const std::pair<const RE2RR::Types::Enums::MapPartsID, const char *>> mapPartNames;

	RE2RR::Common::Logging::ImmediateLogger &logger;
	bool &debugSkipRandomization;
	std::unordered_map<GUID, RE2RR::Types::ItemInformation, std::hash<GUID>, std::equal_to<GUID>> originalItemInformation;
	RE2RR::Types::Seed seed;
	RE2RR::Types::Enums::FloorID floorId;
	RE2RR::Types::Enums::MapID mapId;
	RE2RR::Types::Enums::MapPartsID mapPartsId;
	RE2RR::Types::RE2RItem lastInteractedItem = {};
	RE2RR::Types::RE2RItem lastRandomizedItem = {};
	GUID lastInteractedItemPositionGuid = {};

	void RandomizeItem(RE2RR::Types::RE2RItem &, const RE2RR::Types::RE2RItem &, const RE2RR::Types::RE2RItem &);
	RE2RR::Types::RE2RItem GetItemByType(uint32_t);
	void SetItemByGUID(RE2RR::Types::RE2RItem *, GUID *);
	void SetLast(const RE2RR::Types::RE2RItem &, const RE2RR::Types::RE2RItem &, const GUID &);

	/// @brief Gets a list of candidate items based on a predicate.
	/// @tparam Predicate A lambda expression to filter the items we want to consider candidates.
	/// @param predicate The predicate to filter the items.
	/// @return An std::vector<RE2RR::Types::ItemInformation> containing the candidate items.
	template <typename Predicate>
	const std::vector<RE2RR::Types::ItemInformation> GetCandidates(const Predicate &predicate);

	/// @brief Gets a list of candidate items based on a predicate.
	/// @param itemGuids A list of candidate GUIDs to filter the items.
	/// @return An std::vector<RE2RR::Types::ItemInformation> containing the candidate items.
	const std::vector<RE2RR::Types::ItemInformation> GetCandidates(const std::initializer_list<GUID> &itemGuids);

	/// @brief
	/// @param gen
	void HandleSoftLocks(std::mt19937 &gen);

	/// @brief Adds a key item to a random one of the item drop candidates.
	/// @param originals The original items' drop location.
	/// @param destinations The candidate item drop locations we want this item to potentially be placed.
	/// @param gen The random number generator instance.
	void AddKeyItem(std::vector<RE2RR::Types::ItemInformation> &originals, std::vector<RE2RR::Types::ItemInformation> &destinations, std::mt19937 &gen);

protected:
public:
	Randomizer(RE2RR::Common::Logging::ImmediateLogger &logger, bool &debugSkipRandomization);
	~Randomizer(void);

	void ItemPickup(RE2RR::Types::RE2RItem &, const GUID &);
	bool ChangeArea(RE2RR::Types::Enums::MapPartsID, RE2RR::Types::Enums::MapID, RE2RR::Types::Enums::FloorID);

	const RE2RR::Types::Enums::Difficulty GetDifficulty(void);
	const RE2RR::Types::Enums::Scenario GetScenario(void);
	const RE2RR::Types::Enums::FloorID GetFloorID(void);
	const RE2RR::Types::Enums::MapID GetMapID(void);
	const RE2RR::Types::Enums::MapPartsID GetMapPartsID(void);
	const std::unique_ptr<const std::string> GetFloorName(void);
	const std::unique_ptr<const std::string> GetMapName(void);
	const std::unique_ptr<const std::string> GetMapPartsName(void);

	const RE2RR::Types::RE2RItem &GetLastInteractedItem(void);
	const RE2RR::Types::RE2RItem &GetLastRandomizedItem(void);
	GUID &GetLastInteractedItemPositionGuid(void);
	void Randomize(const RE2RR::Types::Enums::Difficulty &, const RE2RR::Types::Enums::Scenario &, int_fast32_t);
	const RE2RR::Types::Seed &GetSeed(void);
	void ExportCheatSheet();
};

#endif
