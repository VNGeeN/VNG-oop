#include "stdafx.h"
#include "GeneratePrimeNumberSet.h"
#include <iterator>

using namespace std;

static const int MIN_NUMBER = 2;

set<int> FindPrimeNumbers(vector<bool> const& primeNumber, int theLimitOfplurality)
{
	set<int> primeNumbers;
	for (int i = MIN_NUMBER; i <= theLimitOfplurality; ++i)
	{
		if (primeNumber[i])
		{
			primeNumbers.insert(i);
		}
	}
	return primeNumbers;
}

set<int> GeneratePrimeNumbersSet(int theLimitOfplurality)
{
	vector<bool> primeNumber(theLimitOfplurality + 1, true);
	primeNumber[0] = false;
	if (theLimitOfplurality != 0)
	{
		primeNumber[1] = false;
	}
	
	for (int i = MIN_NUMBER; i*i <= theLimitOfplurality; ++i)
	{
		if (primeNumber[i])
		{
			for (int k = i*i; k <= theLimitOfplurality; k += i)
			{
				primeNumber[k] = false;
			}
		}
	}
	return FindPrimeNumbers(primeNumber, theLimitOfplurality);
}

void WritePrimeNumbersInOutput(set<int> const& primeNumbers)
{
	copy(primeNumbers.begin(), primeNumbers.end(), ostream_iterator<int>(cout, " "));
}