#include <iostream>
#include "DynamicBitset.h"

int main()
{
	DynamicBitset bitset;

    unsigned char count = 255;

    bitset.addByte(count);
	count = 254;
	bitset.addByte(count);
	bitset++;
	//bool bit = bitset[0];

	//std::cout << bit << std::endl;

	bitset.printArray();

	return 0;
}