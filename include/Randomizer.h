#ifndef RE2RR_RANDOMIZER_H
#define RE2RR_RANDOMIZER_H

#include "Logging.h"
#include "Types.h"
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

	std::vector<uint8_t> GetItemByID(uint32_t pos);

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
	void ItemPickup(uint32_t *, uint8_t *);
	void ItemPutdown(uint32_t *);
};

#endif
