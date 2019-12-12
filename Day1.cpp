#ifndef DAY1_CPP
#define DAY1_CPP
#include <fstream>
static int day1()
{
	const int divisor = 3;
	const int subtractor = 2;
	int tempFuel = 0;
	int totalFuel = 0;
	int rows = 1;
	std::ifstream in;
	in.open("1.txt");
	while (!in.eof())
	{
		int mass = 0;
		in >> mass;
		tempFuel += (mass / divisor) - subtractor;
		totalFuel += tempFuel;
		while (1)
		{
			tempFuel = (tempFuel / divisor) - subtractor;
			if (tempFuel <= 0)
			{
				break;
			}
			totalFuel += tempFuel;
		}
		tempFuel = 0;
		rows++;
	}
	return totalFuel;
}

#endif // !DAY1_CPP