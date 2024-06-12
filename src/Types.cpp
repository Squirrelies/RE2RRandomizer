#define RE2RR_TYPES_CPP
#include "Types.h"
#undef RE2RR_TYPES_CPP

bool TryStringToGUIDA(const std::string &stringGUID, const GUID &guid)
{
	return UuidFromStringA((unsigned char *)stringGUID.c_str(), (UUID *)&guid) == RPC_S_OK;
}

bool TryStringToGUIDW(const std::wstring &stringGUID, const GUID &guid)
{
	return UuidFromStringW((unsigned short *)stringGUID.c_str(), (UUID *)&guid) == RPC_S_OK;
}

std::unique_ptr<GUID> StringToGUIDA(const std::string &stringGUID)
{
	std::unique_ptr<GUID> returnValue = std::make_unique<GUID>();
	UuidFromStringA((unsigned char *)stringGUID.c_str(), (UUID *)returnValue.get());
	return returnValue;
}

std::unique_ptr<GUID> StringToGUIDW(const std::wstring &stringGUID)
{
	std::unique_ptr<GUID> returnValue = std::make_unique<GUID>();
	UuidFromStringW((unsigned short *)stringGUID.c_str(), (UUID *)returnValue.get());
	return returnValue;
}

bool operator==(const RE2RItem &lhs, const RE2RItem &rhs)
{
	return lhs.ItemId == rhs.ItemId &&
	       lhs.WeaponId == rhs.WeaponId &&
	       lhs.WeaponParts == rhs.WeaponParts &&
	       lhs.BulletId == rhs.BulletId &&
	       lhs.Count == rhs.Count;
}

bool operator==(const GameModeKey &lhs, const GameModeKey &rhs)
{
	return lhs.Scenario == rhs.Scenario &&
	       lhs.Difficulty == rhs.Difficulty;
}

bool operator==(const RandomizedItem &lhs, const RandomizedItem &rhs)
{
	return lhs.OriginalGUID == rhs.OriginalGUID &&
	       lhs.ReplacementItem == rhs.ReplacementItem;
}

bool operator==(const Seed &lhs, const Seed &rhs)
{
	return lhs.gameMode == rhs.gameMode &&
	       lhs.seedData == rhs.seedData;
}
