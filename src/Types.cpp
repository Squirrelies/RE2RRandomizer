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

bool operator==(const ItemMapKey &lhs, const ItemMapKey &rhs)
{
	return lhs.ItemPositionGUID == rhs.ItemPositionGUID &&
	       lhs.Scenario == rhs.Scenario &&
	       lhs.Difficulty == rhs.Difficulty;
}
