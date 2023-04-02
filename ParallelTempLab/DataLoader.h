#pragma once
#include <vector>
#include <string>

using namespace std;

class DataLoader
{
public:
	virtual vector<vector<double>> GetRealData(const string& file_name, size_t N) = 0;
};