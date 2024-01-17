#ifndef RE2RR_RANDOMIZER_H
#define RE2RR_RANDOMIZER_H

#include "Logging.h"
#include <vector>

class Randomizer
{
private:
	ImmediateLogger *logger;
	std::vector<int> seed;

protected:
public:
	Randomizer(ImmediateLogger *logger)
	{
		this->logger = logger;
	}
	~Randomizer()
	{
		if (logger != nullptr)
		{
			delete logger;
			logger = nullptr;
		}
	}
};

#endif
