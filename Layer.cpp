#include "Layer.h"
Layer::Layer()
{
	this->zeros = 0;
	this->ones = 0;
	this->twos = 0;
}

void Layer::updateCount(const int value)
{
	switch (value)
	{
		case 0:
		{
			this->zeros++;
			break;
		}
		case 1:
		{
			this->ones++;
			break;
		}
		case 2:
		{
			this->twos++;
			break;
		}
		default:
		{
			throw "Invalid value: " + value;
		}
	}
}

int Layer::getZeros()
{
	return this->zeros;
}