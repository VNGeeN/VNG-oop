#include "stdafx.h"
#include "GeneratePrimeNumberSet.h"

using namespace std;

static const int MAX_NUMBER = 100000000;

int main(int argc, char *argv[])
{
	unsigned int startTime = clock();
	int theLimitOfplurality = 100000000;
	if (MAX_NUMBER >= theLimitOfplurality)
	{
		set<int> theSetOfInteger = GeneratePrimeNumbersSet(theLimitOfplurality);
		//WritePrimeNumbersInOutput(theSetOfInteger);
	}
	unsigned int endTime = clock();
	unsigned int searchTime = endTime - startTime;
	cout << searchTime / 1000.f << endl;
	return 0;
}