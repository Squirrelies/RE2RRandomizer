#ifndef RE2RR_RE2RRSEEDGEN_H
#define RE2RR_RE2RRSEEDGEN_H

#include "RE2RRSeedShuffler.h"
#include <algorithm>
#include <future>
#include <map>
#include <string>
#include <vector>

enum RE2RRCharacter
{
	Leon = 0,
	Claire = 1
};

enum RE2RRScenario
{
	A = 0,
	B = 1
};

enum RE2RRDifficulty
{
	Assisted = 0,
	Standard = 1,
	Hardcore = 2
};

class RE2RRSeedGen
{
private:
	bool m_HasFoundSeed;
	int m_ListLength;
	std::vector<int> finalList;
	std::vector<int> ZoneIDByItemID;
	std::vector<std::string> ItemNames;
	std::map<int, std::vector<int>> DisallowedZoneMap;
	std::map<int, std::map<int, std::vector<int>>> ZoneRequiredItems;
	std::vector<std::future<std::vector<int>>> m_Futures;
	std::vector<int> m_AmmoGunpowderList;

	void PrintCheatSheetItemToFile(FILE *file, const int itemId);
	void MixWeapons(RE2RRCharacter, RE2RRScenario, RE2RRDifficulty);
	void WriteDataToFile(RE2RRCharacter, RE2RRScenario, RE2RRDifficulty, bool);

protected:
public:
	void GenerateSeed(RE2RRCharacter, RE2RRScenario, RE2RRDifficulty, bool);
};

#endif
