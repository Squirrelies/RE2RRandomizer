#ifndef RE2RR_TYPES_H
#define RE2RR_TYPES_H

#include "Common.h"
#include <array>
#include <functional>
#include <memory>
#include <rpc.h>
#include <stdint.h>
#include <string>
#include <vector>
#include <windows.h>

#ifdef UNICODE
#define TryStringToGUID TryStringToGUIDW
#else
#define TryStringToGUID TryStringToGUIDA
#endif
bool TryStringToGUIDA(const std::string &stringGUID, const GUID &guid);
bool TryStringToGUIDW(const std::wstring &stringGUID, const GUID &guid);

#ifdef UNICODE
#define StringToGUID StringToGUIDW
#else
#define StringToGUID StringToGUIDA
#endif
GUID &StringToGUIDA(const std::string &stringGUID);
GUID &StringToGUIDW(const std::wstring &stringGUID);

// Enum RE2RGameVersion
#ifndef RE2RR_TYPES_H_RE2RGameVersion
#define RE2RR_TYPES_H_RE2RGameVersion
#define ENUM_NAME RE2RGameVersion
#define ENUM_TYPE uint32_t
#define ENUM_LIST                        \
	ENUM_VALUE(Unknown, 0)               \
	ENUM_VALUE(WW_DX11_20230421_1, 1)    \
	ENUM_VALUE(WW_DX12_20230814_1, 2)    \
	ENUM_VALUE(CEROZ_DX11_20230421_1, 3) \
	ENUM_VALUE(CEROZ_DX12_20230814_1, 4)
#ifdef RE2RR_TYPES_CPP
#include "../src/Types_Enum.cpp"
#else
#include "Types_Enum.h"
#endif
#undef ENUM_LIST
#undef ENUM_TYPE
#undef ENUM_NAME
#endif
//

// Enum Scenario (app.ropeway.gamemastering.MainFlowManager.ScenarioType)
#ifndef RE2RR_TYPES_H_Scenario
#define RE2RR_TYPES_H_Scenario
#define ENUM_NAME Scenario
#define ENUM_TYPE int32_t
#define ENUM_LIST           \
	ENUM_VALUE(LEON_A, 0)   \
	ENUM_VALUE(CLAIRE_A, 1) \
	ENUM_VALUE(LEON_B, 2)   \
	ENUM_VALUE(CLAIRE_B, 3) \
	ENUM_VALUE(HUNK, 4)     \
	ENUM_VALUE(TOFU, 5)     \
	ENUM_VALUE(ROGUE, 6)    \
	ENUM_VALUE(L_A, 7)      \
	ENUM_VALUE(L_B, 8)      \
	ENUM_VALUE(L_C, 9)      \
	ENUM_VALUE(L_D, 10)     \
	ENUM_VALUE(MAX, 11)     \
	ENUM_VALUE(INVALID, 12)
#ifdef RE2RR_TYPES_CPP
#include "../src/Types_Enum.cpp"
#else
#include "Types_Enum.h"
#endif
#undef ENUM_LIST
#undef ENUM_TYPE
#undef ENUM_NAME
#endif
//

// Enum Difficulty (app.ropeway.gamemastering.MainFlowManager.Difficulty)
#ifndef RE2RR_TYPES_H_Difficulty
#define RE2RR_TYPES_H_Difficulty
#define ENUM_NAME Difficulty
#define ENUM_TYPE int32_t
#define ENUM_LIST         \
	ENUM_VALUE(EASY, 0)   \
	ENUM_VALUE(NORMAL, 1) \
	ENUM_VALUE(HARD, 2)   \
	ENUM_VALUE(MAX, 3)
#ifdef RE2RR_TYPES_CPP
#include "../src/Types_Enum.cpp"
#else
#include "Types_Enum.h"
#endif
#undef ENUM_LIST
#undef ENUM_TYPE
#undef ENUM_NAME
#endif
//

// Enum LocationID (app.ropeway.gamemastering.Location.ID)
#ifndef RE2RR_TYPES_H_LocationID
#define RE2RR_TYPES_H_LocationID
#define ENUM_NAME LocationID
#define ENUM_TYPE int32_t
#define ENUM_LIST                       \
	ENUM_VALUE(invalid, 0)              \
	ENUM_VALUE(CityArea, 1)             \
	ENUM_VALUE(Factory, 2)              \
	ENUM_VALUE(Laboratory, 3)           \
	ENUM_VALUE(Mountain, 4)             \
	ENUM_VALUE(Opening, 5)              \
	ENUM_VALUE(Orphanage, 6)            \
	ENUM_VALUE(Police, 7)               \
	ENUM_VALUE(SewagePlant, 8)          \
	ENUM_VALUE(Sewer, 9)                \
	ENUM_VALUE(Playground, 10)          \
	ENUM_VALUE(DLC_Laboratory, 11)      \
	ENUM_VALUE(DLC_Aida, 12)            \
	ENUM_VALUE(DLC_Hunk, 13)            \
	ENUM_VALUE(Opening2, 14)            \
	ENUM_VALUE(GasStation, 15)          \
	ENUM_VALUE(RPD, 16)                 \
	ENUM_VALUE(WasteWater, 17)          \
	ENUM_VALUE(WaterPlant, 18)          \
	ENUM_VALUE(EV011, 19)               \
	ENUM_VALUE(EV050, 20)               \
	ENUM_VALUE(LaboratoryUndermost, 21) \
	ENUM_VALUE(Transportation, 22)      \
	ENUM_VALUE(GasStation2, 23)         \
	ENUM_VALUE(OrphanAsylum, 24)        \
	ENUM_VALUE(OrphanApproach, 25)      \
	ENUM_VALUE(CrocodiliaArea, 26)      \
	ENUM_VALUE(Title, 27)               \
	ENUM_VALUE(Movie, 28)               \
	ENUM_VALUE(RPD_B1, 29)              \
	ENUM_VALUE(Opening3, 30)            \
	ENUM_VALUE(GameOver, 31)            \
	ENUM_VALUE(Result, 32)              \
	ENUM_VALUE(Ending, 33)              \
	ENUM_VALUE(LOCATION_NUM, 34)
#ifdef RE2RR_TYPES_CPP
#include "../src/Types_Enum.cpp"
#else
#include "Types_Enum.h"
#endif
#undef ENUM_LIST
#undef ENUM_TYPE
#undef ENUM_NAME
#endif
//

// Enum MapArea
#ifndef RE2RR_TYPES_H_MapArea
#define RE2RR_TYPES_H_MapArea
#define ENUM_NAME MapArea
#define ENUM_TYPE uint32_t
#define ENUM_LIST     \
	ENUM_VALUE(_0, 0) \
	ENUM_VALUE(_1, 1) \
	ENUM_VALUE(_2, 2) \
	ENUM_VALUE(_3, 3) \
	ENUM_VALUE(_4, 4) \
	ENUM_VALUE(_5, 5) \
	ENUM_VALUE(AREA_NUM, 6)
#ifdef RE2RR_TYPES_CPP
#include "../src/Types_Enum.cpp"
#else
#include "Types_Enum.h"
#endif
#undef ENUM_LIST
#undef ENUM_TYPE
#undef ENUM_NAME
#endif
//

