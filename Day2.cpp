#ifndef DAY2_CPP
#define DAY2_CPP
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
static void reset(std::vector<int>* resetVec)
{
	(*resetVec).clear();
	std::ifstream in;
	std::string line;
	in.open("2.csv");
	//ew
	while (!in.eof())
	{
		std::getline(in, line);
		std::string temp;
		//gross
		for (int i = 0; i < line.length(); i++)
		{
			if (line[i] == ',')
			{
				(*resetVec).push_back(std::stoi(temp));
				temp.clear();
			}
			else
			{
				temp += line[i];
			}
		}
		(*resetVec).push_back(std::stoi(temp));
	}
}

static int day2()
{

	std::vector<int> doWerk;
	reset(&doWerk);
	//start
	int opcodeIndex = 0;
	for (int i = 0; i <= 99; i++)
	{
		for (int j = 0; j <= 99; j++)
		{
			doWerk[1] = i;
			doWerk[2] = j;
			while (doWerk[opcodeIndex] != 99)
			{
				try
				{
					int sign = doWerk.at(opcodeIndex);
					int index1 = doWerk.at(opcodeIndex + 1);
					int index2 = doWerk.at(opcodeIndex + 2);
					int overwrite = doWerk.at(opcodeIndex + 3);
					int value1 = doWerk.at(index1);
					int value2 = doWerk.at(index2);
					doWerk.at(overwrite) = sign == 1 ? value1 + value2 : value1 * value2;
				}
				catch (const std::out_of_range)
				{
					break;
				}
				opcodeIndex = opcodeIndex + 4;
			}
			opcodeIndex = 0;
			if (doWerk[0] == 19690720)
			{
				std::cout << "i: " << i << std::endl;
				std::cout << "j: " << j << std::endl;
				break;
			}
			else
			{
				reset(&doWerk);
			}
		}
	}

	return doWerk[0];
}
#endif // !DAY1_CPP
