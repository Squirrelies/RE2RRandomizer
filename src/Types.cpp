// Enum Character
#ifndef RE2RR_TYPES_H_Character
#define RE2RR_TYPES_H_Character
#define ENUM_NAME Character
#define ENUM_TYPE uint8_t
#define ENUM_LIST       \
	ENUM_VALUE(Leon, 0) \
	ENUM_VALUE(Claire, 1)
#include "Types_Enum.cpp"
#undef ENUM_LIST
#undef ENUM_TYPE
#undef ENUM_NAME
#endif
//

// Enum Scenario
#ifndef RE2RR_TYPES_H_Scenario
#define RE2RR_TYPES_H_Scenario
#define ENUM_NAME Scenario
#define ENUM_TYPE uint8_t
#define ENUM_LIST    \
	ENUM_VALUE(A, 0) \
	ENUM_VALUE(B, 1)
#include "Types_Enum.cpp"
#undef ENUM_LIST
#undef ENUM_TYPE
#undef ENUM_NAME
#endif
//

// Enum Difficulty
#ifndef RE2RR_TYPES_H_Difficulty
#define RE2RR_TYPES_H_Difficulty
#define ENUM_NAME Difficulty
#define ENUM_TYPE uint8_t
#define ENUM_LIST           \
	ENUM_VALUE(Standard, 0) \
	ENUM_VALUE(Hardcore, 1)
#include "Types_Enum.cpp"
#undef ENUM_LIST
#undef ENUM_TYPE
#undef ENUM_NAME
#endif
//

// Enum ItemType
#ifndef RE2RR_TYPES_H_ItemType
#define RE2RR_TYPES_H_ItemType
#define ENUM_NAME ItemType
#define ENUM_TYPE uint32_t
#define ENUM_LIST                                   \
	ENUM_VALUE(None, 0)                             \
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
#include "Types_Enum.cpp"
#undef ENUM_LIST
#undef ENUM_TYPE
#undef ENUM_NAME
#endif
//
