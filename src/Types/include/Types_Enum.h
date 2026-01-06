#if defined(ENUM_NAME) && defined(ENUM_TYPE) && defined(ENUM_LIST)

#include "Common.h"

namespace Enums
{
	enum class ENUM_NAME : ENUM_TYPE
	{
#define ENUM_VALUE(name, value) name = value,
		ENUM_LIST
#undef ENUM_VALUE
	};

#define ENUM_METHOD_NAME(name) LIBRARY_EXPORT_API std::unique_ptr<std::string> DEFINE_CONCATENATION(DEFINE_CONCATENATION(Enum, name), ToString)(DEFINE_CONCATENATION(, name) enumValue)
	ENUM_METHOD_NAME(ENUM_NAME);
#undef ENUM_METHOD_NAME

#define ENUM_METHOD_NAME(name, type) LIBRARY_EXPORT_API name DEFINE_CONCATENATION(DEFINE_CONCATENATION(Enum, name), FromValue)(DEFINE_CONCATENATION(, type) enumValue)
	ENUM_METHOD_NAME(ENUM_NAME, ENUM_TYPE);
#undef ENUM_METHOD_NAME
}

#endif
