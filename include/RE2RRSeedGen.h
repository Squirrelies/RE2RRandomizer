#ifndef RE2RR_RE2RRSEEDGEN_H
#define RE2RR_RE2RRSEEDGEN_H

#include "RE2RRTypes.h"

#include "RE2RRSeedShuffler.h"
#include <algorithm>
#include <future>
#include <map>
#include <string>
#include <vector>

class RE2RRSeedGen
{
private:
	bool m_HasFoundSeed;
	int m_ListLength;
	std::vector<int> finalList;
	std::vector<std::string> finalCheatSheet;
	std::vector<int> ZoneIDByItemID;
	std::vector<std::string> ItemNames;
	std::map<int, std::vector<int>> DisallowedZoneMap;
	std::map<int, std::map<int, std::vector<int>>> ZoneRequiredItems;
	std::vector<std::future<std::vector<int>>> m_Futures;
	std::vector<int> m_AmmoGunpowderList;

	std::unique_ptr<char[]> FormatCharArray(const char *, ...);
	std::unique_ptr<std::string> FormatString(const char *, ...);
	FILE *OpenFile(const char *, const char *);
	std::unique_ptr<std::string> CheatSheetItemToString(const int);
	std::vector<int> GetSeed(void);
	std::vector<std::string> GetCheatSheet(void);
	void PrintCheatSheetItemToFile(FILE *, const int);
	void MixWeapons(RE2RRCharacter, RE2RRScenario, RE2RRDifficulty);
	void CreateCheatSheetVector(RE2RRCharacter, RE2RRScenario, RE2RRDifficulty, bool);
	void WriteDataToFile(RE2RRCharacter, RE2RRScenario, RE2RRDifficulty, bool);

protected:
public:
	void GenerateSeed(RE2RRCharacter, RE2RRScenario, RE2RRDifficulty, bool);
};

#endif
