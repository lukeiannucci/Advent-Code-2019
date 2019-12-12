#ifndef DAY4_CPP
#define DAY4_CPP
#include <string>
static bool isValidNum(const int number)
{
	std::string num = std::to_string(number);
	int prev = -1;
	int pairCounter = 0;
	bool pair = false;
	for (int i = 0; i < num.length(); i++)
	{
		int currentVal = num[i] - '0';
		if (currentVal == prev)
		{
			pairCounter++;
			pair = true;
		}
		else if (currentVal < prev)
		{
			return false;
		}
		else if (pairCounter != 0) //prev != -1 && currentVal != prev
		{
			if (pairCounter % 2 == 0)
			{
				return false;
			}
			else
			{
				pairCounter = 0;
			}
		}
		prev = currentVal;
	}
	/*if (number == 146888)
	{
		return pair && pairCounter % 2 == 1;
	}*/
	//if(pairCounter )
	if (pairCounter != 0)
		return pairCounter % 2 == 1;
	return pair;
}

static int day4()
{
	int passwords = 0;
	int start = 146810;
	int end = 612564;
	for (; start <= end; start++)
	{
		if (isValidNum(start))
		{
			passwords++;
		}
	}
	return passwords;
}
#endif // !DAY4_CPP
