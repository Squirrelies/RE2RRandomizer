#include "Randomizer.h"

std::unordered_map<RE2RREnums::FloorID, std::string> Randomizer::floorIdToName =
    {
        {RE2RREnums::FloorID::None, ""},
        {RE2RREnums::FloorID::RPD_A, "RPD 1st Floor"},
        {RE2RREnums::FloorID::RPD_B, "RPD 2nd Floor"},
        {RE2RREnums::FloorID::RPD_C, "RPD 3rd Floor"},
        {RE2RREnums::FloorID::RPD_D, "RPD 4th Floor"},
        {RE2RREnums::FloorID::RPD_E, "RPD B1 Floor"},
        {RE2RREnums::FloorID::WaterPlant_A, "Water Treatment Upper"},
        {RE2RREnums::FloorID::WaterPlant_B, "Water Treatment Middle"},
        {RE2RREnums::FloorID::WaterPlant_C, "Water Treatment Lower"},
        {RE2RREnums::FloorID::OrphanAsylum_A, "Orphanage 1st Floor"},
        {RE2RREnums::FloorID::OrphanAsylum_B, "Orphanage 2nd Floor"},
        {RE2RREnums::FloorID::OrphanAsylum_C, "Orphanage B1 Floor"},
        {RE2RREnums::FloorID::WasteWater_A, "Sewer Upper"},
        {RE2RREnums::FloorID::WasteWater_B, "Sewer Middle"},
        {RE2RREnums::FloorID::WasteWater_C, "Sewer Lower"},
        {RE2RREnums::FloorID::CityArea_A, "Raccoon City A"},
        {RE2RREnums::FloorID::CityArea_B, "Raccoon City B"}, // Sewer Entrance area
        {RE2RREnums::FloorID::Laboratory_A, "NEST B1"},
        {RE2RREnums::FloorID::Laboratory_B, "NEST B2"}};

