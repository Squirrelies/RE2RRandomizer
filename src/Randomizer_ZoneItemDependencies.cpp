#include "Randomizer.h"

static GameModeKey gameModeNormalClaireA = {.Scenario = RE2RREnums::Scenario::CLAIRE_A, .Difficulty = RE2RREnums::Difficulty::NORMAL};
static GameModeKey gameModeNormalClaireB = {.Scenario = RE2RREnums::Scenario::CLAIRE_B, .Difficulty = RE2RREnums::Difficulty::NORMAL};
static GameModeKey gameModeHardClaireA = {.Scenario = RE2RREnums::Scenario::CLAIRE_A, .Difficulty = RE2RREnums::Difficulty::HARD};
static GameModeKey gameModeHardClaireB = {.Scenario = RE2RREnums::Scenario::CLAIRE_B, .Difficulty = RE2RREnums::Difficulty::HARD};

static GameModeKey gameModeNormalLeonA = {.Scenario = RE2RREnums::Scenario::LEON_A, .Difficulty = RE2RREnums::Difficulty::NORMAL};
static GameModeKey gameModeNormalLeonB = {.Scenario = RE2RREnums::Scenario::LEON_B, .Difficulty = RE2RREnums::Difficulty::NORMAL};
static GameModeKey gameModeHardLeonA = {.Scenario = RE2RREnums::Scenario::LEON_A, .Difficulty = RE2RREnums::Difficulty::HARD};
static GameModeKey gameModeHardLeonB = {.Scenario = RE2RREnums::Scenario::LEON_B, .Difficulty = RE2RREnums::Difficulty::HARD};

static std::unordered_map<ZoneItemDependencyKey, std::vector<GUID>, std::hash<ZoneItemDependencyKey>, std::equal_to<ZoneItemDependencyKey>> zoneItemDependencies =
    {
        {ZoneItemDependencyKey{.ZoneId = 1, .GameModes = {gameModeNormalClaireA, gameModeHardClaireA, gameModeNormalLeonA, gameModeHardLeonA}, .DependencyItems = {Randomizer::originalItemMapping[gameModeNormalClaireA][*StringToGUIDA("FF9122A6-7CCE-04E4-3317-103F06B2D2E5")]}}, {*StringToGUIDA("FF9122A6-7CCE-04E4-3317-103F06B2D2E5")}},                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        // KeyStorageRoom
        {ZoneItemDependencyKey{.ZoneId = 2, .GameModes = {gameModeNormalClaireA, gameModeHardClaireA, gameModeNormalLeonA, gameModeHardLeonA}, .DependencyItems = {Randomizer::originalItemMapping[gameModeNormalClaireA][*StringToGUIDA("09749BFC-D1B4-09EA-3723-AC256D7E5630")]}}, {*StringToGUIDA("09749BFC-D1B4-09EA-3723-AC256D7E5630"), *StringToGUIDA("17761516-0B95-0710-16D2-EDDF56F1866D"), *StringToGUIDA("F1E708F9-318D-4D29-8351-EB1AA8218188"), *StringToGUIDA("0C4C5EC2-0EE6-0175-15E3-74B9F4A22F91"), *StringToGUIDA("59F3E4BF-ACB0-40B5-B7B6-01480EEC855F"), *StringToGUIDA("09749BFC-D1B4-09EA-3723-AC256D7E5630"), *StringToGUIDA("6A098F7F-81A3-4B2C-9144-8C28C9506C90"), *StringToGUIDA("C0888EF1-C0AA-47B1-B241-CDE8A11AA29C"), *StringToGUIDA("1FABF80A-A8B2-44CA-A8B6-D9DC1BC8BC4D"), *StringToGUIDA("03659087-CCD3-4032-A375-5DCCA3C339EE"), *StringToGUIDA("8AE2134C-5EFD-0227-3A61-0462F2C5CC5D"), *StringToGUIDA("21FA606C-B4D6-45C4-B097-2F439920F36C")}} // CombatKnife (Marvin)
};
