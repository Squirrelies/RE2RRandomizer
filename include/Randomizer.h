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
	std::vector<int> *seed;
	Difficulty *difficulty;
	Scenario *scenario;
	Character *character;

	std::vector<uint8_t> GetItemByType(uint32_t *);
	void SetItemByGUID(GUID *);

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

	void ResetSeed(std::vector<int> *, Difficulty *, Scenario *, Character *);
	void ItemPickup(uint32_t *, GUID *);
};

std::string GUIDToString(GUID *);

#endif
