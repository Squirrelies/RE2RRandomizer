#ifndef RE2RR_SEEDGENERATOR_H
#define RE2RR_SEEDGENERATOR_H

#include "Logging.h"
#include "SeedShuffler.h"
#include "Types.h"
#include <algorithm>
#include <future>
#include <map>
#include <string>
#include <vector>

class SeedGenerator
{
private:
	ImmediateLogger *logger;
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
	void MixWeapons(Character, Scenario, Difficulty);
	void CreateCheatSheetVector(Character, Scenario, Difficulty, bool);
	void WriteDataToFile(Character, Scenario, Difficulty, bool);

protected:
public:
	SeedGenerator(ImmediateLogger *logger)
	{
		this->logger = logger;
	}

	~SeedGenerator()
	{
		this->logger = nullptr;
	}

	void GenerateSeed(Character, Scenario, Difficulty, bool);
};

#endif
