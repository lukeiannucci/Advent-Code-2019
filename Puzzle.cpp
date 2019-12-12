// Puzzle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <math.h>
#include "Day1.cpp"
#include "Day2.cpp"
#include "Day3.cpp"
#include "Day4.cpp"
#include "Layer.h"
#include "LinkedList.h"
int day5()
{
	int index = 0;
	LinkedList<Layer> list;
	Layer fewestZeros;
	bool force = true;
	std::string input = "";
	std::ifstream in;
	in.open("5.txt");
	std::getline(in, input);
	while (index < input.size())
	{
		Layer tempLayer;
		for (int i = 0; i < LENGTH; i++)
		{
			for (int j = 0; j < WIDTH; j++)
			{
				int tempNum = input[index] - '0';
				tempLayer.imageData[i][j] = tempNum;
				tempLayer.updateCount(tempNum);
				index++;
			}
		}
		if (tempLayer.getZeros() < fewestZeros.getZeros() || force)
		{
			fewestZeros = tempLayer;
			force = false;
		}
		list.push_back(tempLayer);
	}
	list.printPicture();
	return list.getSize();
}

int main()
{
	//int iDay1 = day1();
	//int iDay2 = day2();
	//int iDay3 = day3();
	//int iDay4 = day4();
	int iDay5 = day5();
    std::cout << "Hello World!\n";
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