// Enum MapID (app.ropeway.gamemastering.Map.ID)
#ifndef RE2RR_TYPES_H_MapID
#define RE2RR_TYPES_H_MapID
#define ENUM_NAME MapID
#define ENUM_TYPE int32_t
#define ENUM_LIST              \
	ENUM_VALUE(Invalid, 0)     \
	ENUM_VALUE(st0_101_0, 1)   \
	ENUM_VALUE(st0_102_0, 2)   \
	ENUM_VALUE(st1_101_0, 3)   \
	ENUM_VALUE(st1_102_0, 4)   \
	ENUM_VALUE(st1_103_0, 5)   \
	ENUM_VALUE(st1_104_0, 6)   \
	ENUM_VALUE(st1_105_0, 7)   \
	ENUM_VALUE(st1_106_0, 8)   \
	ENUM_VALUE(st1_107_0, 9)   \
	ENUM_VALUE(st1_108_0, 10)  \
	ENUM_VALUE(st1_109_0, 11)  \
	ENUM_VALUE(st1_110_0, 12)  \
	ENUM_VALUE(st1_111_0, 13)  \
	ENUM_VALUE(st1_201_0, 14)  \
	ENUM_VALUE(st1_202_0, 15)  \
	ENUM_VALUE(st1_203_0, 16)  \
	ENUM_VALUE(st1_204_0, 17)  \
	ENUM_VALUE(st1_205_0, 18)  \
	ENUM_VALUE(st1_206_0, 19)  \
	ENUM_VALUE(st1_207_0, 20)  \
	ENUM_VALUE(st1_208_0, 21)  \
	ENUM_VALUE(st1_209_0, 22)  \
	ENUM_VALUE(st1_210_0, 23)  \
	ENUM_VALUE(st1_211_0, 24)  \
	ENUM_VALUE(st2_101_0, 25)  \
	ENUM_VALUE(st2_102_0, 26)  \
	ENUM_VALUE(st2_103_0, 27)  \
	ENUM_VALUE(st2_201_0, 28)  \
	ENUM_VALUE(st2_202_0, 29)  \
	ENUM_VALUE(st2_203_0, 30)  \
	ENUM_VALUE(st2_204_0, 31)  \
	ENUM_VALUE(st2_205_0, 32)  \
	ENUM_VALUE(st2_206_0, 33)  \
	ENUM_VALUE(st2_207_0, 34)  \
	ENUM_VALUE(st2_208_0, 35)  \
	ENUM_VALUE(st2_209_0, 36)  \
	ENUM_VALUE(st2_210_0, 37)  \
	ENUM_VALUE(st2_211_0, 38)  \
	ENUM_VALUE(st2_212_0, 39)  \
	ENUM_VALUE(st2_213_0, 40)  \
	ENUM_VALUE(st2_214_0, 41)  \
	ENUM_VALUE(st2_215_0, 42)  \
	ENUM_VALUE(st2_216_0, 43)  \
	ENUM_VALUE(st2_301_0, 44)  \
	ENUM_VALUE(st2_302_0, 45)  \
	ENUM_VALUE(st2_303_0, 46)  \
	ENUM_VALUE(st2_304_0, 47)  \
	ENUM_VALUE(st2_305_0, 48)  \
	ENUM_VALUE(st2_306_0, 49)  \
	ENUM_VALUE(st2_307_0, 50)  \
	ENUM_VALUE(st2_308_0, 51)  \
	ENUM_VALUE(st2_309_0, 52)  \
	ENUM_VALUE(st2_401_0, 53)  \
	ENUM_VALUE(st2_401_1, 54)  \
	ENUM_VALUE(st2_402_0, 55)  \
	ENUM_VALUE(st2_403_0, 56)  \
	ENUM_VALUE(st2_404_0, 57)  \
	ENUM_VALUE(st2_405_0, 58)  \
	ENUM_VALUE(st2_406_0, 59)  \
	ENUM_VALUE(st2_407_0, 60)  \
	ENUM_VALUE(st2_408_0, 61)  \
	ENUM_VALUE(st2_501_0, 62)  \
	ENUM_VALUE(st2_502_0, 63)  \
	ENUM_VALUE(st2_502_0b, 64) \
	ENUM_VALUE(st2_502_0c, 65) \
	ENUM_VALUE(st2_503_0, 66)  \
	ENUM_VALUE(st2_504_0, 67)  \
	ENUM_VALUE(st2_505_0, 68)  \
	ENUM_VALUE(st2_506_0, 69)  \
	ENUM_VALUE(st2_507_0, 70)  \
	ENUM_VALUE(st2_508_0, 71)  \
	ENUM_VALUE(st2_601_0, 72)  \
	ENUM_VALUE(st2_602_0, 73)  \
	ENUM_VALUE(st2_603_0, 74)  \
	ENUM_VALUE(st2_604_0, 75)  \
	ENUM_VALUE(st2_605_0, 76)  \
	ENUM_VALUE(st2_606_0, 77)  \
	ENUM_VALUE(st2_607_0, 78)  \
	ENUM_VALUE(st2_608_0, 79)  \
	ENUM_VALUE(st3_101_0, 80)  \
	ENUM_VALUE(st3_102_0, 81)  \
	ENUM_VALUE(st3_103_0, 82)  \
	ENUM_VALUE(st3_104_0, 83)  \
	ENUM_VALUE(st3_105_0, 84)  \
	ENUM_VALUE(st3_106_0, 85)  \
	ENUM_VALUE(st3_107_0, 86)  \
	ENUM_VALUE(st3_108_0, 87)  \
	ENUM_VALUE(st3_109_0, 88)  \
	ENUM_VALUE(st3_110_0, 89)  \
	ENUM_VALUE(st3_111_0, 90)  \
	ENUM_VALUE(st3_112_0, 91)  \
	ENUM_VALUE(st3_113_0, 92)  \
	ENUM_VALUE(st3_114_0, 93)  \
	ENUM_VALUE(st3_201_0, 94)  \
	ENUM_VALUE(st3_202_0, 95)  \
	ENUM_VALUE(st3_203_0, 96)  \
	ENUM_VALUE(st3_204_0, 97)  \
	ENUM_VALUE(st3_205_0, 98)  \
	ENUM_VALUE(st3_206_0, 99)  \
	ENUM_VALUE(st3_207_0, 100) \
	ENUM_VALUE(st3_208_0, 101) \
	ENUM_VALUE(st3_209_0, 102) \
	ENUM_VALUE(st3_210_0, 103) \
	ENUM_VALUE(st3_301_0, 104) \
	ENUM_VALUE(st3_302_0, 105) \
	ENUM_VALUE(st3_303_0, 106) \
	ENUM_VALUE(st3_304_0, 107) \
	ENUM_VALUE(st3_305_0, 108) \
	ENUM_VALUE(st3_306_0, 109) \
	ENUM_VALUE(st3_307_0, 110) \
	ENUM_VALUE(st3_308_0, 111) \
	ENUM_VALUE(st4_101_0, 112) \
	ENUM_VALUE(st4_102_0, 113) \
	ENUM_VALUE(st4_103_0, 114) \
	ENUM_VALUE(st4_104_0, 115) \
	ENUM_VALUE(st4_105_0, 116) \
	ENUM_VALUE(st4_106_0, 117) \
	ENUM_VALUE(st4_207_0, 118) \
	ENUM_VALUE(st4_208_0, 119) \
	ENUM_VALUE(st4_209_0, 120) \
	ENUM_VALUE(st4_210_0, 121) \
	ENUM_VALUE(st4_211_0, 122) \
	ENUM_VALUE(st4_212_0, 123) \
	ENUM_VALUE(st4_213_0, 124) \
	ENUM_VALUE(st4_214_0, 125) \
	ENUM_VALUE(st5_101_0, 126) \
	ENUM_VALUE(st5_102_0, 127) \
	ENUM_VALUE(st5_103_0, 128) \
	ENUM_VALUE(st5_104_0, 129) \
	ENUM_VALUE(st5_105_0, 130) \
	ENUM_VALUE(st5_106_0, 131) \
	ENUM_VALUE(st5_107_0, 132) \
	ENUM_VALUE(st5_201_0, 133) \
	ENUM_VALUE(st5_202_0, 134) \
	ENUM_VALUE(st5_203_0, 135) \
	ENUM_VALUE(st5_204_0, 136) \
	ENUM_VALUE(st5_205_0, 137) \
	ENUM_VALUE(st5_206_0, 138) \
	ENUM_VALUE(st5_207_0, 139) \
	ENUM_VALUE(st5_301_0, 140) \
	ENUM_VALUE(st5_302_0, 141) \
	ENUM_VALUE(st5_303_0, 142) \
	ENUM_VALUE(st6_101_0, 143) \
	ENUM_VALUE(st6_102_0, 144) \
	ENUM_VALUE(st6_103_0, 145) \
	ENUM_VALUE(st6_104_0, 146) \
	ENUM_VALUE(st6_105_0, 147) \
	ENUM_VALUE(st6_106_0, 148) \
	ENUM_VALUE(st6_107_0, 149) \
	ENUM_VALUE(st6_201_0, 150) \
	ENUM_VALUE(st6_202_0, 151) \
	ENUM_VALUE(st6_203_0, 152) \
	ENUM_VALUE(st6_204_0, 153) \
	ENUM_VALUE(st6_205_0, 154) \
	ENUM_VALUE(st6_206_0, 155) \
	ENUM_VALUE(st6_207_0, 156) \
	ENUM_VALUE(st6_208_0, 157) \
	ENUM_VALUE(st6_209_0, 158) \
	ENUM_VALUE(st6_210_0, 159) \
	ENUM_VALUE(st6_211_0, 160) \
	ENUM_VALUE(st6_212_0, 161) \
	ENUM_VALUE(st7_101_0, 162) \
	ENUM_VALUE(st7_102_0, 163) \
	ENUM_VALUE(st7_103_0, 164) \
	ENUM_VALUE(st7_104_0, 165) \
	ENUM_VALUE(st7_105_0, 166) \
	ENUM_VALUE(st7_106_0, 167) \
	ENUM_VALUE(st7_107_0, 168) \
	ENUM_VALUE(st7_108_0, 169) \
	ENUM_VALUE(st7_109_0, 170) \
	ENUM_VALUE(st7_110_0, 171) \
	ENUM_VALUE(st7_111_0, 172) \
	ENUM_VALUE(st7_112_0, 173) \
	ENUM_VALUE(st8_101_0, 174) \
	ENUM_VALUE(st8_102_0, 175) \
	ENUM_VALUE(st8_103_0, 176) \
	ENUM_VALUE(st8_104_0, 177) \
	ENUM_VALUE(st8_105_0, 178) \
	ENUM_VALUE(st8_106_0, 179) \
	ENUM_VALUE(st8_107_0, 180) \
	ENUM_VALUE(st8_108_0, 181) \
	ENUM_VALUE(st8_109_0, 182) \
	ENUM_VALUE(st8_110_0, 183) \
	ENUM_VALUE(st8_111_0, 184) \
	ENUM_VALUE(st8_112_0, 185) \
	ENUM_VALUE(st8_113_0, 186) \
	ENUM_VALUE(st8_114_0, 187) \
	ENUM_VALUE(st8_115_0, 188) \
	ENUM_VALUE(st8_201_0, 189) \
	ENUM_VALUE(st8_202_0, 190) \
	ENUM_VALUE(st8_203_0, 191) \
	ENUM_VALUE(st8_301_0, 192) \
	ENUM_VALUE(st8_302_0, 193) \
	ENUM_VALUE(st8_303_0, 194) \
	ENUM_VALUE(st8_304_0, 195) \
	ENUM_VALUE(st8_305_0, 196) \
	ENUM_VALUE(st8_306_0, 197) \
	ENUM_VALUE(st8_307_0, 198) \
	ENUM_VALUE(st8_308_0, 199) \
	ENUM_VALUE(st8_309_0, 200) \
	ENUM_VALUE(st8_310_0, 201) \
	ENUM_VALUE(st8_311_0, 202) \
	ENUM_VALUE(st8_401_0, 203) \
	ENUM_VALUE(st8_402_0, 204) \
	ENUM_VALUE(st8_403_0, 205) \
	ENUM_VALUE(st8_404_0, 206) \
	ENUM_VALUE(st8_405_0, 207) \
	ENUM_VALUE(st8_406_0, 208) \
	ENUM_VALUE(st8_407_0, 209) \
	ENUM_VALUE(st9_101_0, 210) \
	ENUM_VALUE(st9_102_0, 211) \
	ENUM_VALUE(st9_103_0, 212) \
	ENUM_VALUE(st9_201_0, 213) \
	ENUM_VALUE(st9_202_0, 214) \
	ENUM_VALUE(st9_203_0, 215) \
	ENUM_VALUE(st9_301_0, 216) \
	ENUM_VALUE(st1_301_0, 217) \
	ENUM_VALUE(st1_401_0, 218) \
	ENUM_VALUE(st4_201_0, 219) \
	ENUM_VALUE(st4_202_0, 220) \
	ENUM_VALUE(st4_203_0, 221) \
	ENUM_VALUE(st4_204_0, 222) \
	ENUM_VALUE(st4_205_0, 223) \
	ENUM_VALUE(st4_206_0, 224) \
	ENUM_VALUE(st4_215_0, 225) \
	ENUM_VALUE(st4_216_0, 226) \
	ENUM_VALUE(st4_301_0, 227) \
	ENUM_VALUE(st4_302_0, 228) \
	ENUM_VALUE(st4_303_0, 229) \
	ENUM_VALUE(st4_304_0, 230) \
	ENUM_VALUE(st4_305_0, 231) \
	ENUM_VALUE(st4_306_0, 232) \
	ENUM_VALUE(st4_307_0, 233) \
	ENUM_VALUE(st4_308_0, 234) \
	ENUM_VALUE(st4_309_0, 235) \
	ENUM_VALUE(st4_310_0, 236) \
	ENUM_VALUE(st4_311_0, 237) \
	ENUM_VALUE(st4_312_0, 238) \
	ENUM_VALUE(st4_313_0, 239) \
	ENUM_VALUE(st4_314_0, 240) \
	ENUM_VALUE(st4_401_0, 241) \
	ENUM_VALUE(st4_401_1, 242) \
	ENUM_VALUE(st4_402_0, 243) \
	ENUM_VALUE(st4_403_0, 244) \
	ENUM_VALUE(st4_404_0, 245) \
	ENUM_VALUE(st4_405_0, 246) \
	ENUM_VALUE(st4_406_0, 247) \
	ENUM_VALUE(st4_407_0, 248) \
	ENUM_VALUE(st4_408_0, 249) \
	ENUM_VALUE(st4_409_0, 250) \
	ENUM_VALUE(st4_410_0, 251) \
	ENUM_VALUE(st4_411_0, 252) \
	ENUM_VALUE(st4_412_0, 253) \
	ENUM_VALUE(st4_501_0, 254) \
	ENUM_VALUE(st4_502_0, 255) \
	ENUM_VALUE(st4_503_0, 256) \
	ENUM_VALUE(st4_504_0, 257) \
	ENUM_VALUE(st4_505_0, 258) \
	ENUM_VALUE(st4_506_0, 259) \
	ENUM_VALUE(st4_507_0, 260) \
	ENUM_VALUE(st4_508_0, 261) \
	ENUM_VALUE(st4_601_0, 262) \
	ENUM_VALUE(st4_602_0, 263) \
	ENUM_VALUE(st4_603_0, 264) \
	ENUM_VALUE(st4_604_0, 265) \
	ENUM_VALUE(st4_605_0, 266) \
	ENUM_VALUE(st4_606_0, 267) \
	ENUM_VALUE(st4_607_0, 268) \
	ENUM_VALUE(st4_608_0, 269) \
	ENUM_VALUE(st4_609_0, 270) \
	ENUM_VALUE(st4_610_0, 271) \
	ENUM_VALUE(st4_701_0, 272) \
	ENUM_VALUE(st4_702_0, 273) \
	ENUM_VALUE(st4_703_0, 274) \
	ENUM_VALUE(st4_704_0, 275) \
	ENUM_VALUE(st4_705_0, 276) \
	ENUM_VALUE(st4_708_0, 277) \
	ENUM_VALUE(st4_709_0, 278) \
	ENUM_VALUE(st4_710_0, 279) \
	ENUM_VALUE(st4_711_0, 280) \
	ENUM_VALUE(st4_712_0, 281) \
	ENUM_VALUE(st4_714_0, 282) \
	ENUM_VALUE(st1_501_0, 283) \
	ENUM_VALUE(st1_502_0, 284) \
	ENUM_VALUE(st1_503_0, 285) \
	ENUM_VALUE(st1_504_0, 286) \
	ENUM_VALUE(st1_505_0, 287) \
	ENUM_VALUE(st1_506_0, 288) \
	ENUM_VALUE(st4_650_0, 289) \
	ENUM_VALUE(st3_401_0, 290) \
	ENUM_VALUE(st3_402_0, 291) \
	ENUM_VALUE(st3_403_0, 292) \
	ENUM_VALUE(st3_404_0, 293) \
	ENUM_VALUE(st3_405_0, 294) \
	ENUM_VALUE(st3_406_0, 295) \
	ENUM_VALUE(st3_407_0, 296) \
	ENUM_VALUE(st3_408_0, 297) \
	ENUM_VALUE(st3_409_0, 298) \
	ENUM_VALUE(st3_410_0, 299) \
	ENUM_VALUE(st8_501_0, 300) \
	ENUM_VALUE(st8_601_0, 301) \
	ENUM_VALUE(st8_602_0, 302) \
	ENUM_VALUE(st8_603_0, 303) \
	ENUM_VALUE(st8_604_0, 304) \
	ENUM_VALUE(st8_605_0, 305) \
	ENUM_VALUE(st8_606_0, 306) \
	ENUM_VALUE(st8_607_0, 307) \
	ENUM_VALUE(st8_608_0, 308) \
	ENUM_VALUE(st8_609_0, 309) \
	ENUM_VALUE(st3_600_0, 310) \
	ENUM_VALUE(st3_601_0, 311) \
	ENUM_VALUE(st3_602_0, 312) \
	ENUM_VALUE(st3_603_0, 313) \
	ENUM_VALUE(st3_610_0, 314) \
	ENUM_VALUE(st3_611_0, 315) \
	ENUM_VALUE(st3_612_0, 316) \
	ENUM_VALUE(st3_613_0, 317) \
	ENUM_VALUE(st3_614_0, 318) \
	ENUM_VALUE(st3_615_0, 319) \
	ENUM_VALUE(st3_616_0, 320) \
	ENUM_VALUE(st3_617_0, 321) \
	ENUM_VALUE(st3_620_0, 322) \
	ENUM_VALUE(st3_621_0, 323) \
	ENUM_VALUE(st3_622_0, 324) \
	ENUM_VALUE(st3_623_0, 325) \
	ENUM_VALUE(st3_624_0, 326) \
	ENUM_VALUE(st3_625_0, 327) \
	ENUM_VALUE(st3_626_0, 328) \
	ENUM_VALUE(st3_627_0, 329) \
	ENUM_VALUE(st3_630_0, 330) \
	ENUM_VALUE(st3_631_0, 331) \
	ENUM_VALUE(st3_632_0, 332) \
	ENUM_VALUE(st3_633_0, 333) \
	ENUM_VALUE(st3_634_0, 334) \
	ENUM_VALUE(st3_635_0, 335) \
	ENUM_VALUE(st3_636_0, 336) \
	ENUM_VALUE(st3_637_0, 337) \
	ENUM_VALUE(st3_638_0, 338) \
	ENUM_VALUE(st3_640_0, 339) \
	ENUM_VALUE(st3_641_0, 340) \
	ENUM_VALUE(st3_642_0, 341) \
	ENUM_VALUE(st3_643_0, 342) \
	ENUM_VALUE(st3_644_0, 343) \
	ENUM_VALUE(st3_650_0, 344) \
	ENUM_VALUE(st3_651_0, 345) \
	ENUM_VALUE(st3_652_0, 346) \
	ENUM_VALUE(st1_411_0, 347) \
	ENUM_VALUE(st4_715_0, 348) \
	ENUM_VALUE(st4_716_0, 349) \
	ENUM_VALUE(st4_717_0, 350) \
	ENUM_VALUE(st8_408_0, 351) \
	ENUM_VALUE(st4_750_0, 352) \
	ENUM_VALUE(st4_751_0, 353) \
	ENUM_VALUE(st4_752_0, 354) \
	ENUM_VALUE(st4_753_0, 355) \
	ENUM_VALUE(st4_754_0, 356) \
	ENUM_VALUE(st8_409_0, 357) \
	ENUM_VALUE(st8_410_0, 358) \
	ENUM_VALUE(st1_601_0, 359) \
	ENUM_VALUE(st1_602_0, 360) \
	ENUM_VALUE(st1_603_0, 361) \
	ENUM_VALUE(st1_604_0, 362) \
	ENUM_VALUE(st1_605_0, 363) \
	ENUM_VALUE(st1_606_0, 364) \
	ENUM_VALUE(st1_607_0, 365) \
	ENUM_VALUE(st1_608_0, 366) \
	ENUM_VALUE(st1_609_0, 367) \
	ENUM_VALUE(st8_650_0, 368) \
	ENUM_VALUE(st8_411_0, 369) \
	ENUM_VALUE(st5_111_0, 370) \
	ENUM_VALUE(st5_121_0, 371) \
	ENUM_VALUE(st5_131_0, 372) \
	ENUM_VALUE(st5_211_0, 373) \
	ENUM_VALUE(st5_221_0, 374) \
	ENUM_VALUE(st0_103_0, 375) \
	ENUM_VALUE(st8_660_0, 376) \
	ENUM_VALUE(st1_620_0, 377) \
	ENUM_VALUE(st1_621_0, 378) \
	ENUM_VALUE(st1_622_0, 379) \
	ENUM_VALUE(st1_623_0, 380) \
	ENUM_VALUE(st1_610_0, 381) \
	ENUM_VALUE(st1_611_0, 382) \
	ENUM_VALUE(st1_612_0, 383) \
	ENUM_VALUE(st1_613_0, 384) \
	ENUM_VALUE(st1_614_0, 385) \
	ENUM_VALUE(st5_112_0, 386) \
	ENUM_VALUE(st5_110_0, 387) \
	ENUM_VALUE(st5_113_0, 388) \
	ENUM_VALUE(st5_114_0, 389) \
	ENUM_VALUE(st5_115_0, 390) \
	ENUM_VALUE(st5_307_0, 391) \
	ENUM_VALUE(st5_308_0, 392) \
	ENUM_VALUE(st5_309_0, 393) \
	ENUM_VALUE(st5_310_0, 394) \
	ENUM_VALUE(st5_401_0, 395) \
	ENUM_VALUE(st5_402_0, 396) \
	ENUM_VALUE(st5_403_0, 397) \
	ENUM_VALUE(st5_404_0, 398) \
	ENUM_VALUE(st5_405_0, 399) \
	ENUM_VALUE(st5_406_0, 400) \
	ENUM_VALUE(st5_407_0, 401) \
	ENUM_VALUE(st5_408_0, 402) \
	ENUM_VALUE(st4_800_0, 403) \
	ENUM_VALUE(st1_615_0, 404) \
	ENUM_VALUE(st4_755_0, 405) \
	ENUM_VALUE(st1_630_0, 406) \
	ENUM_VALUE(st1_631_0, 407) \
	ENUM_VALUE(st1_632_0, 408) \
	ENUM_VALUE(st4_713_0, 409) \
	ENUM_VALUE(st5_122_0, 410) \
	ENUM_VALUE(st5_123_0, 411) \
	ENUM_VALUE(st5_124_0, 412) \
	ENUM_VALUE(st5_125_0, 413) \
	ENUM_VALUE(st5_126_0, 414) \
	ENUM_VALUE(st5_127_0, 415) \
	ENUM_VALUE(st5_128_0, 416) \
	ENUM_VALUE(st5_129_0, 417) \
	ENUM_VALUE(st5_132_0, 418) \
	ENUM_VALUE(st5_133_0, 419) \
	ENUM_VALUE(st5_134_0, 420) \
	ENUM_VALUE(st5_212_0, 421) \
	ENUM_VALUE(st5_222_0, 422) \
	ENUM_VALUE(st5_223_0, 423) \
	ENUM_VALUE(st8_651_0, 424) \
	ENUM_VALUE(st8_610_0, 425) \
	ENUM_VALUE(st8_611_0, 426) \
	ENUM_VALUE(st8_612_0, 427) \
	ENUM_VALUE(st8_613_0, 428) \
	ENUM_VALUE(st3_604_0, 429) \
	ENUM_VALUE(st3_605_0, 430) \
	ENUM_VALUE(st4_217_0, 431) \
	ENUM_VALUE(st5_122_1, 432) \
	ENUM_VALUE(st5_122_2, 433) \
	ENUM_VALUE(st8_614_0, 434) \
	ENUM_VALUE(MAP_NUM, 435)
