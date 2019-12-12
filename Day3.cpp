#ifndef DAY3_CPP
#define DAY3_CPP
#include <iostream>
#include <string>
#include <fstream>
const int MAX_ARRAY_SIZE = 30000;

struct Lines {
	bool hasLine1;
	bool hasLine2;
	int stepsLine1;
	int stepsLine2;
	Lines()
	{
		this->hasLine1 = false;
		this->hasLine2 = false;
		this->stepsLine1 = 0;
		this->stepsLine2 = 0;
	}
};
struct Coordinates {
	int row;
	int col;
	Coordinates()
	{
		this->row = -1;
		this->col = -1;
	}

	Coordinates(int row, int col)
	{
		this->row = row;
		this->col = col;
	}
};

enum Direction
{
	NOT_SET = -1,
	UP = 0,
	DOWN = 1,
	LEFT = 2,
	RIGHT = 3
};

static Coordinates drawLine(Lines** board, int val, Direction dir, Coordinates endPoint, bool line1, int* closest, int* step, int* lowestStep)
{
	const int origin = MAX_ARRAY_SIZE / 2;
	switch (dir)
	{
	case RIGHT:
	{
		int col = endPoint.col + 1;
		for (col; col < (endPoint.col + 1 + val); col++)
		{
			if (line1)
			{
				board[endPoint.row][col].hasLine1 = true;
				board[endPoint.row][col].stepsLine1 = *step;
			}
			else if (!line1)
			{
				board[endPoint.row][col].hasLine2 = true;
				board[endPoint.row][col].stepsLine2 = *step;
			}
			if (board[endPoint.row][col].hasLine1 && board[endPoint.row][col].hasLine2)
			{
				int distanceRow = std::abs(endPoint.row - origin);
				int distanceCol = std::abs(col - origin);
				int total = distanceRow + distanceCol;
				if (total < *closest)
				{
					*closest = total;
				}
				int totalSteps = board[endPoint.row][col].stepsLine1 + board[endPoint.row][col].stepsLine2;
				if (totalSteps < *lowestStep)
				{
					*lowestStep = totalSteps;
				}
				std::cout << "row: " << endPoint.row << "\ncol: " << col << std::endl << std::endl;
			}
			(*step)++;
		}
		return Coordinates(endPoint.row, col - 1);
	}
	case LEFT:
	{
		int col = endPoint.col - 1;
		for (col; col > (endPoint.col - 1 - val); col--)
		{
			if (line1)
			{
				board[endPoint.row][col].hasLine1 = true;
				board[endPoint.row][col].stepsLine1 = *step;
			}
			else if (!line1)
			{
				board[endPoint.row][col].hasLine2 = true;
				board[endPoint.row][col].stepsLine2 = *step;
			}
			if (board[endPoint.row][col].hasLine1 && board[endPoint.row][col].hasLine2)
			{
				int distanceRow = std::abs(endPoint.row - origin);
				int distanceCol = std::abs(col - origin);
				int total = distanceRow + distanceCol;
				if (total < *closest)
				{
					*closest = total;
				}
				int totalSteps = board[endPoint.row][col].stepsLine1 + board[endPoint.row][col].stepsLine2;
				if (totalSteps < *lowestStep)
				{
					*lowestStep = totalSteps;
				}
				std::cout << "row: " << endPoint.row << "\ncol: " << col << std::endl << std::endl;
			}
			(*step)++;
		}
		return Coordinates(endPoint.row, col + 1);
	}
	case UP:
	{
		int row = endPoint.row + 1;
		for (; row < (endPoint.row + 1 + val); row++)
		{
			if (line1)
			{
				board[row][endPoint.col].hasLine1 = true;
				board[row][endPoint.col].stepsLine1 = *step;
			}
			else if (!line1)
			{
				board[row][endPoint.col].hasLine2 = true;
				board[row][endPoint.col].stepsLine2 = *step;
			}
			if (board[row][endPoint.col].hasLine1 && board[row][endPoint.col].hasLine2)
			{
				int distanceRow = std::abs(row - origin);
				int distanceCol = std::abs(endPoint.col - origin);
				int total = distanceRow + distanceCol;
				if (total < *closest)
				{
					*closest = total;
				}
				int totalSteps = board[row][endPoint.col].stepsLine1 + board[row][endPoint.col].stepsLine2;
				if (totalSteps < *lowestStep)
				{
					*lowestStep = totalSteps;
				}
				std::cout << "row: " << row << "\ncol: " << endPoint.col << std::endl << std::endl;
			}
			(*step)++;
		}
		return Coordinates(row - 1, endPoint.col);
	}
	case DOWN:
	{
		int row = endPoint.row - 1;
		for (; row > (endPoint.row - 1 - val); row--)
		{
			if (line1)
			{
				board[row][endPoint.col].hasLine1 = true;
				board[row][endPoint.col].stepsLine1 = *step;
			}
			else if (!line1)
			{
				board[row][endPoint.col].hasLine2 = true;
				board[row][endPoint.col].stepsLine2 = *step;
			}
			if (board[row][endPoint.col].hasLine1 && board[row][endPoint.col].hasLine2)
			{
				int distanceRow = std::abs(row - origin);
				int distanceCol = std::abs(endPoint.col - origin);
				int total = distanceRow + distanceCol;
				if (total < *closest)
				{
					*closest = total;
				}
				int totalSteps = board[row][endPoint.col].stepsLine1 + board[row][endPoint.col].stepsLine2;
				if (totalSteps < *lowestStep)
				{
					*lowestStep = totalSteps;
				}
				std::cout << "row: " << row << "\ncol: " << endPoint.col << std::endl << std::endl;
			}
			(*step)++;
		}
		return Coordinates(row + 1, endPoint.col);
	}
	default:
		throw;
	}
}

