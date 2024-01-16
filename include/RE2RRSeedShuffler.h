#ifndef RE2RR_RE2RRSEEDSHUFFLER_H
#define RE2RR_RE2RRSEEDSHUFFLER_H

#include "RE2RRSeedGen.h"
#include <map>
#include <random>
#include <vector>

class RE2RRSeedShuffler
{
private:
	bool m_IsItemRandoValid = false;
	std::vector<int> m_FinalList;
	std::vector<int> m_ForbiddenDependencies;
	std::map<int, int> m_DebugInfo;
	std::mt19937 m_Twister;
	RE2RRCharacter character;
	RE2RRScenario scenario;
	RE2RRDifficulty difficulty;

	void CheckItemValidity(void);
	void ShuffleItems(void);
	bool CheckDependencies(int itemID);
	bool CheckOptionalDependency(std::vector<int> OptionalItems);
	bool CheckSpadeKeyInArea(void);

protected:
public:
	RE2RRSeedShuffler(RE2RRCharacter character, RE2RRScenario scenario, RE2RRDifficulty difficulty);
	~RE2RRSeedShuffler(void);
	std::vector<int> AsyncShuffle(int threadCount);
};

#endif