#ifdef RE2RR_TYPES_CPP
#include "../src/Types_Enum.cpp"
#else
#include "Types_Enum.h"
#endif
#undef ENUM_LIST
#undef ENUM_TYPE
#undef ENUM_NAME
#endif
//

// Enum MapPartsID (app.ropeway.gamemastering.MapParts.ID)
#ifndef RE2RR_TYPES_H_MapPartsID
#define RE2RR_TYPES_H_MapPartsID
#define ENUM_NAME MapPartsID
#define ENUM_TYPE int32_t
#define ENUM_LIST               \
	ENUM_VALUE(Invalid, 0)      \
	ENUM_VALUE(st0_101_0, 1)    \
	ENUM_VALUE(st0_102_0, 2)    \
	ENUM_VALUE(st1_101_0, 3)    \
	ENUM_VALUE(st1_102_0, 4)    \
	ENUM_VALUE(st1_103_0, 5)    \
	ENUM_VALUE(st1_104_0, 6)    \
	ENUM_VALUE(st1_105_0, 7)    \
	ENUM_VALUE(st1_106_0, 8)    \
	ENUM_VALUE(st1_107_0, 9)    \
	ENUM_VALUE(st1_108_0, 10)   \
	ENUM_VALUE(st1_109_0, 11)   \
	ENUM_VALUE(st1_110_0, 12)   \
	ENUM_VALUE(st1_111_0, 13)   \
	ENUM_VALUE(st1_201_0, 14)   \
	ENUM_VALUE(st1_202_0, 15)   \
	ENUM_VALUE(st1_203_0, 16)   \
	ENUM_VALUE(st1_204_0, 17)   \
	ENUM_VALUE(st1_205_0, 18)   \
	ENUM_VALUE(st1_206_0, 19)   \
	ENUM_VALUE(st1_207_0, 20)   \
	ENUM_VALUE(st1_208_0, 21)   \
	ENUM_VALUE(st1_209_0, 22)   \
	ENUM_VALUE(st1_210_0, 23)   \
	ENUM_VALUE(st1_211_0, 24)   \
	ENUM_VALUE(st2_101_0, 25)   \
	ENUM_VALUE(st2_102_0, 26)   \
	ENUM_VALUE(st2_103_0, 27)   \
	ENUM_VALUE(st2_201_0, 28)   \
	ENUM_VALUE(st2_202_0, 29)   \
	ENUM_VALUE(st2_203_0, 30)   \
	ENUM_VALUE(st2_204_0, 31)   \
	ENUM_VALUE(st2_205_0, 32)   \
	ENUM_VALUE(st2_206_0, 33)   \
	ENUM_VALUE(st2_207_0, 34)   \
	ENUM_VALUE(st2_208_0, 35)   \
	ENUM_VALUE(st2_209_0, 36)   \
	ENUM_VALUE(st2_210_0, 37)   \
	ENUM_VALUE(st2_211_0, 38)   \
	ENUM_VALUE(st2_212_0, 39)   \
	ENUM_VALUE(st2_213_0, 40)   \
	ENUM_VALUE(st2_214_0, 41)   \
	ENUM_VALUE(st2_215_0, 42)   \
	ENUM_VALUE(st2_216_0, 43)   \
	ENUM_VALUE(st2_301_0, 44)   \
	ENUM_VALUE(st2_302_0, 45)   \
	ENUM_VALUE(st2_303_0, 46)   \
	ENUM_VALUE(st2_304_0, 47)   \
	ENUM_VALUE(st2_305_0, 48)   \
	ENUM_VALUE(st2_306_0, 49)   \
	ENUM_VALUE(st2_307_0, 50)   \
	ENUM_VALUE(st2_308_0, 51)   \
	ENUM_VALUE(st2_309_0, 52)   \
	ENUM_VALUE(st2_401_0, 53)   \
	ENUM_VALUE(st2_401_1, 54)   \
	ENUM_VALUE(st2_402_0, 55)   \
	ENUM_VALUE(st2_403_0, 56)   \
	ENUM_VALUE(st2_404_0, 57)   \
	ENUM_VALUE(st2_405_0, 58)   \
	ENUM_VALUE(st2_406_0, 59)   \
	ENUM_VALUE(st2_407_0, 60)   \
	ENUM_VALUE(st2_408_0, 61)   \
	ENUM_VALUE(st2_501_0, 62)   \
	ENUM_VALUE(st2_502_0, 63)   \
	ENUM_VALUE(st2_502_0b, 64)  \
	ENUM_VALUE(st2_502_0c, 65)  \
	ENUM_VALUE(st2_503_0, 66)   \
	ENUM_VALUE(st2_504_0, 67)   \
	ENUM_VALUE(st2_505_0, 68)   \
	ENUM_VALUE(st2_506_0, 69)   \
	ENUM_VALUE(st2_507_0, 70)   \
	ENUM_VALUE(st2_508_0, 71)   \
	ENUM_VALUE(st2_601_0, 72)   \
	ENUM_VALUE(st2_602_0, 73)   \
	ENUM_VALUE(st2_603_0, 74)   \
	ENUM_VALUE(st2_604_0, 75)   \
	ENUM_VALUE(st2_605_0, 76)   \
	ENUM_VALUE(st2_606_0, 77)   \
	ENUM_VALUE(st2_607_0, 78)   \
	ENUM_VALUE(st2_608_0, 79)   \
	ENUM_VALUE(st3_101_0, 80)   \
	ENUM_VALUE(st3_102_0, 81)   \
	ENUM_VALUE(st3_103_0, 82)   \
	ENUM_VALUE(st3_104_0, 83)   \
	ENUM_VALUE(st3_105_0, 84)   \
	ENUM_VALUE(st3_106_0, 85)   \
	ENUM_VALUE(st3_107_0, 86)   \
	ENUM_VALUE(st3_108_0, 87)   \
	ENUM_VALUE(st3_109_0, 88)   \
	ENUM_VALUE(st3_110_0, 89)   \
	ENUM_VALUE(st3_111_0, 90)   \
	ENUM_VALUE(st3_112_0, 91)   \
	ENUM_VALUE(st3_113_0, 92)   \
	ENUM_VALUE(st3_114_0, 93)   \
	ENUM_VALUE(st3_201_0, 94)   \
	ENUM_VALUE(st3_202_0, 95)   \
	ENUM_VALUE(st3_203_0, 96)   \
	ENUM_VALUE(st3_204_0, 97)   \
	ENUM_VALUE(st3_205_0, 98)   \
	ENUM_VALUE(st3_206_0, 99)   \
	ENUM_VALUE(st3_207_0, 100)  \
	ENUM_VALUE(st3_208_0, 101)  \
	ENUM_VALUE(st3_209_0, 102)  \
	ENUM_VALUE(st3_210_0, 103)  \
	ENUM_VALUE(st3_301_0, 104)  \
	ENUM_VALUE(st3_302_0, 105)  \
	ENUM_VALUE(st3_303_0, 106)  \
	ENUM_VALUE(st3_304_0, 107)  \
	ENUM_VALUE(st3_305_0, 108)  \
	ENUM_VALUE(st3_306_0, 109)  \
	ENUM_VALUE(st3_307_0, 110)  \
	ENUM_VALUE(st3_308_0, 111)  \
	ENUM_VALUE(st4_101_0, 112)  \
	ENUM_VALUE(st4_102_0, 113)  \
	ENUM_VALUE(st4_103_0, 114)  \
	ENUM_VALUE(st4_104_0, 115)  \
	ENUM_VALUE(st4_105_0, 116)  \
	ENUM_VALUE(st4_106_0, 117)  \
	ENUM_VALUE(st4_207_0, 118)  \
	ENUM_VALUE(st4_208_0, 119)  \
	ENUM_VALUE(st4_209_0, 120)  \
	ENUM_VALUE(st4_210_0, 121)  \
	ENUM_VALUE(st4_211_0, 122)  \
	ENUM_VALUE(st4_212_0, 123)  \
	ENUM_VALUE(st4_213_0, 124)  \
	ENUM_VALUE(st4_214_0, 125)  \
	ENUM_VALUE(st5_101_0, 126)  \
	ENUM_VALUE(st5_102_0, 127)  \
	ENUM_VALUE(st5_103_0, 128)  \
	ENUM_VALUE(st5_104_0, 129)  \
	ENUM_VALUE(st5_105_0, 130)  \
	ENUM_VALUE(st5_106_0, 131)  \
	ENUM_VALUE(st5_107_0, 132)  \
	ENUM_VALUE(st5_201_0, 133)  \
	ENUM_VALUE(st5_202_0, 134)  \
	ENUM_VALUE(st5_203_0, 135)  \
	ENUM_VALUE(st5_204_0, 136)  \
	ENUM_VALUE(st5_205_0, 137)  \
	ENUM_VALUE(st5_206_0, 138)  \
	ENUM_VALUE(st5_207_0, 139)  \
	ENUM_VALUE(st5_301_0, 140)  \
	ENUM_VALUE(st5_302_0, 141)  \
	ENUM_VALUE(st5_303_0, 142)  \
	ENUM_VALUE(st6_101_0, 143)  \
	ENUM_VALUE(st6_102_0, 144)  \
	ENUM_VALUE(st6_103_0, 145)  \
	ENUM_VALUE(st6_104_0, 146)  \
	ENUM_VALUE(st6_105_0, 147)  \
	ENUM_VALUE(st6_106_0, 148)  \
	ENUM_VALUE(st6_107_0, 149)  \
	ENUM_VALUE(st6_201_0, 150)  \
	ENUM_VALUE(st6_202_0, 151)  \
	ENUM_VALUE(st6_203_0, 152)  \
	ENUM_VALUE(st6_204_0, 153)  \
	ENUM_VALUE(st6_205_0, 154)  \
	ENUM_VALUE(st6_206_0, 155)  \
	ENUM_VALUE(st6_207_0, 156)  \
	ENUM_VALUE(st6_208_0, 157)  \
	ENUM_VALUE(st6_209_0, 158)  \
	ENUM_VALUE(st6_210_0, 159)  \
	ENUM_VALUE(st6_211_0, 160)  \
	ENUM_VALUE(st6_212_0, 161)  \
	ENUM_VALUE(st7_101_0, 162)  \
	ENUM_VALUE(st7_102_0, 163)  \
	ENUM_VALUE(st7_103_0, 164)  \
	ENUM_VALUE(st7_104_0, 165)  \
	ENUM_VALUE(st7_105_0, 166)  \
	ENUM_VALUE(st7_106_0, 167)  \
	ENUM_VALUE(st7_107_0, 168)  \
	ENUM_VALUE(st7_108_0, 169)  \
	ENUM_VALUE(st7_109_0, 170)  \
	ENUM_VALUE(st7_110_0, 171)  \
	ENUM_VALUE(st7_111_0, 172)  \
	ENUM_VALUE(st7_112_0, 173)  \
	ENUM_VALUE(st8_101_0, 174)  \
	ENUM_VALUE(st8_102_0, 175)  \
	ENUM_VALUE(st8_103_0, 176)  \
	ENUM_VALUE(st8_104_0, 177)  \
	ENUM_VALUE(st8_105_0, 178)  \
	ENUM_VALUE(st8_106_0, 179)  \
	ENUM_VALUE(st8_107_0, 180)  \
	ENUM_VALUE(st8_108_0, 181)  \
	ENUM_VALUE(st8_109_0, 182)  \
	ENUM_VALUE(st8_110_0, 183)  \
	ENUM_VALUE(st8_111_0, 184)  \
	ENUM_VALUE(st8_112_0, 185)  \
	ENUM_VALUE(st8_113_0, 186)  \
	ENUM_VALUE(st8_114_0, 187)  \
	ENUM_VALUE(st8_115_0, 188)  \
	ENUM_VALUE(st8_201_0, 189)  \
	ENUM_VALUE(st8_202_0, 190)  \
	ENUM_VALUE(st8_203_0, 191)  \
	ENUM_VALUE(st8_301_0, 192)  \
	ENUM_VALUE(st8_302_0, 193)  \
	ENUM_VALUE(st8_303_0, 194)  \
	ENUM_VALUE(st8_304_0, 195)  \
	ENUM_VALUE(st8_305_0, 196)  \
	ENUM_VALUE(st8_306_0, 197)  \
	ENUM_VALUE(st8_307_0, 198)  \
	ENUM_VALUE(st8_308_0, 199)  \
	ENUM_VALUE(st8_309_0, 200)  \
	ENUM_VALUE(st8_310_0, 201)  \
	ENUM_VALUE(st8_311_0, 202)  \
	ENUM_VALUE(st8_401_0, 203)  \
	ENUM_VALUE(st8_402_0, 204)  \
	ENUM_VALUE(st8_403_0, 205)  \
	ENUM_VALUE(st8_404_0, 206)  \
	ENUM_VALUE(st8_405_0, 207)  \
	ENUM_VALUE(st8_406_0, 208)  \
	ENUM_VALUE(st8_407_0, 209)  \
	ENUM_VALUE(st9_101_0, 210)  \
	ENUM_VALUE(st9_102_0, 211)  \
	ENUM_VALUE(st9_103_0, 212)  \
	ENUM_VALUE(st9_201_0, 213)  \
	ENUM_VALUE(st9_202_0, 214)  \
	ENUM_VALUE(st9_203_0, 215)  \
	ENUM_VALUE(st9_301_0, 216)  \
	ENUM_VALUE(st1_301_0, 217)  \
	ENUM_VALUE(st1_401_0, 218)  \
	ENUM_VALUE(st4_201_0, 219)  \
	ENUM_VALUE(st4_202_0, 220)  \
	ENUM_VALUE(st4_203_0, 221)  \
	ENUM_VALUE(st4_204_0, 222)  \
	ENUM_VALUE(st4_205_0, 223)  \
	ENUM_VALUE(st4_206_0, 224)  \
	ENUM_VALUE(st4_215_0, 225)  \
	ENUM_VALUE(st4_216_0, 226)  \
	ENUM_VALUE(st4_301_0, 227)  \
	ENUM_VALUE(st4_302_0, 228)  \
	ENUM_VALUE(st4_303_0, 229)  \
	ENUM_VALUE(st4_304_0, 230)  \
	ENUM_VALUE(st4_305_0, 231)  \
	ENUM_VALUE(st4_306_0, 232)  \
	ENUM_VALUE(st4_307_0, 233)  \
	ENUM_VALUE(st4_308_0, 234)  \
	ENUM_VALUE(st4_309_0, 235)  \
	ENUM_VALUE(st4_310_0, 236)  \
	ENUM_VALUE(st4_311_0, 237)  \
	ENUM_VALUE(st4_312_0, 238)  \
	ENUM_VALUE(st4_313_0, 239)  \
	ENUM_VALUE(st4_314_0, 240)  \
	ENUM_VALUE(st4_401_0, 241)  \
	ENUM_VALUE(st4_401_1, 242)  \
	ENUM_VALUE(st4_402_0, 243)  \
	ENUM_VALUE(st4_403_0, 244)  \
	ENUM_VALUE(st4_404_0, 245)  \
	ENUM_VALUE(st4_405_0, 246)  \
	ENUM_VALUE(st4_406_0, 247)  \
	ENUM_VALUE(st4_407_0, 248)  \
	ENUM_VALUE(st4_408_0, 249)  \
	ENUM_VALUE(st4_409_0, 250)  \
	ENUM_VALUE(st4_410_0, 251)  \
	ENUM_VALUE(st4_411_0, 252)  \
	ENUM_VALUE(st4_412_0, 253)  \
	ENUM_VALUE(st4_501_0, 254)  \
	ENUM_VALUE(st4_502_0, 255)  \
	ENUM_VALUE(st4_503_0, 256)  \
	ENUM_VALUE(st4_504_0, 257)  \
	ENUM_VALUE(st4_505_0, 258)  \
	ENUM_VALUE(st4_506_0, 259)  \
	ENUM_VALUE(st4_507_0, 260)  \
	ENUM_VALUE(st4_508_0, 261)  \
	ENUM_VALUE(st4_601_0, 262)  \
	ENUM_VALUE(st4_602_0, 263)  \
	ENUM_VALUE(st4_603_0, 264)  \
	ENUM_VALUE(st4_604_0, 265)  \
	ENUM_VALUE(st4_605_0, 266)  \
	ENUM_VALUE(st4_606_0, 267)  \
	ENUM_VALUE(st4_607_0, 268)  \
	ENUM_VALUE(st4_608_0, 269)  \
	ENUM_VALUE(st4_609_0, 270)  \
	ENUM_VALUE(st4_610_0, 271)  \
	ENUM_VALUE(st4_701_0, 272)  \
	ENUM_VALUE(st4_702_0, 273)  \
	ENUM_VALUE(st4_703_0, 274)  \
	ENUM_VALUE(st4_704_0, 275)  \
	ENUM_VALUE(st4_705_0, 276)  \
	ENUM_VALUE(st4_708_0, 277)  \
	ENUM_VALUE(st4_709_0, 278)  \
	ENUM_VALUE(st4_710_0, 279)  \
	ENUM_VALUE(st4_711_0, 280)  \
	ENUM_VALUE(st4_712_0, 281)  \
	ENUM_VALUE(st4_714_0, 282)  \
	ENUM_VALUE(st1_501_0, 283)  \
	ENUM_VALUE(st1_502_0, 284)  \
	ENUM_VALUE(st1_503_0, 285)  \
	ENUM_VALUE(st1_504_0, 286)  \
	ENUM_VALUE(st1_505_0, 287)  \
	ENUM_VALUE(st1_506_0, 288)  \
	ENUM_VALUE(st4_650_0, 289)  \
	ENUM_VALUE(st3_401_0, 290)  \
	ENUM_VALUE(st3_402_0, 291)  \
	ENUM_VALUE(st3_403_0, 292)  \
	ENUM_VALUE(st3_404_0, 293)  \
	ENUM_VALUE(st3_405_0, 294)  \
	ENUM_VALUE(st3_406_0, 295)  \
	ENUM_VALUE(st3_407_0, 296)  \
	ENUM_VALUE(st3_408_0, 297)  \
	ENUM_VALUE(st3_409_0, 298)  \
	ENUM_VALUE(st3_410_0, 299)  \
	ENUM_VALUE(st8_501_0, 300)  \
	ENUM_VALUE(st8_601_0, 301)  \
	ENUM_VALUE(st8_602_0, 302)  \
	ENUM_VALUE(st8_603_0, 303)  \
	ENUM_VALUE(st8_604_0, 304)  \
	ENUM_VALUE(st8_605_0, 305)  \
	ENUM_VALUE(st8_606_0, 306)  \
	ENUM_VALUE(st8_607_0, 307)  \
	ENUM_VALUE(st8_608_0, 308)  \
	ENUM_VALUE(st8_609_0, 309)  \
	ENUM_VALUE(st3_600_0, 310)  \
	ENUM_VALUE(st3_601_0, 311)  \
	ENUM_VALUE(st3_602_0, 312)  \
	ENUM_VALUE(st3_603_0, 313)  \
	ENUM_VALUE(st3_610_0, 314)  \
	ENUM_VALUE(st3_611_0, 315)  \
	ENUM_VALUE(st3_612_0, 316)  \
	ENUM_VALUE(st3_613_0, 317)  \
	ENUM_VALUE(st3_614_0, 318)  \
	ENUM_VALUE(st3_615_0, 319)  \
	ENUM_VALUE(st3_616_0, 320)  \
	ENUM_VALUE(st3_617_0, 321)  \
	ENUM_VALUE(st3_620_0, 322)  \
	ENUM_VALUE(st3_621_0, 323)  \
	ENUM_VALUE(st3_622_0, 324)  \
	ENUM_VALUE(st3_623_0, 325)  \
	ENUM_VALUE(st3_624_0, 326)  \
	ENUM_VALUE(st3_625_0, 327)  \
	ENUM_VALUE(st3_626_0, 328)  \
	ENUM_VALUE(st3_627_0, 329)  \
	ENUM_VALUE(st3_630_0, 330)  \
	ENUM_VALUE(st3_631_0, 331)  \
	ENUM_VALUE(st3_632_0, 332)  \
	ENUM_VALUE(st3_633_0, 333)  \
	ENUM_VALUE(st3_634_0, 334)  \
	ENUM_VALUE(st3_635_0, 335)  \
	ENUM_VALUE(st3_636_0, 336)  \
	ENUM_VALUE(st3_637_0, 337)  \
	ENUM_VALUE(st3_638_0, 338)  \
	ENUM_VALUE(st3_640_0, 339)  \
	ENUM_VALUE(st3_641_0, 340)  \
	ENUM_VALUE(st3_642_0, 341)  \
	ENUM_VALUE(st3_643_0, 342)  \
	ENUM_VALUE(st3_644_0, 343)  \
	ENUM_VALUE(st3_650_0, 344)  \
	ENUM_VALUE(st3_651_0, 345)  \
	ENUM_VALUE(st3_652_0, 346)  \
	ENUM_VALUE(st1_411_0, 347)  \
	ENUM_VALUE(st4_715_0, 348)  \
	ENUM_VALUE(st4_716_0, 349)  \
	ENUM_VALUE(st4_717_0, 350)  \
	ENUM_VALUE(st8_408_0, 351)  \
	ENUM_VALUE(st4_750_0, 352)  \
	ENUM_VALUE(st4_751_0, 353)  \
	ENUM_VALUE(st4_752_0, 354)  \
	ENUM_VALUE(st4_753_0, 355)  \
	ENUM_VALUE(st4_754_0, 356)  \
	ENUM_VALUE(st8_409_0, 357)  \
	ENUM_VALUE(st8_410_0, 358)  \
	ENUM_VALUE(st1_601_0, 359)  \
	ENUM_VALUE(st1_602_0, 360)  \
	ENUM_VALUE(st1_603_0, 361)  \
	ENUM_VALUE(st1_604_0, 362)  \
	ENUM_VALUE(st1_605_0, 363)  \
	ENUM_VALUE(st1_606_0, 364)  \
	ENUM_VALUE(st1_607_0, 365)  \
	ENUM_VALUE(st1_608_0, 366)  \
	ENUM_VALUE(st1_609_0, 367)  \
	ENUM_VALUE(st8_650_0, 368)  \
	ENUM_VALUE(st8_411_0, 369)  \
	ENUM_VALUE(st5_111_0, 370)  \
	ENUM_VALUE(st5_121_0, 371)  \
	ENUM_VALUE(st5_131_0, 372)  \
	ENUM_VALUE(st5_211_0, 373)  \
	ENUM_VALUE(st5_221_0, 374)  \
	ENUM_VALUE(st0_103_0, 375)  \
	ENUM_VALUE(st8_660_0, 376)  \
	ENUM_VALUE(st1_620_0, 377)  \
	ENUM_VALUE(st1_621_0, 378)  \
	ENUM_VALUE(st1_622_0, 379)  \
	ENUM_VALUE(st1_623_0, 380)  \
	ENUM_VALUE(st1_610_0, 381)  \
	ENUM_VALUE(st1_611_0, 382)  \
	ENUM_VALUE(st1_612_0, 383)  \
	ENUM_VALUE(st1_613_0, 384)  \
	ENUM_VALUE(st1_614_0, 385)  \
	ENUM_VALUE(st5_112_0, 386)  \
	ENUM_VALUE(st5_110_0, 387)  \
	ENUM_VALUE(st5_113_0, 388)  \
	ENUM_VALUE(st5_114_0, 389)  \
	ENUM_VALUE(st5_115_0, 390)  \
	ENUM_VALUE(st5_307_0, 391)  \
	ENUM_VALUE(st5_308_0, 392)  \
	ENUM_VALUE(st5_309_0, 393)  \
	ENUM_VALUE(st5_310_0, 394)  \
	ENUM_VALUE(st5_401_0, 395)  \
	ENUM_VALUE(st5_402_0, 396)  \
	ENUM_VALUE(st5_403_0, 397)  \
	ENUM_VALUE(st5_404_0, 398)  \
	ENUM_VALUE(st5_405_0, 399)  \
	ENUM_VALUE(st5_406_0, 400)  \
	ENUM_VALUE(st5_407_0, 401)  \
	ENUM_VALUE(st5_408_0, 402)  \
	ENUM_VALUE(st4_800_0, 403)  \
	ENUM_VALUE(st1_615_0, 404)  \
	ENUM_VALUE(st4_755_0, 405)  \
	ENUM_VALUE(st1_630_0, 406)  \
	ENUM_VALUE(st1_631_0, 407)  \
	ENUM_VALUE(st1_632_0, 408)  \
	ENUM_VALUE(st4_713_0, 409)  \
	ENUM_VALUE(st5_122_0, 410)  \
	ENUM_VALUE(st5_123_0, 411)  \
	ENUM_VALUE(st5_124_0, 412)  \
	ENUM_VALUE(st5_125_0, 413)  \
	ENUM_VALUE(st5_126_0, 414)  \
	ENUM_VALUE(st5_127_0, 415)  \
	ENUM_VALUE(st5_128_0, 416)  \
	ENUM_VALUE(st5_129_0, 417)  \
	ENUM_VALUE(st5_132_0, 418)  \
	ENUM_VALUE(st5_133_0, 419)  \
	ENUM_VALUE(st5_134_0, 420)  \
	ENUM_VALUE(st5_212_0, 421)  \
	ENUM_VALUE(st5_222_0, 422)  \
	ENUM_VALUE(st5_223_0, 423)  \
	ENUM_VALUE(st8_651_0, 424)  \
	ENUM_VALUE(st8_610_0, 425)  \
	ENUM_VALUE(st8_611_0, 426)  \
	ENUM_VALUE(st8_612_0, 427)  \
	ENUM_VALUE(st8_613_0, 428)  \
	ENUM_VALUE(st3_604_0, 429)  \
	ENUM_VALUE(st3_605_0, 430)  \
	ENUM_VALUE(st4_217_0, 431)  \
	ENUM_VALUE(st5_122_1, 432)  \
	ENUM_VALUE(st5_122_2, 433)  \
	ENUM_VALUE(st4_502_0b, 435) \
	ENUM_VALUE(st4_502_0c, 436) \
	ENUM_VALUE(st4_504_0b, 437) \
	ENUM_VALUE(st4_603_0b, 438) \
	ENUM_VALUE(st4_206_0b, 439) \
	ENUM_VALUE(st4_309_0b, 440) \
	ENUM_VALUE(st4_603_0c, 441) \
	ENUM_VALUE(st4_750_0b, 442) \
	ENUM_VALUE(st3_603_0b, 443) \
	ENUM_VALUE(st3_611_0b, 444) \
	ENUM_VALUE(st3_613_0b, 445) \
	ENUM_VALUE(st3_613_0c, 446) \
	ENUM_VALUE(st3_623_0b, 447) \
	ENUM_VALUE(st3_630_0b, 448) \
	ENUM_VALUE(st3_630_0c, 449) \
	ENUM_VALUE(st3_630_0d, 450) \
	ENUM_VALUE(st4_750_0c, 451) \
	ENUM_VALUE(st4_751_0b, 452) \
	ENUM_VALUE(st4_701_0b, 453) \
	ENUM_VALUE(st4_701_0c, 454) \
	ENUM_VALUE(st4_714_0b, 455) \
	ENUM_VALUE(st4_608_0b, 456) \
	ENUM_VALUE(st1_601_0b, 457) \
	ENUM_VALUE(st4_404_0b, 458) \
	ENUM_VALUE(st3_600_0b, 459) \
	ENUM_VALUE(st3_602_0b, 460) \
	ENUM_VALUE(st3_627_0b, 461) \
	ENUM_VALUE(st3_627_0c, 462) \
	ENUM_VALUE(st3_627_0d, 463) \
	ENUM_VALUE(st4_704_0b, 464) \
	ENUM_VALUE(st4_750_0d, 465) \
	ENUM_VALUE(st4_751_0c, 466) \
	ENUM_VALUE(st4_751_0d, 467) \
	ENUM_VALUE(st4_751_0e, 468) \
	ENUM_VALUE(st4_751_0f, 469) \
	ENUM_VALUE(st1_630_0b, 470) \
	ENUM_VALUE(st1_630_0c, 471) \
	ENUM_VALUE(st1_631_0b, 472) \
	ENUM_VALUE(st1_632_0b, 473) \
	ENUM_VALUE(st1_632_0c, 474) \
	ENUM_VALUE(st1_632_0d, 475) \
	ENUM_VALUE(st1_621_0b, 476) \
	ENUM_VALUE(st1_623_0b, 477) \
	ENUM_VALUE(st5_122_0b, 478) \
	ENUM_VALUE(st5_211_0b, 479) \
	ENUM_VALUE(st5_211_0c, 480) \
	ENUM_VALUE(st5_203_0b, 481) \
	ENUM_VALUE(st4_201_0b, 482) \
	ENUM_VALUE(st4_201_0c, 483) \
	ENUM_VALUE(st4_201_0d, 484) \
	ENUM_VALUE(st4_201_0e, 485) \
	ENUM_VALUE(st4_201_0f, 486) \
	ENUM_VALUE(st3_640_0b, 487) \
	ENUM_VALUE(st3_616_0b, 488) \
	ENUM_VALUE(st3_616_0c, 489) \
	ENUM_VALUE(st3_635_0b, 490) \
	ENUM_VALUE(st3_635_0c, 491) \
	ENUM_VALUE(st3_635_0d, 492) \
	ENUM_VALUE(st3_635_0e, 493) \
	ENUM_VALUE(st3_617_0b, 494) \
	ENUM_VALUE(st3_641_0b, 495) \
	ENUM_VALUE(st3_614_0b, 496) \
	ENUM_VALUE(st5_211_0d, 497) \
	ENUM_VALUE(st5_125_0b, 498) \
	ENUM_VALUE(st3_615_0b, 499) \
	ENUM_VALUE(st5_101_0b, 500) \
	ENUM_VALUE(st5_133_0b, 501) \
	ENUM_VALUE(st5_204_0b, 502) \
	ENUM_VALUE(st5_211_0e, 503) \
	ENUM_VALUE(st5_212_0b, 504) \
	ENUM_VALUE(dummy070, 505)   \
	ENUM_VALUE(dummy071, 506)   \
	ENUM_VALUE(dummy072, 507)   \
	ENUM_VALUE(dummy073, 508)   \
	ENUM_VALUE(dummy074, 509)   \
	ENUM_VALUE(dummy075, 510)   \
	ENUM_VALUE(dummy076, 511)   \
	ENUM_VALUE(dummy077, 512)   \
	ENUM_VALUE(dummy078, 513)   \
	ENUM_VALUE(dummy079, 514)   \
	ENUM_VALUE(dummy080, 515)   \
	ENUM_VALUE(dummy081, 516)   \
	ENUM_VALUE(dummy082, 517)   \
	ENUM_VALUE(dummy083, 518)   \
	ENUM_VALUE(dummy084, 519)   \
	ENUM_VALUE(dummy085, 520)   \
	ENUM_VALUE(dummy086, 521)   \
	ENUM_VALUE(dummy087, 522)   \
	ENUM_VALUE(dummy088, 523)   \
	ENUM_VALUE(dummy089, 524)   \
	ENUM_VALUE(dummy090, 525)   \
	ENUM_VALUE(dummy091, 526)   \
	ENUM_VALUE(dummy092, 527)   \
	ENUM_VALUE(dummy093, 528)   \
	ENUM_VALUE(dummy094, 529)   \
	ENUM_VALUE(dummy095, 530)   \
	ENUM_VALUE(dummy096, 531)   \
	ENUM_VALUE(dummy097, 532)   \
	ENUM_VALUE(dummy098, 533)   \
	ENUM_VALUE(dummy099, 534)   \
	ENUM_VALUE(dummy100, 535)   \
	ENUM_VALUE(dummy101, 536)   \
	ENUM_VALUE(dummy102, 537)   \
	ENUM_VALUE(dummy103, 538)   \
	ENUM_VALUE(dummy104, 539)   \
	ENUM_VALUE(dummy105, 540)   \
	ENUM_VALUE(dummy106, 541)   \
	ENUM_VALUE(dummy107, 542)   \
	ENUM_VALUE(dummy108, 543)   \
	ENUM_VALUE(dummy109, 544)   \
	ENUM_VALUE(dummy110, 545)   \
	ENUM_VALUE(dummy111, 546)   \
	ENUM_VALUE(dummy112, 547)   \
	ENUM_VALUE(dummy113, 548)   \
	ENUM_VALUE(dummy114, 549)   \
	ENUM_VALUE(dummy115, 550)   \
	ENUM_VALUE(dummy116, 551)   \
	ENUM_VALUE(dummy117, 552)   \
	ENUM_VALUE(dummy118, 553)   \
	ENUM_VALUE(dummy119, 554)   \
	ENUM_VALUE(dummy120, 555)   \
	ENUM_VALUE(dummy121, 556)   \
	ENUM_VALUE(dummy122, 557)   \
	ENUM_VALUE(dummy123, 558)   \
	ENUM_VALUE(dummy124, 559)   \
	ENUM_VALUE(dummy125, 560)   \
	ENUM_VALUE(dummy126, 561)   \
	ENUM_VALUE(dummy127, 562)   \
	ENUM_VALUE(MAP_PARTS_NUM, 563)
