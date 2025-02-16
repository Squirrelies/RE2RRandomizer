#include "Strings.h"

namespace RE2RR::Common::Strings
{
	size_t GetStringSizeA(std::string string)
	{
		return (string.length() * sizeof(char)) + sizeof(char);
	}

	size_t GetStringSizeW(std::wstring string)
	{
		return (string.length() * sizeof(wchar_t)) + sizeof(wchar_t);
	}
}
