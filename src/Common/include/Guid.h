//-------------------------------------------------------------------------------------------------------
// constexpr GUID parsing
// Written by Alexander Bessonov
// Modified by Travis J. Gutjahr
//
// Licensed under the MIT license.
//-------------------------------------------------------------------------------------------------------

#ifndef RE2RR_GUID_H
#define RE2RR_GUID_H

#include "Common.h"
#include <assert.h>
#include <stdexcept>
#include <stdint.h>
#include <string>

namespace RE2RR::Common::Guid
{
	constexpr const size_t short_guid_form_length = 36; // XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX

	constexpr int ParseHexChar(const char c)
	{
		using namespace std::string_literals;
		if ('0' <= c && c <= '9')
			return c - '0';
		else if ('a' <= c && c <= 'f')
			return 10 + c - 'a';
		else if ('A' <= c && c <= 'F')
			return 10 + c - 'A';
		else
			throw std::domain_error{"Invalid character in GUID"s};
	}

	template <class T>
	constexpr T ParseHexType(const char *ptr)
	{
		constexpr size_t digits = sizeof(T) * 2;
		T result{};
		for (size_t i = 0; i < digits; ++i)
			result |= ParseHexChar(ptr[i]) << (4 * (digits - i - 1));
		return result;
	}

	constexpr GUID CreateHelper(const char *begin)
	{
		GUID result{};
		result.Data1 = ParseHexType<uint32_t>(begin);
		begin += 8 + 1;
		result.Data2 = ParseHexType<uint16_t>(begin);
		begin += 4 + 1;
		result.Data3 = ParseHexType<uint16_t>(begin);
		begin += 4 + 1;
		result.Data4[0] = ParseHexType<uint8_t>(begin);
		begin += 2;
		result.Data4[1] = ParseHexType<uint8_t>(begin);
		begin += 2 + 1;
		for (size_t i = 0; i < 6; ++i)
			result.Data4[i + 2] = ParseHexType<uint8_t>(begin + i * 2);
		return result;
	}

	template <size_t N>
	constexpr GUID Create(const char (&str)[N])
	{
		static_assert(N == (short_guid_form_length + 1), "String GUID of the form XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX is expected");
		return CreateHelper(str);
	}

	inline namespace Guid_Literals
	{
		constexpr GUID operator"" _guid(const char *str, size_t N)
		{
			using namespace std::string_literals;
			if (N != short_guid_form_length)
				throw std::domain_error{"String GUID of the form XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX is expected"s};
			return CreateHelper(str);
		}
	}
}

#endif
