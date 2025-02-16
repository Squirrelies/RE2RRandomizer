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
#include "Memory.h"
#include <assert.h>
#include <functional>
#include <stdexcept>
#include <stdint.h>
#include <string>

namespace std
{
	template <>
	LIBRARY_EXPORT_API struct hash<GUID>
	{
		constexpr size_t operator()(const GUID &guid) const noexcept
		{
			const uint64_t *p = reinterpret_cast<const uint64_t *>(&guid);
			std::hash<uint64_t> hash;
			return hash(p[0]) ^ hash(p[1]);
		}
	};

	template <>
	LIBRARY_EXPORT_API struct equal_to<GUID>
	{
		constexpr bool operator()(const GUID &lhs, const GUID &rhs) const noexcept
		{
			return lhs.Data1 == rhs.Data1 &&
			       lhs.Data2 == rhs.Data2 &&
			       lhs.Data3 == rhs.Data3 &&
			       std::equal(std::begin(lhs.Data4), std::end(lhs.Data4), std::begin(rhs.Data4));
		}
	};
}

namespace RE2RR::Common::Guid
{
	LIBRARY_EXPORT_API constexpr std::string ToString(const GUID &guid) noexcept
	{
		std::string guid_string((sizeof(GUID) * 2) + 4, ' ');

		snprintf(
		    guid_string.data(), guid_string.capacity(),
		    "%08lX-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X",
		    guid.Data1,
		    guid.Data2,
		    guid.Data3,
		    guid.Data4[0], guid.Data4[1],
		    guid.Data4[2], guid.Data4[3], guid.Data4[4], guid.Data4[5], guid.Data4[6], guid.Data4[7]);

		return guid_string;
	}

	constexpr const size_t short_guid_form_length = 36; // XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX

	LIBRARY_EXPORT_API constexpr char ParseHexChar(const char &c)
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
	LIBRARY_EXPORT_API constexpr T ParseHexType(const char *ptr)
	{
		constexpr size_t digits = sizeof(T) * 2;
		T result{};
		for (size_t i = 0; i < digits; ++i)
			result |= ParseHexChar(ptr[i]) << (4 * (digits - i - 1));
		return result;
	}

	LIBRARY_EXPORT_API constexpr GUID ToGUID(const char *begin)
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
	LIBRARY_EXPORT_API constexpr GUID ToGUID(const char (&str)[N])
	{
		static_assert(N == (short_guid_form_length + 1), "String GUID of the form XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX is expected");
		return ToGUID(str);
	}

	inline namespace Guid_Literals
	{
		LIBRARY_EXPORT_API constexpr GUID operator"" _guid(const char *str, size_t N)
		{
			using namespace std::string_literals;
			if (N != short_guid_form_length)
				throw std::domain_error{"String GUID of the form XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX is expected"s};
			return ToGUID(str);
		}
	}
}

#endif