#ifdef RE2RR_TYPES_CPP
#include "../src/Types_Enum.cpp"
#else
#include "Types_Enum.h"
#endif
#undef ENUM_LIST
#undef ENUM_TYPE
#undef ENUM_NAME
#endif
//

// Enum FloorID (app.ropeway.gamemastering.Floor.ID)
// Changed invalid to None.
#ifndef RE2RR_TYPES_H_FloorID
#define RE2RR_TYPES_H_FloorID
#define ENUM_NAME FloorID
#define ENUM_TYPE int32_t
#define ENUM_LIST                       \
	ENUM_VALUE(None, 0)                 \
	ENUM_VALUE(RPD_A, 1)                \
	ENUM_VALUE(RPD_B, 2)                \
	ENUM_VALUE(RPD_C, 3)                \
	ENUM_VALUE(RPD_D, 4)                \
	ENUM_VALUE(RPD_E, 5)                \
	ENUM_VALUE(RPD_A_SECRET, 6)         \
	ENUM_VALUE(RPD_B_SECRET, 7)         \
	ENUM_VALUE(RPD_E_SECRET, 8)         \
	ENUM_VALUE(WaterPlant_A, 9)         \
	ENUM_VALUE(WaterPlant_B, 10)        \
	ENUM_VALUE(WaterPlant_C, 11)        \
	ENUM_VALUE(WasteWater_A, 12)        \
	ENUM_VALUE(WasteWater_B, 13)        \
	ENUM_VALUE(WasteWater_C, 14)        \
	ENUM_VALUE(WasteWater_A_SECRET, 15) \
	ENUM_VALUE(WasteWater_B_SECRET, 16) \
	ENUM_VALUE(WasteWater_C_SECRET, 17) \
	ENUM_VALUE(CityArea_A, 18)          \
	ENUM_VALUE(CityArea_B, 19)          \
	ENUM_VALUE(OrphanAsylum_A, 20)      \
	ENUM_VALUE(OrphanAsylum_B, 21)      \
	ENUM_VALUE(OrphanAsylum_C, 22)      \
	ENUM_VALUE(Laboratory_A, 23)        \
	ENUM_VALUE(Laboratory_A2, 24)       \
	ENUM_VALUE(Laboratory_A3, 25)       \
	ENUM_VALUE(Laboratory_B, 26)        \
	ENUM_VALUE(Laboratory_B2, 27)       \
	ENUM_VALUE(Laboratory_C, 28)        \
	ENUM_VALUE(Laboratory_D, 29)        \
	ENUM_VALUE(Laboratory_D2, 30)       \
	ENUM_VALUE(Laboratory_D3, 31)       \
	ENUM_VALUE(Laboratory_D4, 32)       \
	ENUM_VALUE(FLOOR_NUM, 33)
