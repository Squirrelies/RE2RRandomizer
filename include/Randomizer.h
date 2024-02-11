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
	Difficulty *difficulty;
	Scenario *scenario;
	Character *character;

	void RandomizeItem(app_ropeway_gamemastering_InventoryManager_PrimitiveItem *, app_ropeway_gamemastering_InventoryManager_PrimitiveItem);
	app_ropeway_gamemastering_InventoryManager_PrimitiveItem GetItemByType(uint32_t);
	void SetItemByGUID(app_ropeway_gamemastering_InventoryManager_PrimitiveItem *, GUID *);

protected:
public:
	Randomizer(ImmediateLogger *logger, std::vector<uint32_t> seed, Difficulty *difficulty, Scenario *scenario, Character *character)
	{
		this->logger = logger;
		this->seed = seed;
		this->difficulty = difficulty;
		this->scenario = scenario;
		this->character = character;

		logger->LogMessage("[RE2R-R] Randomizer::ctor(%p, %p, %d, %d, %d) called.\n",
		                   (void *)logger,
		                   (void *)&seed,
		                   *difficulty,
		                   *scenario,
		                   *character);
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
