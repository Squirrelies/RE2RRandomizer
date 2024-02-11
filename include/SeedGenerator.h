#ifndef RE2RR_SEEDGENERATOR_H
#define RE2RR_SEEDGENERATOR_H

#include "Logging.h"
#include "SeedShuffler.h"
#include "Types.h"
#include <algorithm>
#include <future>
#include <magic_enum.hpp>
#include <map>
#include <string>
#include <vector>

class SeedGenerator
{
private:
	ImmediateLogger *logger;
	bool m_HasFoundSeed;
	uint32_t m_ListLength;
	std::vector<uint32_t> finalList;
	std::vector<std::string> finalCheatSheet;
	std::vector<uint32_t> ZoneIDByItemID;
	std::vector<std::string> ItemNames;
	std::map<uint32_t, std::vector<uint32_t>> DisallowedZoneMap;
	std::map<uint32_t, std::map<uint32_t, std::vector<uint32_t>>> ZoneRequiredItems;
	std::vector<std::future<std::vector<uint32_t>>> m_Futures;
	std::vector<uint32_t> m_AmmoGunpowderList;

	std::unique_ptr<char[]> FormatCharArray(const char *, ...);
	std::unique_ptr<std::string> FormatString(const char *, ...);
	FILE *OpenFile(const char *, const char *);
	std::unique_ptr<std::string> CheatSheetItemToString(const uint32_t);
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
	std::vector<uint32_t> GetSeed(void);
};

#endif