static void process(Lines** board, Coordinates origin)
{
	std::ifstream in;
	std::string line;
	in.open("3.csv");
	bool line1 = true;
	Coordinates endPoint = origin;
	int closest = MAX_ARRAY_SIZE;
	int step = 1;
	int lowest = INT32_MAX;
	//ew
	while (!in.eof())
	{
		std::getline(in, line);
		std::string temp;
		Direction dir = NOT_SET;

		//gross
		for (int i = 0; i < line.size(); i++)
		{

			if (line[i] == ',')
			{
				if (dir == NOT_SET)
				{
					throw;
				}
				int val = std::stoi(temp);
				endPoint = drawLine(board, val, dir, endPoint, line1, &closest, &step, &lowest);
				temp.clear();
				dir = NOT_SET;
			}
			else if (std::isalpha(line[i]))
			{

				switch (line[i])
				{
				case 'U':
				{
					dir = UP;
					break;
				}
				case 'D':
				{
					dir = DOWN;
					break;
				}
				case 'L':
				{
					dir = LEFT;
					break;
				}
				case 'R':
				{
					dir = RIGHT;
					break;
				}
				default:
				{
					throw;
				}
				}
			}
			else
			{
				temp += line[i];
			}
		}
		if (dir == NOT_SET)
		{
			throw;
		}
		int val = std::stoi(temp);
		endPoint = drawLine(board, val, dir, endPoint, line1, &closest, &step, &lowest);
		temp.clear();
		dir = NOT_SET;
		line1 = false;
		endPoint = origin;
		step = 1;
	}
	std::cout << "Lowest: " << lowest << std::endl;
	std::cout << "Closest: " << closest << std::endl;
}

static int day3()
{

	const Coordinates origin = Coordinates(MAX_ARRAY_SIZE / 2, MAX_ARRAY_SIZE / 2);
	Lines** myArray = new Lines * [MAX_ARRAY_SIZE];
	for (int i = 0; i < MAX_ARRAY_SIZE; i++)
	{
		*(myArray + i) = new Lines[MAX_ARRAY_SIZE];
		for (int j = 0; j < MAX_ARRAY_SIZE; j++)
		{
			myArray[i][j] = Lines();
		}
	}
	process(myArray, origin);

	for (int i = 0; i < MAX_ARRAY_SIZE; i++)
	{
		delete[] * (myArray + i);
	}
	delete[] myArray;
	return 0;
}
#endif // !DAY3_CPP
