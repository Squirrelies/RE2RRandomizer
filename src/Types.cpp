#define RE2RR_TYPES_CPP
#include "Types.h"
#undef RE2RR_TYPES_CPP

bool StringToGUIDA(const std::string &stringGUID, GUID &guid)
{
	return UuidFromStringA((unsigned char *)stringGUID.c_str(), (UUID *)&guid) == RPC_S_OK;
}

bool StringToGUIDW(const std::wstring &stringGUID, GUID &guid)
{
	return UuidFromStringW((unsigned short *)stringGUID.c_str(), (UUID *)&guid) == RPC_S_OK;
}
