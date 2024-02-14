#include "SeedShuffler.h"

SeedShuffler::SeedShuffler(
    ImmediateLogger *logger,
    Character character,
    Scenario scenario,
    Difficulty difficulty,
    int listLength,
    bool &m_HasFoundSeed,
    std::vector<std::string> &ItemNames,
    std::map<uint32_t, std::vector<uint32_t>> &DisallowedZoneMap,
    std::vector<uint32_t> &ZoneIDByItemID,
    std::map<uint32_t, std::map<uint32_t, std::vector<uint32_t>>> &ZoneRequiredItems)
{
	this->logger = logger;
	this->character = character;
	this->scenario = scenario;
	this->difficulty = difficulty;
	this->m_ListLength = listLength;
	this->m_HasFoundSeed = m_HasFoundSeed;
	this->ItemNames = ItemNames;
	this->DisallowedZoneMap = DisallowedZoneMap;
	this->ZoneIDByItemID = ZoneIDByItemID;
	this->ZoneRequiredItems = ZoneRequiredItems;
}

SeedShuffler::~SeedShuffler()
{
	m_FinalList.clear();
	m_ForbiddenDependencies.clear();
	m_DebugInfo.clear();
	this->logger = nullptr;
}

void SeedShuffler::ShuffleItems()
{
	std::vector<uint32_t> UniqueIDList;

	m_FinalList.clear();

	uint32_t rookpos = 5000;

	if (character == Character::Leon)
	{
		rookpos = 148 + (rand() % 4);
	}

	// tbar and sewer key
	uint32_t tbarpos = 158 + (rand() % 15);
	uint32_t sewerkeypos = 158 + (rand() % 15);

	while (tbarpos == 170 || sewerkeypos == 170 || tbarpos == sewerkeypos)
	{
		tbarpos = 158 + (rand() % 15);
		sewerkeypos = 158 + (rand() % 15);
	}

	// chip
	uint32_t chippos = 195 + (rand() % 5);

	// Unique Item IDs
	for (uint32_t i = 0; i < m_ListLength; ++i)
	{

		bool exceptions;

		if (scenario == Scenario::B)
		{
			exceptions = (i != 204 && i != 120 && i != 208 && i != 75); // parking key exception and now 3rd level chip and boxed electronic part, and dispersal cartridge

			if (character == Character::Leon)
			{
				exceptions = exceptions && (i != 261 && i != 262 && i != 263 && i != 264 && i != 265); // claire b scenario extras
			}
		}
		else
		{
			exceptions = (i != 204 && i != 120 && i != 208 && i != 75 && i != 53); // spade key added for A scenario

			for (uint32_t z = 256; z < 266; ++z)
			{
				exceptions = exceptions && (i != z); // all the b scenario extras
			}
		}

		if (difficulty != Difficulty::Hardcore) // cut the hardcore items if not in hardcore
		{
			exceptions = exceptions && (i != 251 && i != 252 && i != 253 && i != 254 && i != 255);
		}

		if (exceptions)
		{

			if (i != tbarpos && i != sewerkeypos && i != chippos && i != rookpos)
			{

				if ((difficulty == Difficulty::Hardcore && i != 57 && i != 180 && i != 225) || difficulty != Difficulty::Hardcore)
				{

					if (character == Character::Claire)
					{

						if (scenario == Scenario::B)
						{

							UniqueIDList.push_back(i);
						}
						else
						{
							// extra claire exceptions
							if (i != 144 && i != 145 && i != 146 && i != 147)
							{
								UniqueIDList.push_back(i);
							}
						}
					}
					else
					{
						UniqueIDList.push_back(i);
					}
				}
			}
		}

		m_FinalList.push_back(i);
	}

	// doing this a new way fuck it

	std::vector<uint32_t> KeyItems;
	std::vector<uint32_t> NonKeyItems;

	for (uint32_t i = 0; i < m_ListLength; ++i)
	{

		bool exceptions;

		if (scenario == Scenario::B)
		{
			exceptions = (i != 204 && i != 120 && i != 208 && i != 75); // parking key exception and now 3rd level chip and boxed electronic part + dispersal cartridge

			if (character == Character::Leon)
			{
				exceptions = exceptions && (i != 261 && i != 262 && i != 263 && i != 264 && i != 265); // claire b scenario extras
			}
		}
		else
		{
			exceptions = (i != 204 && i != 120 && i != 208 && i != 75 && i != 53); // spade key added for A scenario

			for (uint32_t z = 256; z < 266; ++z)
			{
				exceptions = exceptions && (i != z); // all the b scenario extras
			}
		}

		if (difficulty != Difficulty::Hardcore) // cut the hardcore items if not in hardcore
		{
			exceptions = exceptions && (i != 251 && i != 252 && i != 253 && i != 254 && i != 255);
		}

		if (exceptions)
		{

			if ((difficulty == Difficulty::Hardcore && i != 57 && i != 180 && i != 225) || difficulty != Difficulty::Hardcore)
			{

				// tbar, chip and sewer key exceptions
				if (i != 167 && i != 170 && i != 199)
				{

					if (character == Character::Claire)
					{
						// extra claire exceptions
						if ((i != 144 && i != 145 && i != 146 && i != 147) || scenario == Scenario::B)
						{

							if (ItemNames[i] != "UNUSED")
							{

								std::vector<uint32_t> DisZones = DisallowedZoneMap[i];

								if (DisZones.size() > 0)
								{
									KeyItems.push_back(i);
								}
								else
								{
									NonKeyItems.push_back(i);
								}
							}
						}
					}
					else
					{

						if (i != 151) // rook piece exception
						{

							if (ItemNames[i] != "UNUSED")
							{

								std::vector<uint32_t> DisZones = DisallowedZoneMap[i];

								if (DisZones.size() > 0)
								{
									KeyItems.push_back(i);
								}
								else
								{
									NonKeyItems.push_back(i);
								}
							}
						}
					}
				}
			}
		}
	}

	// tbar sewer key and chip
	m_FinalList[tbarpos] = 167;
	m_FinalList[sewerkeypos] = 170;
	m_FinalList[chippos] = 199;

	if (character == Character::Leon)
	{
		m_FinalList[rookpos] = 151;
	}

	if (difficulty != Difficulty::Hardcore) // cut the hardcore items if not in hardcore
	{
		m_FinalList[251] = 251;
		m_FinalList[252] = 252;
		m_FinalList[253] = 253;
		m_FinalList[254] = 254;
		m_FinalList[255] = 255;
	}

	if (scenario == Scenario::A)
	{

		for (uint32_t i = 256; i < 266; ++i)
		{
			m_FinalList[i] = i;
		}
	}
	else if (character == Character::Leon)
	{
		for (uint32_t i = 261; i < 266; ++i)
		{
			m_FinalList[i] = i;
		}
	}

	while (KeyItems.empty() == false)
	{

		uint32_t randomkeyitem = std::rand() % KeyItems.size();

		uint32_t randomnumber = std::rand() % UniqueIDList.size();

		uint32_t NewItemZone = ZoneIDByItemID[UniqueIDList[randomnumber]];

		std::vector<uint32_t> DisZones = DisallowedZoneMap[KeyItems[randomkeyitem]];

		bool isvalid = true;

		for (size_t q = 0; q < DisZones.size(); ++q)
		{

			if (DisZones[q] == NewItemZone)
			{
				isvalid = false;
			}
		}

		if (isvalid == true)
		{
			m_FinalList[UniqueIDList[randomnumber]] = KeyItems[randomkeyitem];
			KeyItems.erase(KeyItems.begin() + randomkeyitem);
			UniqueIDList.erase(UniqueIDList.begin() + randomnumber);
		}
		else
		{
			/* //removed because I have a NEED FOR SPEED
			//check it's possible at all

			bool isthereavalidslot = false;

			for (uint32_t i = 0; i < UniqueIDList.size(); ++i)
			{

			    uint32_t testzone = ZoneIDByItemID[UniqueIDList[i]];

			    if (std::find(DisZones.begin(), DisZones.end(), testzone) == DisZones.end())
			    {
			        isthereavalidslot = true;
			    }

			}

			if (isthereavalidslot == false)
			{
			    //AddToConsoleLog("VALID SLOT ERROR");
			}
			*/
		}
	}

	while (NonKeyItems.empty() == false)
	{

		uint32_t randomitem = std::rand() % NonKeyItems.size();

		uint32_t randomnumber = std::rand() % UniqueIDList.size();

		m_FinalList[UniqueIDList[randomnumber]] = NonKeyItems[randomitem];
		NonKeyItems.erase(NonKeyItems.begin() + randomitem);
		UniqueIDList.erase(UniqueIDList.begin() + randomnumber);
	}

	// debug test seed
	/*
	ifstream debugtestfile ("inputtestseed.txt");

	if (debugtestfile.is_open())
	{

	    //AddToConsoleLog("DEBUG SEED TEST!");

	    string line;

	    uint32_t counter = 0;

	    while (getline(debugtestfile, line))
	    {
	        m_FinalList[counter] = stoi(line);
	        //cout << line << '\n';
	        counter++;
	    }

	    debugtestfile.close();

	}
	*/
	// end debug test
}

