#include "DataProcessor.h"
#include "DataLoader.h"

#pragma once

class ValidationTester
{
public:
	virtual void Test(DataProcessor* processor, DataLoader* trustedResultLoader, const string& resultFileName, size_t N, double EPS, int testCount) = 0;
	;
};