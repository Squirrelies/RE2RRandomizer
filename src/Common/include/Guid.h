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
	constexpr const char8_t hex_chars[] = u8"0123456789ABCDEF";
	LIBRARY_EXPORT_API constexpr char8_t ToHighNibble(const uint8_t &chr) noexcept
	{
		return hex_chars[chr >> 4];
	}

	LIBRARY_EXPORT_API constexpr char8_t ToLowNibble(const uint8_t &chr) noexcept
	{
		return hex_chars[chr & 0x0F];
	}

	LIBRARY_EXPORT_API constexpr std::u8string ToString(const GUID &ptr)
	{
		constexpr size_t digits = sizeof(GUID);
		const uint8_t *guidBytes = reinterpret_cast<const uint8_t *>(&ptr);
		std::u8string result(digits * 2 + 4, u8'-');

		{
			size_t i = 0;

			result[i++] = ToHighNibble(guidBytes[3]);
			result[i++] = ToLowNibble(guidBytes[3]);
			result[i++] = ToHighNibble(guidBytes[2]);
			result[i++] = ToLowNibble(guidBytes[2]);
			result[i++] = ToHighNibble(guidBytes[1]);
			result[i++] = ToLowNibble(guidBytes[1]);
			result[i++] = ToHighNibble(guidBytes[0]);
			result[i++] = ToLowNibble(guidBytes[0]);
			++i;

			result[i++] = ToHighNibble(guidBytes[5]);
			result[i++] = ToLowNibble(guidBytes[5]);
			result[i++] = ToHighNibble(guidBytes[4]);
			result[i++] = ToLowNibble(guidBytes[4]);
			++i;

			result[i++] = ToHighNibble(guidBytes[7]);
			result[i++] = ToLowNibble(guidBytes[7]);
			result[i++] = ToHighNibble(guidBytes[6]);
			result[i++] = ToLowNibble(guidBytes[6]);
			++i;

			result[i++] = ToHighNibble(guidBytes[8]);
			result[i++] = ToLowNibble(guidBytes[8]);
			result[i++] = ToHighNibble(guidBytes[9]);
			result[i++] = ToLowNibble(guidBytes[9]);
			++i;

			result[i++] = ToHighNibble(guidBytes[10]);
			result[i++] = ToLowNibble(guidBytes[10]);
			result[i++] = ToHighNibble(guidBytes[11]);
			result[i++] = ToLowNibble(guidBytes[11]);
			result[i++] = ToHighNibble(guidBytes[12]);
			result[i++] = ToLowNibble(guidBytes[12]);
			result[i++] = ToHighNibble(guidBytes[13]);
			result[i++] = ToLowNibble(guidBytes[13]);
			result[i++] = ToHighNibble(guidBytes[14]);
			result[i++] = ToLowNibble(guidBytes[14]);
			result[i++] = ToHighNibble(guidBytes[15]);
			result[i++] = ToLowNibble(guidBytes[15]);
		}

		return result;
	}

	constexpr const size_t short_guid_form_length = 36; // XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX

	LIBRARY_EXPORT_API constexpr char8_t ParseHexChar(const char8_t &c)
	{
		using namespace std::string_literals;
		if (u8'0' <= c && c <= u8'9')
			return c - u8'0';
		else if (u8'a' <= c && c <= u8'f')
			return 10 + c - u8'a';
		else if (u8'A' <= c && c <= u8'F')
			return 10 + c - u8'A';
		else
			throw std::domain_error{"Invalid character in GUID"s};
	}

	template <class T>
	LIBRARY_EXPORT_API constexpr T ParseHexType(const char8_t *ptr)
	{
		constexpr size_t digits = sizeof(T) * 2;
		T result{};
		for (size_t i = 0; i < digits; ++i)
			result |= ParseHexChar(ptr[i]) << (4 * (digits - i - 1));
		return result;
	}

	LIBRARY_EXPORT_API constexpr GUID ToGUID(const char8_t *begin)
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
	LIBRARY_EXPORT_API constexpr GUID ToGUID(const char8_t (&str)[N])
	{
		static_assert(N == (short_guid_form_length + 1), "String GUID of the form XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX is expected");
		return ToGUID(str);
	}

	inline namespace Guid_Literals
	{
		LIBRARY_EXPORT_API constexpr GUID operator"" _guid(const char8_t *str, size_t N)
		{
			using namespace std::string_literals;
			if (N != short_guid_form_length)
				throw std::domain_error{"String GUID of the form XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX is expected"s};
			return ToGUID(reinterpret_cast<const char8_t *>(str));
		}

		[[deprecated("Consider using the Utf8 literal instead")]]
		LIBRARY_EXPORT_API constexpr GUID operator"" _guid(const char *str, size_t N)
		{
			using namespace std::string_literals;
			if (N != short_guid_form_length)
				throw std::domain_error{"String GUID of the form XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX is expected"s};
			return ToGUID(reinterpret_cast<const char8_t *>(str));
		}
	}
}

#endif