#ifdef RE2RR_TYPES_CPP
#include "../src/Types_Enum.cpp"
#else
#include "Types_Enum.h"
#endif
#undef ENUM_LIST
#undef ENUM_TYPE
#undef ENUM_NAME
#endif
//

// Enum ItemType
#ifndef RE2RR_TYPES_H_ItemType
#define RE2RR_TYPES_H_ItemType
#define ENUM_NAME ItemType
#define ENUM_TYPE int32_t
#define ENUM_LIST                                   \
	ENUM_VALUE(None, 0x00)                          \
	ENUM_VALUE(FirstAidSpray, 0x01)                 \
	ENUM_VALUE(Herb_Green1, 0x02)                   \
	ENUM_VALUE(Herb_Red1, 0x03)                     \
	ENUM_VALUE(Herb_Blue1, 0x04)                    \
	ENUM_VALUE(Herb_Mixed_GG, 0x05)                 \
	ENUM_VALUE(Herb_Mixed_GR, 0x06)                 \
	ENUM_VALUE(Herb_Mixed_GB, 0x07)                 \
	ENUM_VALUE(Herb_Mixed_GGB, 0x08)                \
	ENUM_VALUE(Herb_Mixed_GGG, 0x09)                \
	ENUM_VALUE(Herb_Mixed_GRB, 0x0A)                \
	ENUM_VALUE(Herb_Mixed_RB, 0x0B)                 \
	ENUM_VALUE(Herb_Green2, 0x0C)                   \
	ENUM_VALUE(Herb_Red2, 0x0D)                     \
	ENUM_VALUE(Herb_Blue2, 0x0E)                    \
	ENUM_VALUE(HandgunBullets, 0x0F)                \
	ENUM_VALUE(ShotgunShells, 0x10)                 \
	ENUM_VALUE(SubmachineGunAmmo, 0x11)             \
	ENUM_VALUE(MAGAmmo, 0x12)                       \
	ENUM_VALUE(ErrorBox, 0x13)                      \
	ENUM_VALUE(GrenadeAcidRounds, 0x16)             \
	ENUM_VALUE(GrenadeFlameRounds, 0x17)            \
	ENUM_VALUE(NeedleCartridges, 0x18)              \
	ENUM_VALUE(Fuel, 0x19)                          \
	ENUM_VALUE(HandgunLargeCaliberAmmo, 0x1A)       \
	ENUM_VALUE(SLS60HighPoweredRounds, 0x1B)        \
	ENUM_VALUE(Detonator, 0x1F)                     \
	ENUM_VALUE(InkRibbon, 0x20)                     \
	ENUM_VALUE(WoodenBoard, 0x21)                   \
	ENUM_VALUE(ElectronicGadget, 0x22)              \
	ENUM_VALUE(Battery9Volt, 0x23)                  \
	ENUM_VALUE(Gunpowder, 0x24)                     \
	ENUM_VALUE(GunpowderLarge, 0x25)                \
	ENUM_VALUE(GunpowderHighGradeYellow, 0x26)      \
	ENUM_VALUE(GunpowderHighGradeWhite, 0x27)       \
	ENUM_VALUE(MatildaHighCapacityMagazine, 0x30)   \
	ENUM_VALUE(MatildaMuzzleBrake, 0x31)            \
	ENUM_VALUE(MatildaGunStock, 0x32)               \
	ENUM_VALUE(SLS60SpeedLoader, 0x33)              \
	ENUM_VALUE(JMBHp3LaserSight, 0x34)              \
	ENUM_VALUE(SLS60ReinforcedFrame, 0x35)          \
	ENUM_VALUE(JMBHp3HighCapacityMagazine, 0x36)    \
	ENUM_VALUE(W870ShotgunStock, 0x37)              \
	ENUM_VALUE(W870LongBarrel, 0x38)                \
	ENUM_VALUE(MQ11HighCapacityMagazine, 0x3A)      \
	ENUM_VALUE(MQ11Suppressor, 0x3C)                \
	ENUM_VALUE(LightningHawkRedDotSight, 0x3D)      \
	ENUM_VALUE(LightningHawkLongBarrel, 0x3E)       \
	ENUM_VALUE(GM79ShoulderStock, 0x40)             \
	ENUM_VALUE(FlamethrowerRegulator, 0x41)         \
	ENUM_VALUE(SparkShotHighVoltageCondenser, 0x42) \
	ENUM_VALUE(Film_HidingPlace, 0x48)              \
	ENUM_VALUE(Film_RisingRookie, 0x49)             \
	ENUM_VALUE(Film_Commemorative, 0x4A)            \
	ENUM_VALUE(Film_3FLocker, 0x4B)                 \
	ENUM_VALUE(Film_LionStatue, 0x4C)               \
	ENUM_VALUE(KeyStorageRoom, 0x4D)                \
	ENUM_VALUE(JackHandle, 0x4F)                    \
	ENUM_VALUE(SquareCrank, 0x50)                   \
	ENUM_VALUE(MedallionUnicorn, 0x51)              \
	ENUM_VALUE(KeySpade, 0x52)                      \
	ENUM_VALUE(KeyCardParkingGarage, 0x53)          \
	ENUM_VALUE(KeyCardWeaponsLocker, 0x54)          \
	ENUM_VALUE(ValveHandle, 0x56)                   \
	ENUM_VALUE(STARSBadge, 0x57)                    \
	ENUM_VALUE(Scepter, 0x58)                       \
	ENUM_VALUE(RedJewel, 0x5A)                      \
	ENUM_VALUE(BejeweledBox, 0x5B)                  \
	ENUM_VALUE(PlugBishop, 0x5D)                    \
	ENUM_VALUE(PlugRook, 0x5E)                      \
	ENUM_VALUE(PlugKing, 0x5F)                      \
	ENUM_VALUE(PictureBlock, 0x62)                  \
	ENUM_VALUE(USBDongleKey, 0x66)                  \
	ENUM_VALUE(SpareKey, 0x70)                      \
	ENUM_VALUE(RedBook, 0x72)                       \
	ENUM_VALUE(StatuesLeftArm, 0x73)                \
	ENUM_VALUE(StatuesLeftArmWithRedBook, 0x74)     \
	ENUM_VALUE(MedallionLion, 0x76)                 \
	ENUM_VALUE(KeyDiamond, 0x77)                    \
	ENUM_VALUE(KeyCar, 0x78)                        \
	ENUM_VALUE(MedallionMaiden, 0x7C)               \
	ENUM_VALUE(PowerPanelPart1, 0x7E)               \
	ENUM_VALUE(PowerPanelPart2, 0x7F)               \
	ENUM_VALUE(LoversRelief, 0x80)                  \
	ENUM_VALUE(GearSmall, 0x81)                     \
	ENUM_VALUE(GearLarge, 0x82)                     \
	ENUM_VALUE(KeyCourtyard, 0x83)                  \
	ENUM_VALUE(PlugKnight, 0x84)                    \
	ENUM_VALUE(PlugPawn, 0x85)                      \
	ENUM_VALUE(PlugQueen, 0x86)                     \
	ENUM_VALUE(BoxedElectronicPart1, 0x87)          \
	ENUM_VALUE(BoxedElectronicPart2, 0x88)          \
	ENUM_VALUE(KeyOrphanage, 0x9F)                  \
	ENUM_VALUE(KeyClub, 0xA0)                       \
	ENUM_VALUE(KeyHeart, 0xA9)                      \
	ENUM_VALUE(USSDigitalVideoCassette, 0xAA)       \
	ENUM_VALUE(TBarValveHandle, 0xB0)               \
	ENUM_VALUE(DispersalCartridgeEmpty, 0xB3)       \
	ENUM_VALUE(DispersalCartridgeSolution, 0xB4)    \
	ENUM_VALUE(DispersalCartridgeHerbicide, 0xB5)   \
	ENUM_VALUE(JointPlug, 0xB7)                     \
	ENUM_VALUE(UpgradeChipAdministrator, 0xBA)      \
	ENUM_VALUE(IDWristbandAdministrator, 0xBB)      \
	ENUM_VALUE(ElectronicChip, 0xBC)                \
	ENUM_VALUE(SignalModulator, 0xBD)               \
	ENUM_VALUE(Trophy1, 0xBE)                       \
	ENUM_VALUE(Trophy2, 0xBF)                       \
	ENUM_VALUE(KeySewers, 0xC2)                     \
	ENUM_VALUE(IDWristbandVisitor1, 0xC3)           \
	ENUM_VALUE(IDWristbandGeneralStaff1, 0xC4)      \
	ENUM_VALUE(IDWristbandSeniorStaff1, 0xC5)       \
	ENUM_VALUE(UpgradeChipGeneralStaff, 0xC6)       \
	ENUM_VALUE(UpgradeChipSeniorStaff, 0xC7)        \
	ENUM_VALUE(IDWristbandVisitor2, 0xC8)           \
	ENUM_VALUE(IDWristbandGeneralStaff2, 0xC9)      \
	ENUM_VALUE(IDWristbandSeniorStaff2, 0xCA)       \
	ENUM_VALUE(LabDigitalVideoCassette, 0xCB)       \
	ENUM_VALUE(Briefcase, 0xE6)                     \
	ENUM_VALUE(FuseMainHall, 0xF0)                  \
	ENUM_VALUE(FuseBreakRoom, 0xF1)                 \
	ENUM_VALUE(Scissors, 0xF3)                      \
	ENUM_VALUE(BoltCutter, 0xF4)                    \
	ENUM_VALUE(StuffedDoll, 0xF5)                   \
	ENUM_VALUE(HipPouch, 0x0106)                    \
	ENUM_VALUE(OldKey, 0x011E)                      \
	ENUM_VALUE(PortableSafe, 0x0123)                \
	ENUM_VALUE(TinStorageBox1, 0x0125)              \
	ENUM_VALUE(WoodenBox1, 0x0126)                  \
	ENUM_VALUE(WoodenBox2, 0x0127)                  \
	ENUM_VALUE(TinStorageBox2, 0x0128)
