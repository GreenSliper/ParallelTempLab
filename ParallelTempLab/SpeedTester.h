#include "DataProcessor.h"
#include <chrono>

class SpeedData
{
public:
	std::chrono::nanoseconds epochDuration, epochMin, epochMax, epochAverage;
};

class SpeedTester
{
public:
	virtual SpeedData* GetMetrics(DataProcessor* processor, size_t N, double EPS, int testCount) = 0;
};