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
	std::vector<uint32_t> *seed;
	Difficulty *difficulty;
	Scenario *scenario;
	Character *character;

	void RandomizeItem(app_ropeway_gamemastering_InventoryManager_PrimitiveItem *, app_ropeway_gamemastering_InventoryManager_PrimitiveItem *);
	app_ropeway_gamemastering_InventoryManager_PrimitiveItem GetItemByType(uint32_t *);
	void SetItemByGUID(uint32_t *, GUID *);

protected:
public:
	Randomizer(ImmediateLogger *logger)
	{
		this->logger = logger;
		this->seed = nullptr;
		this->difficulty = nullptr;
		this->scenario = nullptr;
		this->character = nullptr;
	}
	~Randomizer()
	{
		this->logger = nullptr;
		this->seed = nullptr;
		this->difficulty = nullptr;
		this->scenario = nullptr;
		this->character = nullptr;
	}

	void ResetSeed(std::vector<uint32_t> *, Difficulty *, Scenario *, Character *);
	void ItemPickup(app_ropeway_gamemastering_InventoryManager_PrimitiveItem *, GUID *);
};

std::string GUIDToString(GUID *);

#endif
