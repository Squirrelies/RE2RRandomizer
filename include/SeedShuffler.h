#ifndef RE2RR_SEEDSHUFFLER_H
#define RE2RR_SEEDSHUFFLER_H

#include "Types.h"
#include <algorithm>
#include <ctime>
#include <map>
#include <random>
#include <string>
#include <vector>

class SeedShuffler
{
private:
	uint32_t m_ListLength;
	bool m_IsItemRandoValid = false;
	std::vector<uint32_t> m_FinalList;
	std::vector<uint32_t> m_ForbiddenDependencies;
	std::map<uint32_t, uint32_t> m_DebugInfo;
	std::mt19937 m_Twister;
	Character character;
	Scenario scenario;
	Difficulty difficulty;

	bool m_HasFoundSeed;
	std::vector<std::string> ItemNames;
	std::map<uint32_t, std::vector<uint32_t>> DisallowedZoneMap;
	std::vector<uint32_t> ZoneIDByItemID;
	std::map<uint32_t, std::map<uint32_t, std::vector<uint32_t>>> ZoneRequiredItems;

	void
	CheckItemValidity(void);
	void ShuffleItems(void);
	bool CheckDependencies(uint32_t itemID);
	bool CheckOptionalDependency(std::vector<uint32_t> OptionalItems);
	bool CheckSpadeKeyInArea(void);

protected:
public:
	SeedShuffler(
	    Character character,
	    Scenario scenario,
	    Difficulty difficulty,
	    int listLength,
	    bool &m_HasFoundSeed,
	    std::vector<std::string> &ItemNames,
	    std::map<uint32_t, std::vector<uint32_t>> &DisallowedZoneMap,
	    std::vector<uint32_t> &ZoneIDByItemID,
	    std::map<uint32_t, std::map<uint32_t, std::vector<uint32_t>>> &ZoneRequiredItems);
	~SeedShuffler(void);
	std::vector<uint32_t> AsyncShuffle(int threadCount);
};

#endif
