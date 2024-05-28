#define RE2RR_TYPES_CPP
#include "Types.h"
#undef RE2RR_TYPES_CPP

bool TryStringToGUIDA(const std::string &stringGUID, GUID &guid)
{
	return UuidFromStringA((unsigned char *)stringGUID.c_str(), (UUID *)&guid) == RPC_S_OK;
}

bool TryStringToGUIDW(const std::wstring &stringGUID, GUID &guid)
{
	return UuidFromStringW((unsigned short *)stringGUID.c_str(), (UUID *)&guid) == RPC_S_OK;
}

GUID *StringToGUIDA(const std::string &stringGUID)
{
	GUID *returnValue = new GUID();
	UuidFromStringA((unsigned char *)stringGUID.c_str(), (UUID *)returnValue);
	return returnValue;
}

GUID *StringToGUIDW(const std::wstring &stringGUID)
{
	GUID *returnValue = new GUID();
	UuidFromStringW((unsigned short *)stringGUID.c_str(), (UUID *)returnValue);
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

bool operator==(const Seed &lhs, const Seed &rhs)
{
	return lhs.gameMode == rhs.gameMode &&
	       lhs.seedData == rhs.seedData;
}