std::vector<uint32_t> SeedShuffler::AsyncShuffle(int threadCount)
{
	try
	{
		// AddToConsoleLog("FECK");

		// std::mt19937 mt_rand(time(0) + threadCount);
		srand(time(0) + threadCount);

		int counter = 0;

		// vanilla shuffle
		while (m_IsItemRandoValid == false)
		{

			if (m_HasFoundSeed == true) // a thread has already found the seed, abort
			{
				m_FinalList.clear();
				return m_FinalList;
			}

			if (counter > 1000)
			{
				counter = 0;
				/*
				m_FinalList.clear();
				return m_FinalList;
				*/
				// AddToConsoleLog(" .");
			}

			ShuffleItems();

			CheckItemValidity();

			counter++;
		}

		m_HasFoundSeed = true;
	}
	catch (std::exception &ex)
	{
		logger->LogMessage("Exception thrown: %s\n", ex.what());
		m_FinalList.clear();
	}

	return m_FinalList;
}

bool SeedShuffler::CheckSpadeKeyInArea()
{

	bool spadeinzonetwo = false;

	for (uint32_t i = 8; i < 20; ++i)
	{

		if (m_FinalList[i] == 53)
		{
			spadeinzonetwo = true;
		}
	}

	for (uint32_t i = 46; i < 58; ++i)
	{

		if (scenario == Scenario::B)
		{
			if (i == 57) // skip over 57 in B scenario
			{
				continue;
			}
		}

		if (m_FinalList[i] == 53)
		{
			spadeinzonetwo = true;
		}
	}

	for (uint32_t i = 59; i < 64; ++i)
	{

		if (m_FinalList[i] == 53)
		{
			spadeinzonetwo = true;
		}
	}

	return spadeinzonetwo;
}

