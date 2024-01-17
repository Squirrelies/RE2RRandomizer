#include "Randomizer.h"

void Randomizer::ResetSeed(std::vector<int> *seed)
{
	this->seed = seed;
}

void Randomizer::ItemPickup(uint32_t *itemId, uint8_t *itemLocation)
{
	logger->LogMessage("[RE2R-R] Randomizer::ItemPickup(%d, %d) called: 0x%x, 0x%x\n", *itemId, *itemLocation, *itemId, *itemLocation);
}

void Randomizer::ItemPutdown(uint32_t *itemId)
{
	logger->LogMessage("[RE2R-R] Randomizer::ItemPutdown(%d) called: 0x%x\n", *itemId, *itemId);
}
