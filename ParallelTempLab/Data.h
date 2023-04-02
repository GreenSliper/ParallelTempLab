#pragma once
#include <vector>

using namespace std;

struct Data {
	Data(size_t N) :
		u(N, vector<double>(N)),
		v(N, vector<double>(N))
	{
		double mean = 0.0;
		for (int i = 0; i < N; ++i) {
			u[i][0] = u[i][N - 1] = u[0][i] = 100.0;
			u[N - 1][i] = 0.0;
			mean += u[i][0] + u[i][N - 1] + u[0][i] + u[N - 1][i];
		}
		mean /= (4.0 * N);

		for (int i = 1; i < N - 1; ++i)
			for (int j = 1; j < N - 1; ++j)
				u[i][j] = mean;
	}

	vector<vector<double>> u;
	vector<vector<double>> v;
};