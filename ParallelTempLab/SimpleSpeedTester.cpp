#include "SpeedTester.h"

using namespace std::chrono;

class SimpleSpeedTester : public SpeedTester
{
public:
	SpeedData* GetMetrics(DataProcessor* processor, size_t N, double EPS, int testCount) override
	{
		SpeedData* result = new SpeedData();
		result->epochMin = nanoseconds(99999999);
		nanoseconds totalDur(0);

		for (int i = 0; i < testCount; i++)
		{
			Data dt(N);
			auto iterStart = high_resolution_clock::now();
			processor->Process(dt, EPS);
			auto iterEnd = high_resolution_clock::now();
			auto curDur = (iterEnd - iterStart);
			totalDur += curDur;
			if (curDur < result->epochMin)
				result->epochMin = curDur;
			else if (curDur > result->epochMax)
				result->epochMax = curDur;
		}
		result->epochAverage = duration_cast<nanoseconds>(totalDur / testCount);
		result->epochDuration = totalDur;
		return result;
	}
	;
};