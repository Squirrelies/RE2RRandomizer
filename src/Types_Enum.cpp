#if defined(ENUM_NAME) && defined(ENUM_TYPE) && defined(ENUM_LIST)

#include "Types_Enum.h"

namespace RE2RREnums
{
#define ENUM_METHOD_NAME(name) std::unique_ptr<std::string> DEFINE_CONCATENATION(DEFINE_CONCATENATION(Enum, name), ToString)(DEFINE_CONCATENATION(, name) enumValue)
	ENUM_METHOD_NAME(ENUM_NAME)
#undef ENUM_METHOD_NAME
	{
		switch (enumValue)
		{
#define ENUM_VALUE(name, value) \
	case ENUM_NAME::name:       \
		return std::make_unique<std::string>(#name);
			ENUM_LIST
#undef ENUM_VALUE
			default:
				return std::make_unique<std::string>();
		}
	}

#define ENUM_METHOD_NAME(name, type) name DEFINE_CONCATENATION(DEFINE_CONCATENATION(Enum, name), FromValue)(DEFINE_CONCATENATION(, type) enumValue)
	ENUM_METHOD_NAME(ENUM_NAME, ENUM_TYPE)
#undef ENUM_METHOD_NAME
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
}

#endif
