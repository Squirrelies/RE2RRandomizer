#include "Randomizer.h"
/*
    static std::unordered_map<std::string, std::string> floorIdsToName;
    static std::unordered_map<std::string, std::string> mapIdsToName;
    static std::unordered_map<std::string, std::string> mapPartIdsToName;
*/
std::unordered_map<std::string, std::string> Randomizer::floorIdToName =
    {
        {"NONE", ""},
        {"RPD_A", "RPD 1st Floor"},
        {"RPD_B", "RPD 2nd Floor"},
        {"RPD_C", "RPD 3rd Floor"},
        {"RPD_E", "RPD B1 Floor"},
        {"WaterPlant_A", "Water Treatment Ground Floor"},
        {"WaterPlant_B", "Water Treatment B1 Floor"},
        {"WaterPlant_C", "Water Treatment B2 Floor"},
        {"WasteWater_A", "Sewer B1"},
        {"WasteWater_B", "Sewer B2"},
        {"WasteWater_C", "Sewer B3"},
        {"CityArea_A", "Raccoon City A"},
        {"CityArea_B", "Raccoon City B"},
        {"Laboratory_A", "NEST A"}};

std::unordered_map<std::string, std::string> Randomizer::mapIdToName =
    {
        {"st1_411_0", "Gas Station"},
        {"st1_603_0", "Hallway 2"},
        {"st1_605_0", ""},
        {"st1_606_0", ""},
        {"st1_609_0", ""},
        {"st1_611_0", "Sewer 4"},
        {"st1_614_0", "Sewer 5"},
        {"st1_620_0", "Sewer 1"},
        {"st1_621_0", "Sewer 2"},
        {"st1_623_0", ""},
        {"st1_630_0", ""},
        {"st1_631_0", "Sewer Entrance"},
        {"st1_632_0", ""},
        {"st3_600_0", "Hallway 1"},
        {"st3_603_0", ""},
        {"st3_604_0", "Sewer 3"},
        {"st3_611_0", "Sewer 4"},
        {"st3_612_0", ""},
        {"st3_613_0", "Sewer 6"},
        {"st3_614_0", "Sewer 5"},
        {"st3_615_0", "Treatment Room"},
        {"st3_616_0", ""},
        {"st3_617_0", "Sewer 8"},
        {"st3_620_0", "Sewer 1"},
        {"st3_621_0", "Sewer 2"},
        {"st3_622_0", "Allegator Encounter"},
        {"st3_623_0", "Organ Trail"},
        {"st3_624_0", "Supplies Storage Entrance"},
        {"st3_625_0", "Supplies Storage Room"},
        {"st3_627_0", "Sewer 7"},
        {"st3_630_0", "Outside Cable Car"},
        {"st3_632_0", "Sewer Save Room"},
        {"st3_635_0", "Birkin 2 Fight"},
        {"st3_638_0", "Garbage Room (Ada/Sherry)"},
        {"st3_640_0", "Incinerator"},
        {"st3_641_0", "Garbage Room"},
        {"st3_642_0", "Incinerator Exit"},
        {"st4_101_0", "Main Hall"},
        {"st4_201_0", "Entrance"},
        {"st4_202_0", "Reception"},
        {"st4_204_0", ""},
        {"st4_206_0", "Operations Room"},
        {"st4_207_0", "Safety Deposit Room"},
        {"st4_208_0", "West Office"},
        {"st4_209_0", "West Save Room"},
        {"st4_211_0", "Boiler Room Path"},
        {"st4_212_0", "Boiler Room"},
        {"st4_214_0", "West Hallway Outer 1"},
        {"st4_215_0", "West Hallway Outer 2"},
        {"st4_216_0", "West Hallway Inner 2"},
        {"st4_217_0", "West Hallway Inner 1"},
        {"st4_301_0", ""},
        {"st4_303_0", "East Hallway Outer 1"},
        {"st4_304_0", "East Office"},
        {"st4_305_0", "East Hallway Closet"},
        {"st4_306_0", "Press Room"},
        {"st4_307_0", "Interrogation Room"},
        {"st4_308_0", "Observation Room"},
        {"st4_309_0", "East Save Room"},
        {"st4_311_0", "Women's Bathroom"},
        {"st4_312_0", "Watchman's Room"},
        {"st4_313_0", "East Hallway Inner"},
        {"st4_314_0", "East Hallway Outer 2"},
        {"st4_402_0", "Women's Locker Room"},
        {"st4_403_0", "Men's Locker Room"},
        {"st4_404_0", "S.T.A.R.S. Office"},
        {"st4_407_0", "Lounge"},
        {"st4_408_0", "Library"},
        {"st4_409_0", "Linen Room"},
        {"st4_411_0", "West Hallway (Staircase)"},
        {"st4_412_0", "West Hallway (S.T.A.R.S. Office)"},
        {"st4_501_0", "Waiting Room"},
        {"st4_502_0", "East Hallway"},
        {"st4_503_0", "Art Room"},
        {"st4_504_0", ""},
        {"st4_506_0", ""},
        {"st4_507_0", "Roof"},
        {"st4_508_0", "East Staircase"},
        {"st4_602_0", "Clock Tower"},
        {"st4_603_0", "West Hallway Outer 3"},
        {"st4_604_0", "West Storage Room"},
        {"st4_607_0", "Balcony"},
        {"st4_608_0", "East Storage Room"},
        {"st4_609_0", "Spade Key Room"},
        {"st4_610_0", "East Storage Passage"},
        {"st4_701_0", "Hallway"},
        {"st4_702_0", "Morgue"},
        {"st4_703_0", "Generator Room"},
        {"st4_704_0", "Firing Range"},
        {"st4_708_0", "Parking Lot"},
        {"st4_710_0", "Kennel"},
        {"st4_713_0", "Jail Intake"},
        {"st4_714_0", "Jail"},
        {"st4_717_0", "Secret Save Room"},
        {"st4_750_0", "Underground Stairs"},
        {"st4_751_0", "Machinery Room"},
        {"st4_754_0", ""},
        {"st4_755_0", "Secret Save Room Elevator"},
        {"st5_101_0", "Cable Car Platform"},
        {"st5_102_0", "Reception"},
        {"st5_103_0", "Security Room"},
        {"st5_104_0", "Cafeteria"},
        {"st5_105_0", "Air Vent"},
        {"st5_106_0", "Nap Room"},
        {"st5_111_0", "Main Shaft"},
        {"st5_121_0", "Lobby Save Room"},
        {"st5_122_0", ""},
        {"st5_122_1", "Presentation Room"},
        {"st5_122_2", "Greenhouse Control Room"},
        {"st5_123_0", "Weed Hallway"},
        {"st5_124_0", "Drug Testing Lab"},
        {"st5_125_0", "Storage Room"},
        {"st5_126_0", ""},
        {"st5_127_0", "Lounge"},
        {"st5_128_0", ""},
        {"st5_129_0", "Maintenance Room"},
        {"st5_131_0", ""},
        {"st5_132_0", ""},
        {"st5_133_0", ""},
        {"st5_134_0", ""},
        {"st5_201_0", ""},
        {"st5_202_0", ""},
        {"st5_203_0", ""},
        {"st5_204_0", ""},
        {"st5_211_0", ""},
        {"st5_212_0", ""},
        {"st5_223_0", ""},
        {"st8_408_0", ""}};

std::unordered_map<std::string, std::string> Randomizer::mapPartsIdToName =
    {
        {"", ""}};

const std::string &Randomizer::GetFloorNameById(const std::string &key)
{
	if (floorIdToName.contains(key))
		return floorIdToName[key];
	else
		return key;
}

const std::string &Randomizer::GetMapNameById(const std::string &key)
{
	if (mapIdToName.contains(key))
		return mapIdToName[key];
	else
		return key;
}

const std::string &Randomizer::GetMapPartsNameById(const std::string &key)
{
	if (mapPartsIdToName.contains(key))
		return mapPartsIdToName[key];
	else
		return key;
}