std::unordered_map<RE2RREnums::MapID, std::string> Randomizer::mapIdToName =
    {
        {RE2RREnums::MapID::st1_411_0, "Gas Station"},
        {RE2RREnums::MapID::st1_601_0, "Front Hall"},
        {RE2RREnums::MapID::st1_602_0, "Hallway"},
        {RE2RREnums::MapID::st1_603_0, "Director's Room"},
        {RE2RREnums::MapID::st1_605_0, "Bedroom"},
        {RE2RREnums::MapID::st1_606_0, "Nursery"},
        {RE2RREnums::MapID::st1_607_0, "Bedroom Hallway"},
        {RE2RREnums::MapID::st1_608_0, "Medical Observation Room"},
        {RE2RREnums::MapID::st1_609_0, "Bathroom"},
        {RE2RREnums::MapID::st1_610_0, "Underground Passage"},
        {RE2RREnums::MapID::st1_611_0, "Sewer (1-611)"},
        {RE2RREnums::MapID::st1_612_0, "Sewer (1-612)"},
        {RE2RREnums::MapID::st1_613_0, "Sewer (1-613)"},
        {RE2RREnums::MapID::st1_614_0, "Sewer (1-614)"},
        {RE2RREnums::MapID::st1_620_0, "Sewer (1-620)"},
        {RE2RREnums::MapID::st1_621_0, "Sewer (1-621)"},
        {RE2RREnums::MapID::st1_622_0, "Alligator Fight"},
        {RE2RREnums::MapID::st1_623_0, "Alligator Aftermath"},
        {RE2RREnums::MapID::st1_630_0, "Kendo's Shop/Walkway"},
        {RE2RREnums::MapID::st1_631_0, "Sewer Entrance"},
        {RE2RREnums::MapID::st1_632_0, "Orphanage Approach"},
        {RE2RREnums::MapID::st3_600_0, "Hallway"},
        {RE2RREnums::MapID::st3_603_0, "Sewer (3-603)"},
        {RE2RREnums::MapID::st3_604_0, "Sewer (3-604)"},
        {RE2RREnums::MapID::st3_611_0, "Sewer (3-611)"},
        {RE2RREnums::MapID::st3_612_0, "Workroom"},
        {RE2RREnums::MapID::st3_613_0, "Sewer (3-613)"},
        {RE2RREnums::MapID::st3_614_0, "Sewer (3-614)"},
        {RE2RREnums::MapID::st3_615_0, "Treatment Room"},
        {RE2RREnums::MapID::st3_616_0, "Office (Save)"},
        {RE2RREnums::MapID::st3_617_0, "Sewer (3-617)"},
        {RE2RREnums::MapID::st3_620_0, "Sewer (3-620)"},
        {RE2RREnums::MapID::st3_621_0, "Sewer (3-621)"},
        {RE2RREnums::MapID::st3_622_0, ""}, // ???
        {RE2RREnums::MapID::st3_623_0, "Organ Trail"},
        {RE2RREnums::MapID::st3_624_0, "Supplies Storage Entrance"},
        {RE2RREnums::MapID::st3_625_0, "Supplies Storage Room"},
        {RE2RREnums::MapID::st3_627_0, "Sewer (3-627)"},
        {RE2RREnums::MapID::st3_630_0, "Cable Car/Control Room"},
        {RE2RREnums::MapID::st3_632_0, "Monitor Room (Save)"},
        {RE2RREnums::MapID::st3_635_0, "Proposed Water Purification Room"},
        {RE2RREnums::MapID::st3_638_0, "Garbage Room"},
        {RE2RREnums::MapID::st3_640_0, "Incinerator"},
        {RE2RREnums::MapID::st3_641_0, "Garbage Room"},
        {RE2RREnums::MapID::st3_642_0, "Incinerator Exit"},
        {RE2RREnums::MapID::st4_101_0, "Main Hall"},
        {RE2RREnums::MapID::st4_201_0, "Entrance"},
        {RE2RREnums::MapID::st4_202_0, "Reception"},
        {RE2RREnums::MapID::st4_204_0, "Records Room"},
        {RE2RREnums::MapID::st4_206_0, "Operations Room"},
        {RE2RREnums::MapID::st4_207_0, "Safety Deposit Room"},
        {RE2RREnums::MapID::st4_208_0, "West Office"},
        {RE2RREnums::MapID::st4_209_0, "Dark Room (Save)"},
        {RE2RREnums::MapID::st4_211_0, "Boiler Room Path"},
        {RE2RREnums::MapID::st4_212_0, "Boiler Room"},
        {RE2RREnums::MapID::st4_214_0, "West Hallway (4-214)"},
        {RE2RREnums::MapID::st4_215_0, "West Hallway (4-215)"},
        {RE2RREnums::MapID::st4_216_0, "West Hallway (4-216)"},
        {RE2RREnums::MapID::st4_217_0, "West Hallway (4-217)"},
        {RE2RREnums::MapID::st4_301_0, "East Courtyard"},
        {RE2RREnums::MapID::st4_303_0, "East Hallway (4-303)"},
        {RE2RREnums::MapID::st4_304_0, "East Office"},
        {RE2RREnums::MapID::st4_305_0, "East Hallway Closet"},
        {RE2RREnums::MapID::st4_306_0, "Press Room"},
        {RE2RREnums::MapID::st4_307_0, "Interrogation Room"},
        {RE2RREnums::MapID::st4_308_0, "Observation Room"},
        {RE2RREnums::MapID::st4_309_0, "East Break Room (Save)"},
        {RE2RREnums::MapID::st4_311_0, "Women's Bathroom"},
        {RE2RREnums::MapID::st4_312_0, "Watchman's Room"},
        {RE2RREnums::MapID::st4_313_0, "East Hallway (4-313)"},
        {RE2RREnums::MapID::st4_314_0, "East Hallway (4-314)"},
        {RE2RREnums::MapID::st4_402_0, "Women's Locker Room"},
        {RE2RREnums::MapID::st4_403_0, "Men's Locker Room"},
        {RE2RREnums::MapID::st4_404_0, "S.T.A.R.S. Office"},
        {RE2RREnums::MapID::st4_407_0, "Lounge"},
        {RE2RREnums::MapID::st4_408_0, "Library"},
        {RE2RREnums::MapID::st4_409_0, "Linen Room"},
        {RE2RREnums::MapID::st4_411_0, "West Hallway (Staircase)"},
        {RE2RREnums::MapID::st4_412_0, "West Hallway (S.T.A.R.S. Office)"},
        {RE2RREnums::MapID::st4_501_0, "Waiting Room"},
        {RE2RREnums::MapID::st4_502_0, "East Hallway (4-502)"},
        {RE2RREnums::MapID::st4_503_0, "Art Room"},
        {RE2RREnums::MapID::st4_504_0, "Chief's Office"},
        {RE2RREnums::MapID::st4_505_0, "Private Collection Hallway"},
        {RE2RREnums::MapID::st4_506_0, "Private Collection Room"},
        {RE2RREnums::MapID::st4_507_0, "Roof"},
        {RE2RREnums::MapID::st4_508_0, "East Staircase"},
        {RE2RREnums::MapID::st4_602_0, "Clock Tower"},
        {RE2RREnums::MapID::st4_603_0, "West Hallway (4-603)"},
        {RE2RREnums::MapID::st4_604_0, "West Storage Room"},
        {RE2RREnums::MapID::st4_607_0, "Balcony"},
        {RE2RREnums::MapID::st4_608_0, "East Storage Room"},
        {RE2RREnums::MapID::st4_609_0, "Spade Key Room"},
        {RE2RREnums::MapID::st4_610_0, "East Storage Passage"},
        {RE2RREnums::MapID::st4_701_0, "Hallway"},
        {RE2RREnums::MapID::st4_702_0, "Morgue"},
        {RE2RREnums::MapID::st4_703_0, "Generator Room"},
        {RE2RREnums::MapID::st4_704_0, "Firing Range"},
        {RE2RREnums::MapID::st4_708_0, "Parking Garage"},
        {RE2RREnums::MapID::st4_710_0, "Kennel"},
        {RE2RREnums::MapID::st4_713_0, "Jail Intake"},
        {RE2RREnums::MapID::st4_714_0, "Jail"},
        {RE2RREnums::MapID::st4_717_0, "Secret Room (Save)"},
        {RE2RREnums::MapID::st4_750_0, "Underground Stairs"},
        {RE2RREnums::MapID::st4_751_0, "Machinery Room"},
        {RE2RREnums::MapID::st4_754_0, "Elevator Control Room"},
        {RE2RREnums::MapID::st4_755_0, "Secret Save Room Elevator"},
        {RE2RREnums::MapID::st5_101_0, "Cable Car Platform"},
        {RE2RREnums::MapID::st5_102_0, "Reception"},
        {RE2RREnums::MapID::st5_103_0, "Security Room"},
        {RE2RREnums::MapID::st5_104_0, "Cafeteria/Kitchen"},
        {RE2RREnums::MapID::st5_105_0, "HVAC Duct"},
        {RE2RREnums::MapID::st5_106_0, "Nap Room"},
        {RE2RREnums::MapID::st5_111_0, "Main Shaft"},
        {RE2RREnums::MapID::st5_112_0, "Main Shaft Elevator"},
        {RE2RREnums::MapID::st5_121_0, "Lobby (Save)"},
        {RE2RREnums::MapID::st5_122_0, "Greenhouse"},
        {RE2RREnums::MapID::st5_122_1, "Presentation Room"},
        {RE2RREnums::MapID::st5_122_2, "Greenhouse Control Room"},
        {RE2RREnums::MapID::st5_123_0, "Weed Hallway"},
        {RE2RREnums::MapID::st5_124_0, "Drug Testing Lab"},
        {RE2RREnums::MapID::st5_125_0, "Storage Room"},
        {RE2RREnums::MapID::st5_126_0, "Low-Temp Testing Lab"},
        {RE2RREnums::MapID::st5_127_0, "Lounge"},
        {RE2RREnums::MapID::st5_128_0, "Server Room (Save)"},
        {RE2RREnums::MapID::st5_129_0, "Maintenance Room"},
        {RE2RREnums::MapID::st5_131_0, "Biotesting Lab"},
        {RE2RREnums::MapID::st5_132_0, "Bioreactor Decontamination"},
        {RE2RREnums::MapID::st5_133_0, "Bioreactor Room"},
        {RE2RREnums::MapID::st5_134_0, "P-4 Level Testing Lab"},
        {RE2RREnums::MapID::st5_201_0, "Monitor Room"},
        {RE2RREnums::MapID::st5_202_0, "Pump Room"},
        {RE2RREnums::MapID::st5_203_0, "Duct"},
        {RE2RREnums::MapID::st5_204_0, "Boiler Room"},
        {RE2RREnums::MapID::st5_211_0, "Escape Platform (Save)"},
        {RE2RREnums::MapID::st5_212_0, "Train Turntable"},
        {RE2RREnums::MapID::st5_223_0, ""}, // ???
        {RE2RREnums::MapID::st8_408_0, "Raccoon City Streets (Kendo's Shop)"},
        {RE2RREnums::MapID::st8_410_0, "Raccoon City Streets (A Start)"}};

std::unordered_map<RE2RREnums::MapPartsID, std::string> Randomizer::mapPartsIdToName =
    {
        {RE2RREnums::MapPartsID::Invalid, ""}};

const std::string &Randomizer::GetFloorNameById(const RE2RREnums::FloorID &key)
{
	static const std::string defaultValue = "";
	if (floorIdToName.contains(key))
		return floorIdToName[key];
	else
		return defaultValue;
}

const std::string &Randomizer::GetMapNameById(const RE2RREnums::MapID &key)
{
	static const std::string defaultValue = "";
	if (mapIdToName.contains(key))
		return mapIdToName[key];
	else
		return defaultValue;
}

const std::string &Randomizer::GetMapPartsNameById(const RE2RREnums::MapPartsID &key)
{
	static const std::string defaultValue = "";
	if (mapPartsIdToName.contains(key))
		return mapPartsIdToName[key];
	else
		return defaultValue;
}
