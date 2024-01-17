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
	int m_ListLength;
	bool m_IsItemRandoValid = false;
	std::vector<int> m_FinalList;
	std::vector<int> m_ForbiddenDependencies;
	std::map<int, int> m_DebugInfo;
	std::mt19937 m_Twister;
	Character character;
	Scenario scenario;
	Difficulty difficulty;

	bool m_HasFoundSeed;
	std::vector<std::string> ItemNames;
	std::map<int, std::vector<int>> DisallowedZoneMap;
	std::vector<int> ZoneIDByItemID;
	std::map<int, std::map<int, std::vector<int>>> ZoneRequiredItems;

	void
	CheckItemValidity(void);
	void ShuffleItems(void);
	bool CheckDependencies(int itemID);
	bool CheckOptionalDependency(std::vector<int> OptionalItems);
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
	    std::map<int, std::vector<int>> &DisallowedZoneMap,
	    std::vector<int> &ZoneIDByItemID,
	    std::map<int, std::map<int, std::vector<int>>> &ZoneRequiredItems);
	~SeedShuffler(void);
	std::vector<int> AsyncShuffle(int threadCount);
};

#endif
