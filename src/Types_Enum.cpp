#if defined(ENUM_NAME) && defined(ENUM_TYPE) && defined(ENUM_LIST)

#include "Types_Enum.h"

namespace RE2RREnums
{
#define ENUM_METHOD_NAME(name) std::string METHOD_NAME_STRINGIFIER(Enum,name,ToString)(METHOD_NAME_STRINGIFIER(,name,) enumValue)
ENUM_METHOD_NAME(ENUM_NAME)
#undef ENUM_METHOD_NAME
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

#define ENUM_METHOD_NAME(name,type) name METHOD_NAME_STRINGIFIER(Enum,name,FromValue)(METHOD_NAME_STRINGIFIER(,type,) enumValue)
ENUM_METHOD_NAME(ENUM_NAME,ENUM_TYPE)
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