void SeedShuffler::CheckItemValidity()
{

	// special situations first

	if (scenario == Scenario::A) // a scenario only
	{

		// is there a knife or a spade key in zone 1?
		bool knifeinzoneone = false;
		bool spadekeyinzoneone = false;

		for (uint32_t i = 0; i < 5; ++i)
		{
			if (m_FinalList[i] == 4 || m_FinalList[i] == 20 || m_FinalList[i] == 60 || m_FinalList[i] == 135 || m_FinalList[i] == 155 || m_FinalList[i] == 190 || m_FinalList[i] == 196 || m_FinalList[i] == 217 || m_FinalList[i] == 240)
			{
				knifeinzoneone = true;
			}

			if (m_FinalList[i] == 53)
			{
				spadekeyinzoneone = true;
			}
		}

		// stuck in zone 1
		if (knifeinzoneone == false && spadekeyinzoneone == false)
		{
			return;
		}

		// check for spade key soft-lock if we can get into zone 3 with a knife
		if (knifeinzoneone == true)
		{

			if (CheckSpadeKeyInArea() == false)
			{
				return;
			}
		}

		bool medallionedgecase = false;

		// check if there's a medallion in the east office to prevent black screen of doom in A scenario helicopter cutscene
		for (uint32_t i = 37; i < 44; ++i)
		{
			if (m_FinalList[i] == 2 || m_FinalList[i] == 58 || m_FinalList[i] == 63)
			{
				medallionedgecase = true;
			}
		}

		if (medallionedgecase == false)
		{
			return;
		}
	}
	else
	{

		// If fuse is available to get to main hall then spade key MUST be in spade key zone.

		std::vector<uint32_t> earlylocations;

		for (uint32_t i = 64; i < 72; ++i)
		{
			earlylocations.push_back(i);
		}

		earlylocations.push_back(257);
		earlylocations.push_back(258);

		if (character == Character::Leon)
		{
			for (uint32_t i = 134; i < 141; ++i)
			{
				earlylocations.push_back(i);
			}
		}
		else
		{
			earlylocations.push_back(144);
			earlylocations.push_back(145);

			for (uint32_t i = 261; i < 266; ++i)
			{
				earlylocations.push_back(i);
			}
		}

		bool fuseaccess = false;
		bool boltcutteraccess = false;
		bool squarecrankaccess = false;
		bool redbookaccess = false;
		bool statuearmaccess = false;

		for (auto itr = earlylocations.begin(); itr != earlylocations.end(); ++itr)
		{

			if (m_FinalList[(*itr)] == 139) // fuse = 139
			{
				fuseaccess = true;
			}

			if (m_FinalList[(*itr)] == 71) // bolt cutters
			{
				boltcutteraccess = true;
			}

			if (character == Character::Leon)
			{
				if (m_FinalList[(*itr)] == 119) // square crank
				{
					squarecrankaccess = true;
				}
			}
			else
			{
				if (m_FinalList[(*itr)] == 147) // square crank
				{
					squarecrankaccess = true;
				}
			}

			if (m_FinalList[(*itr)] == 61) // red book
			{
				redbookaccess = true;
			}

			if (m_FinalList[(*itr)] == 67) // statue arm
			{
				statuearmaccess = true;
			}
		}

		if (fuseaccess == true)
		{
			if (CheckSpadeKeyInArea() == false)
			{
				return;
			}
		}
		else
		{
			if (boltcutteraccess == true || squarecrankaccess == true || (redbookaccess == true && statuearmaccess == true))
			{
				if (CheckSpadeKeyInArea() == false)
				{
					return;
				}
			}
		}

		/*
		Bolt cutters need to be found and cutscene triggered before Leon can go down the ladder (or anyone can get near the area without causing a cutscene soft-lock.)
		If one of the items in the guardhouse does not lead to a medallion this issue will happen.
		*/

		bool boltcuttersOK = false;

		if (m_FinalList[4] == 2 || m_FinalList[4] == 58 || m_FinalList[4] == 63)
		{
			boltcuttersOK = true;
		}

		if (m_FinalList[43] == 2 || m_FinalList[43] == 58 || m_FinalList[43] == 63)
		{
			boltcuttersOK = true;
		}

		if (m_FinalList[259] == 2 || m_FinalList[259] == 58 || m_FinalList[259] == 63)
		{
			boltcuttersOK = true;
		}

		if (m_FinalList[260] == 2 || m_FinalList[260] == 58 || m_FinalList[260] == 63)
		{
			boltcuttersOK = true;
		}

		if (boltcuttersOK == false)
		{
			return;
		}
	}

	if (character == Character::Leon)
	{

		// can we use the rook plug or the t-bar valve to get out of the sewer access area TBAR REMOVED FROM HERE
		bool isrookinzone = false;

		for (uint32_t i = 148; i < 152; ++i)
		{

			if (m_FinalList[i] == 151)
			{
				isrookinzone = true;
			}
		}

		if (isrookinzone == false /* && istbarinzone == false*/)
		{
			m_DebugInfo[-1]++;
			return;
		}
	}

	bool issewerkeyinzone = false;
	bool istbarinzone = false;

	// can we find t-bar and sewer key to get out of the sewers?
	for (uint32_t i = 158; i < 173; ++i)
	{

		if (i != 170) // skip this one
		{

			if (m_FinalList[i] == 170)
			{
				issewerkeyinzone = true;
			}

			if (m_FinalList[i] == 167)
			{
				istbarinzone = true;
			}
		}
	}

	// both need to be in this area
	if (issewerkeyinzone == false || istbarinzone == false)
	{
		m_DebugInfo[-2]++;
		return;
	}

	// general chip
	bool ischipinzone = false;

	for (uint32_t i = 195; i < 200; ++i)
	{

		if (m_FinalList[i] == 199)
		{
			ischipinzone = true;
		}
	}

	if (ischipinzone == false)
	{
		m_DebugInfo[-3]++;
		return;
	}

	// joint plug
	bool ispluginzone = false;

	if (character == Character::Leon)
	{

		for (uint32_t i = 244; i < 247; ++i)
		{

			if (m_FinalList[i] == 246)
			{
				ispluginzone = true;
			}
		}
	}
	else
	{
		// claire joint plug check

		if (m_FinalList[244] == 246 || m_FinalList[246] == 246 || m_FinalList[119] == 246)
		{
			ispluginzone = true;
		}
	}

	if (ispluginzone == false)
	{
		m_DebugInfo[-4]++;
		return;
	}

	// now we check dependencies
	for (uint32_t i = 0; i < m_ListLength; ++i)
	{

		if (CheckDependencies(i) == false)
		{
			m_ForbiddenDependencies.clear();
			m_DebugInfo[i]++;
			return;
		}
	}

	m_IsItemRandoValid = true;
}

