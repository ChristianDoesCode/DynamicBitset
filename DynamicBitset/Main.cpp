#include <iostream>
#include "DynamicBitset.h"

int main()
{
	cpStdLib::DynamicBitset bitset;

    unsigned char count = 255;

    bitset.addByte(count);
	//count = 255;
	bitset.addByte(count);

	bitset++;
	bitset++;
	bitset++;

	std::cout << bitset[0] << std::endl;

	bitset.setBit(0, 1);
	//bool bit = bitset[0];

	//std::cout << bit << std::endl;

	bitset.printArray();

	return 0;
}