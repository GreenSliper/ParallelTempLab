#include "Data.h"
#include <string>
#include <fstream>

class ResultExporter
{
public:
	void WriteFile(string& fileName, Data& data, int N)
	{
		ofstream ofs(fileName);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				ofs << data.u[i][j] << " ";
			ofs << endl;
		}
	}
	;
};