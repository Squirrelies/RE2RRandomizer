#if defined(ENUM_NAME) && defined(ENUM_TYPE) && defined(ENUM_LIST)

#include <stdint.h>
#include <string>

#ifndef RE2RR_TYPES_ENUM_H
#define RE2RR_TYPES_ENUM_H

#define METHOD_NAME_STRINGIFIER(pre,name,post) pre ## name ## post

#endif

namespace RE2RREnums
{
enum class ENUM_NAME : ENUM_TYPE
{
#define ENUM_VALUE(name, value) name = value,
	ENUM_LIST
#undef ENUM_VALUE
};

#define ENUM_METHOD_NAME(name) std::string METHOD_NAME_STRINGIFIER(Enum,name,ToString)(METHOD_NAME_STRINGIFIER(,name,) enumValue)
ENUM_METHOD_NAME(ENUM_NAME);
#undef ENUM_METHOD_NAME

#define ENUM_METHOD_NAME(name,type) name METHOD_NAME_STRINGIFIER(Enum,name,FromValue)(METHOD_NAME_STRINGIFIER(,type,) enumValue)
ENUM_METHOD_NAME(ENUM_NAME,ENUM_TYPE);
#undef ENUM_METHOD_NAME
}

#endif
