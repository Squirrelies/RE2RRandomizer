#ifndef RE2RR_RANDOMIZER_H
#define RE2RR_RANDOMIZER_H

#include "Logging.h"
#include <stdint.h>
#include <vector>

class Randomizer
{
private:
	ImmediateLogger *logger;
	std::vector<int> *seed;

protected:
public:
	Randomizer(ImmediateLogger *logger)
	{
		this->logger = logger;
		this->seed = nullptr;
	}
	~Randomizer()
	{
		this->logger = nullptr;
		this->seed = nullptr;
	}

	void ResetSeed(std::vector<int> *);
	void ItemPickup(uint32_t *, uint8_t *);
	void ItemPutdown(uint32_t *);
};

#endif