#ifdef RE2RR_TYPES_CPP
#include "../src/Types_Enum.cpp"
#else
#include "Types_Enum.h"
#endif
#undef ENUM_LIST
#undef ENUM_TYPE
#undef ENUM_NAME
#endif
//

// Enum WeaponType
#ifndef RE2RR_TYPES_H_WeaponType
#define RE2RR_TYPES_H_WeaponType
#define ENUM_NAME WeaponType
#define ENUM_TYPE int32_t
#define ENUM_LIST                                       \
	ENUM_VALUE(None, (int32_t)0xFFFFFFFF)               \
	ENUM_VALUE(Handgun_Matilda, 0x01)                   \
	ENUM_VALUE(Handgun_M19, 0x02)                       \
	ENUM_VALUE(Handgun_JMB_Hp3, 0x03)                   \
	ENUM_VALUE(Handgun_Quickdraw_Army, 0x04)            \
	ENUM_VALUE(Handgun_MUP, 0x07)                       \
	ENUM_VALUE(Handgun_BroomHc, 0x08)                   \
	ENUM_VALUE(Handgun_SLS60, 0x09)                     \
	ENUM_VALUE(Shotgun_W870, 0x0B)                      \
	ENUM_VALUE(SMG_MQ11, 0x15)                          \
	ENUM_VALUE(SMG_LE5_Infinite, 0x17)                  \
	ENUM_VALUE(Handgun_LightningHawk, 0x1F)             \
	ENUM_VALUE(EMF_Visualizer, 0x29)                    \
	ENUM_VALUE(GrenadeLauncher_GM79, 0x2A)              \
	ENUM_VALUE(ChemicalFlamethrower, 0x2B)              \
	ENUM_VALUE(SparkShot, 0x2C)                         \
	ENUM_VALUE(ATM4, 0x2D)                              \
	ENUM_VALUE(CombatKnife, 0x2E)                       \
	ENUM_VALUE(CombatKnife_Infinite, 0x2F)              \
	ENUM_VALUE(AntiTankRocketLauncher, 0x31)            \
	ENUM_VALUE(Minigun, 0x32)                           \
	ENUM_VALUE(HandGrenade, 0x41)                       \
	ENUM_VALUE(FlashGrenade, 0x42)                      \
	ENUM_VALUE(Handgun_SamuraiEdge_Infinite, 0x52)      \
	ENUM_VALUE(Handgun_SamuraiEdge_ChrisRedfield, 0x53) \
	ENUM_VALUE(Handgun_SamuraiEdge_JillValentine, 0x54) \
	ENUM_VALUE(Handgun_SamuraiEdge_AlbertWesker, 0x55)  \
	ENUM_VALUE(ATM4_Infinite, 0xDE)                     \
	ENUM_VALUE(AntiTankRocketLauncher_Infinite, 0xF2)   \
	ENUM_VALUE(Minigun_Infinite, 0xFC)
