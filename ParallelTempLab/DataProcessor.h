#include "Data.h"
#pragma once

class DataProcessor
{
public:
	virtual void Process(Data& data, double EPS) = 0;
};