bool SeedShuffler::CheckDependencies(uint32_t itemID)
{

	uint32_t ItemPos = std::find(m_FinalList.begin(), m_FinalList.end(), itemID) - m_FinalList.begin();

	uint32_t NewItemZone = ZoneIDByItemID[ItemPos];

	std::vector<uint32_t> ReqItems = ZoneRequiredItems[NewItemZone][0];

	std::vector<std::vector<uint32_t>> OptionalSets;

	uint32_t i = 1;

	while (true)
	{

		if (ZoneRequiredItems[NewItemZone][i].empty())
		{
			break;
		}
		else
		{
			OptionalSets.push_back(ZoneRequiredItems[NewItemZone][i]);
		}

		i++;
	}

	m_ForbiddenDependencies.push_back(itemID);

	// all of these are mandatory
	for (size_t q = 0; q < ReqItems.size(); ++q)
	{

		for (size_t z = 0; z < m_ForbiddenDependencies.size(); ++z)
		{

			if (ReqItems[q] == m_ForbiddenDependencies[z])
			{
				return false;
			}
		}

		if (CheckDependencies(ReqItems[q]) == false)
		{
			return false;
		}
	}

	// now we do optional sets, if there are any
	if (OptionalSets.empty() == false)
	{

		while (OptionalSets.empty() == false)
		{

			ReqItems = OptionalSets[0];

			if (CheckOptionalDependency(ReqItems))
			{
				m_ForbiddenDependencies.pop_back();
				return true;
			}

			OptionalSets.erase(OptionalSets.begin());
		}

		// we couldn't find a valid optional set, and we gotta have at least one
		return false;
	}

	// otherwise we are done
	m_ForbiddenDependencies.pop_back();
	return true;
}

bool SeedShuffler::CheckOptionalDependency(std::vector<uint32_t> OptionalItems)
{
	for (size_t q = 0; q < OptionalItems.size(); ++q)
	{

		for (size_t z = 0; z < m_ForbiddenDependencies.size(); ++z)
		{

			if (OptionalItems[q] == m_ForbiddenDependencies[z])
			{
				return false;
			}
		}

		if (CheckDependencies(OptionalItems[q]) == false)
		{
			return false;
		}
	}

	return true;
}
