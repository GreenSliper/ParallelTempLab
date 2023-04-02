#include <iostream>
#include "ResultExporter.cpp"
#include "SimpleSpeedTester.cpp"
#include "SimpleValidationTester.cpp"
#include "SimpleDataProcessor.cpp"
#include "ParallelDataProcessor.cpp"
#include "ParallelDataProcessor_v2.cpp"
#include "FileDataLoader.cpp"

using namespace std;


void GenerateTestFile(DataProcessor* dp, ResultExporter* exp, int N, string& file, double EPS)
{
	Data dt(N);
	dp->Process(dt, EPS);
	exp->WriteFile(file, dt, N);
}

int main()
{
	double EPS = 0.01; int N = 100;
	string testFile = "test.txt";
	/*DataProcessor* dp = new SimpleDataProcessor();
	ResultExporter* exp = new ResultExporter();
	GenerateTestFile(dp, exp, 100, testFile, EPS);*/
	DataProcessor* dp = new SimpleDataProcessor();
	ValidationTester* vd = new SimpleValidationTester();
	DataLoader* dl = new FileDataLoader();
	vd->Test(dp, dl, testFile, N, EPS, 10);
	for (; N <= 150; N += 10)
	{
		cout << "N: " << N << "; EPS: " << EPS << endl;
		SpeedTester* st = new SimpleSpeedTester();
		auto result = st->GetMetrics(dp, N, EPS, 10);
		cout << "Total:\t\t" << duration_cast<milliseconds>(result->epochDuration) << endl;
		cout << "Average:\t" << duration_cast<milliseconds>(result->epochAverage) << endl;
		cout << "Min:\t\t" << duration_cast<milliseconds>(result->epochMin) << endl;
		cout << "Max:\t\t" << duration_cast<milliseconds>(result->epochMax) << endl << endl;
	}
}
