#ifndef RE2RR_RANDOMIZER_H
#define RE2RR_RANDOMIZER_H

#include "Logging.h"
#include "Types.h"
#include <stdexcept>
#include <stdint.h>
#include <vector>

class Randomizer
{
private:
	ImmediateLogger *logger;
	std::vector<uint32_t> seed;
	RE2RREnums::Difficulty *difficulty;
	RE2RREnums::Scenario *scenario;
	RE2RREnums::Character *character;

	void RandomizeItem(app_ropeway_gamemastering_InventoryManager_PrimitiveItem *, app_ropeway_gamemastering_InventoryManager_PrimitiveItem);
	app_ropeway_gamemastering_InventoryManager_PrimitiveItem GetItemByType(uint32_t);
	void SetItemByGUID(app_ropeway_gamemastering_InventoryManager_PrimitiveItem *, GUID *);

protected:
public:
	Randomizer(ImmediateLogger *logger, std::vector<uint32_t> seed, RE2RREnums::Difficulty *difficulty, RE2RREnums::Scenario *scenario, RE2RREnums::Character *character)
	{
		this->logger = logger;
		this->seed = seed;
		this->difficulty = difficulty;
		this->scenario = scenario;
		this->character = character;

		logger->LogMessage("[RE2R-R] Randomizer::ctor(%s: %p, %s: %p, %s: %s, %s: %s, %s: %s) called.\n",
		                   RE2RR_NAMEOF(logger), (void *)logger,
		                   RE2RR_NAMEOF(seed), (void *)&seed,
		                   RE2RR_NAMEOF(difficulty), RE2RREnums::EnumDifficultyToString(*difficulty).c_str(),
		                   RE2RR_NAMEOF(scenario), RE2RREnums::EnumScenarioToString(*scenario).c_str(),
		                   RE2RR_NAMEOF(character), RE2RREnums::EnumCharacterToString(*character).c_str());
	}
	~Randomizer()
	{
		this->logger = nullptr;
		this->seed.clear();
		delete this->difficulty;
		delete this->scenario;
		delete this->character;
	}

	void ItemPickup(app_ropeway_gamemastering_InventoryManager_PrimitiveItem *, GUID *);
};

std::string GUIDToString(GUID *);

#endif
