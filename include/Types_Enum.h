#if defined(ENUM_NAME) && defined(ENUM_TYPE) && defined(ENUM_LIST)

#include <stdint.h>
#include <string>

#ifndef RE2RR_TYPES_ENUM_H
#define RE2RR_TYPES_ENUM_H

namespace CREnums
{
	template <typename T>
	std::string EnumToString(T UNUSED(enumValue))
	{
		return {};
	}

	template <typename R, typename T>
	R EnumFromValue(T UNUSED(enumValue))
	{
		return {};
	}
}

#endif

enum class ENUM_NAME : ENUM_TYPE
{
#define ENUM_VALUE(name, value) name = value,
	ENUM_LIST
#undef ENUM_VALUE
};

template <>
std::string CREnums::EnumToString<ENUM_NAME>(ENUM_NAME enumValue)
{
	switch (enumValue)
	{
#define ENUM_VALUE(name, value) \
	case ENUM_NAME::name:       \
		return #name;
		ENUM_LIST
#undef ENUM_VALUE
		default:
			return {};
	}
}

template <>
ENUM_NAME CREnums::EnumFromValue<ENUM_NAME, ENUM_TYPE>(ENUM_TYPE enumValue)
{
	switch (enumValue)
	{
#define ENUM_VALUE(name, value) \
	case value:                 \
		return ENUM_NAME::name;
		ENUM_LIST
#undef ENUM_VALUE
		default:
			return {};
	}
}

#endif