#ifdef RE2RR_TYPES_CPP
#include "../src/Types_Enum.cpp"
#else
#include "Types_Enum.h"
#endif
#undef ENUM_LIST
#undef ENUM_TYPE
#undef ENUM_NAME
#endif
//

struct PACKED_DATA via_vec3
{
	float x; // 0x00-0x0F
	float y; // 0x10-0x13
	float z; // 0x14-0x17

	std::unique_ptr<std::string> ToString() const
	{
		const char *toStringFormat = ".%s = %f, .%s = %f, .%s = %f";

		int bufferSize = snprintf(NULL, 0, toStringFormat,
		                          NAMEOF(x), x,
		                          NAMEOF(y), y,
		                          NAMEOF(z), z) +
		                 1;
		std::unique_ptr<char[]> toString = std::make_unique<char[]>(bufferSize);
		snprintf(toString.get(), bufferSize, toStringFormat,
		         NAMEOF(x), x,
		         NAMEOF(y), y,
		         NAMEOF(z), z);

		return std::make_unique<std::string>(toString.get());
	}
};

struct PACKED_DATA app_ropeway_MansionManager_MapIdentifier
{
	uint8_t _Reserved[0x10];  // 0x00-0x0F
	RE2RREnums::MapID ID;     // 0x10-0x13
	RE2RREnums::MapArea Area; // 0x14-0x17

