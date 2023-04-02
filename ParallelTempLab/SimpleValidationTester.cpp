#include "ValidationTester.h"
#include <iostream>

class SimpleValidationTester : public ValidationTester
{
public:
	void Test(DataProcessor* processor, DataLoader* trustedResultLoader, const string& resultFileName, size_t N, double EPS, int testCount) override
	{
		auto trusted = trustedResultLoader->GetRealData(resultFileName, N);
		for (int test = 0; test < testCount; test++)
		{
			cout << "Test #" << (test + 1);
			Data result(N);
			processor->Process(result, EPS);
			try 
			{
				for (int i = 0; i < N; i++)
					for (int j = 0; j < N; j++)
						if (fabs(trusted[i][j] - result.u[i][j]) > EPS)
							throw std::exception();
				cout << " | PASSED" << endl;
			}
			catch (std::exception e)
			{
				cout << " | FAILED" << endl;
			}
		}
	}
	;
};