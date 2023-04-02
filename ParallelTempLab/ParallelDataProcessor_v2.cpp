#include "DataProcessor.h"

using namespace std;

class ParallelDataProcessor_v2 : public DataProcessor
{
public:
	void Process(Data& data, double EPS) override
	{
		int N = data.u.size();
		double diff = 0.0;
		while (true) {
			diff = 0.0;
			#pragma omp parallel for shared(diff) schedule(static, 4) collapse(2)
			for (int i = 1; i < N - 1; ++i)
				for (int j = 1; j < N - 1; ++j)
				{
					data.v[i][j] = (data.u[i - 1][j] + data.u[i + 1][j] + data.u[i][j - 1] + data.u[i][j + 1]) / 4.0;
					if (fabs(data.v[i][j] - data.u[i][j]) > diff)
					{
						#pragma omp critical
						if (fabs(data.v[i][j] - data.u[i][j]) > diff)
							diff = fabs(data.v[i][j] - data.u[i][j]);
					}
				}

			if (diff <= EPS)
				break;

			#pragma omp parallel for schedule(static, 4) collapse(2)
			for (int i = 1; i < N - 1; ++i)
				for (int j = 1; j < N - 1; ++j)
					data.u[i][j] = data.v[i][j];
		}
	}
};