	std::unique_ptr<std::string> ToString() const
	{
		const char *toStringFormat = ".%s = %s, .%s = %s";

		int bufferSize = snprintf(NULL, 0, toStringFormat,
		                          NAMEOF(ID), RE2RREnums::EnumMapIDToString(ID).get()->c_str(),
		                          NAMEOF(Area), RE2RREnums::EnumMapAreaToString(Area).get()->c_str()) +
		                 1;
		std::unique_ptr<char[]> toString = std::make_unique<char[]>(bufferSize);
		snprintf(toString.get(), bufferSize, toStringFormat,
		         NAMEOF(ID), RE2RREnums::EnumMapIDToString(ID).get()->c_str(),
		         NAMEOF(Area), RE2RREnums::EnumMapAreaToString(Area).get()->c_str());

		return std::make_unique<std::string>(toString.get());
	}
};

typedef struct PACKED_DATA app_ropeway_gamemastering_InventoryManager_PrimitiveItem
{
	// uint8_t _Reserved[0x10]; // 0x00-0x0F
	RE2RREnums::ItemType ItemId;     // 0x10-0x13
	RE2RREnums::WeaponType WeaponId; // 0x14-0x17
	int32_t WeaponParts;             // 0x18-0x1B
	int32_t BulletId;                // 0x1C-0x1F
	int32_t Count;                   // 0x20-0x23

	std::unique_ptr<std::string> ToString() const
	{
		const char *toStringFormat = ".%s = %s, .%s = %s, .%s = %d, .%s = %d, .%s = %d";

		int bufferSize = snprintf(NULL, 0, toStringFormat,
		                          NAMEOF(ItemId), RE2RREnums::EnumItemTypeToString(ItemId).get()->c_str(),
		                          NAMEOF(WeaponId), RE2RREnums::EnumWeaponTypeToString(WeaponId).get()->c_str(),
		                          NAMEOF(WeaponParts), WeaponParts,
		                          NAMEOF(BulletId), BulletId,
		                          NAMEOF(Count), Count) +
		                 1;
		std::unique_ptr<char[]> toString = std::make_unique<char[]>(bufferSize);
		snprintf(toString.get(), bufferSize, toStringFormat,
		         NAMEOF(ItemId), RE2RREnums::EnumItemTypeToString(ItemId).get()->c_str(),
		         NAMEOF(WeaponId), RE2RREnums::EnumWeaponTypeToString(WeaponId).get()->c_str(),
		         NAMEOF(WeaponParts), WeaponParts,
		         NAMEOF(BulletId), BulletId,
		         NAMEOF(Count), Count);

		return std::make_unique<std::string>(toString.get());
	}
} RE2RItem;
bool operator==(const RE2RItem &, const RE2RItem &);

struct GameModeKey
{
	RE2RREnums::Scenario Scenario;
	RE2RREnums::Difficulty Difficulty;
};
bool operator==(const GameModeKey &lhs, const GameModeKey &rhs);

namespace std
{
	template <>
	struct hash<GUID>
	{
		size_t operator()(const GUID &guid) const noexcept
		{
			const uint64_t *p = reinterpret_cast<const uint64_t *>(&guid);
			std::hash<uint64_t> hash;
			return hash(p[0]) ^ hash(p[1]);
		}
	};

	template <>
	struct equal_to<GUID>
	{
		bool operator()(const GUID &lhs, const GUID &rhs) const noexcept
		{
			return lhs.Data1 == rhs.Data1 &&
			       lhs.Data2 == rhs.Data2 &&
			       lhs.Data3 == rhs.Data3 &&
			       std::equal(std::begin(lhs.Data4), std::end(lhs.Data4), std::begin(rhs.Data4));
		}
	};

	template <>
	struct hash<RE2RItem>
	{
		size_t operator()(const RE2RItem &item) const noexcept
		{
			const int32_t *p = reinterpret_cast<const int32_t *>(&item);
			std::hash<int32_t> hash;
			return hash(p[0]) ^ hash(p[1]) ^ hash(p[2]) ^ hash(p[3]) ^ hash(p[4]);
		}
	};

	template <>
	struct equal_to<RE2RItem>
	{
		bool operator()(const RE2RItem &lhs, const RE2RItem &rhs) const noexcept
		{
			return lhs.ItemId == rhs.ItemId &&
			       lhs.WeaponId == rhs.WeaponId &&
			       lhs.WeaponParts == rhs.WeaponParts &&
			       lhs.BulletId == rhs.BulletId &&
			       lhs.Count == rhs.Count;
		}
	};

	template <>
	struct hash<GameModeKey>
	{
		size_t operator()(const GameModeKey &key) const
		{
			size_t res = 17;

			res = res * 31 + hash<int32_t>()(static_cast<int32_t>(key.Scenario));
			res = res * 31 + hash<int32_t>()(static_cast<int32_t>(key.Difficulty));

			return res;
		}
	};
}

struct RandomizedItem
{
	GUID OriginalGUID;
	RE2RItem ReplacementItem;
};
bool operator==(const RandomizedItem &lhs, const RandomizedItem &rhs);

struct Seed
{
	GameModeKey gameMode;
	std::unordered_map<GUID, RandomizedItem, std::hash<GUID>, std::equal_to<GUID>> seedData;
};
bool operator==(const Seed &lhs, const Seed &rhs);

#endif
