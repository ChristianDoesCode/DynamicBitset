#include <iostream>
#include "DynamicBitset.h"

int main()
{
	DynamicBitset bitset;

    unsigned char count = 97;

    bitset.addByte(count);
	bitset++;

	bitset.printArray();

	return 0;
}