#ifndef LAYER_H
#define LAYER_H
const int WIDTH = 25;
const int LENGTH = 6;
class Layer
{
public:
	Layer();
	void updateCount(const int value);
	int getZeros();
	int imageData[LENGTH][WIDTH];
	
private:
	int zeros;
	int ones;
	int twos;
};
#endif
