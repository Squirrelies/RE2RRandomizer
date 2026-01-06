#include "Common.h"

namespace RE2RR::Common
{
	std::string lastExceptionMessage = "";
	std::string GetLastExceptionMessage()
	{
		return lastExceptionMessage;
	}
}
