#include "stdafx.h"
#include "Car.h"
#include "CarControl.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	CCar car;
	CCarControl virtualControl(car, cin, cout);

	while (!cin.eof() && !cin.fail())
	{
		cout << "> ";
		if (!virtualControl.HandleCommand())
		{
			cout << "Unknown command!\n";
		}
	}
	return 0;
}