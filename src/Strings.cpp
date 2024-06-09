#include "Strings.h"

size_t GetStringSizeA(std::string string)
{
	return (string.length() * sizeof(char)) + sizeof(char);
}

size_t GetStringSizeW(std::wstring string)
{
	return (string.length() * sizeof(wchar_t)) + sizeof(wchar_t);
}

const std::string &GUIDToString(const GUID &guid)
{
	char guid_string[(sizeof(GUID) * 2) + 4 + 1]; // (16 bytes (4+2+2+8) * 2 for character representation) + 4 hyphens + 1 null terminator = 37 bytes/chars.

	snprintf(
	    guid_string, sizeof(guid_string),
	    "%08lX-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X",
	    guid.Data1,
	    guid.Data2,
	    guid.Data3,
	    guid.Data4[0], guid.Data4[1],
	    guid.Data4[2], guid.Data4[3], guid.Data4[4], guid.Data4[5], guid.Data4[6], guid.Data4[7]);

	std::string *returnValue = new std::string(guid_string);
	return *returnValue;
}
