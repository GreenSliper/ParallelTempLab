#include "DataLoader.h"
#include <fstream>

using namespace std;

class FileDataLoader : public DataLoader
{
public:
	vector<vector<double>> GetRealData(const string& file_name, size_t N) override
	{
		vector<vector<double>> result(N, vector<double>(N));
		ifstream in(file_name);
		if (in) {
			for (size_t i = 0; i < N; ++i)
				for (size_t j = 0; j < N; ++j)
					in >> result[i][j];
		}
		else
			throw std::exception();
		return result;
	}
};