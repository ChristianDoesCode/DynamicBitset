#pragma once
#include <cstring>
#include <iostream>

class DynamicBitset
{
private:
	unsigned char* array;
	unsigned int arrayLength;
	unsigned int bitLength;

public:
	//Constructors
	DynamicBitset();
	DynamicBitset(unsigned int bitLength);
	//Deconstructor
	~DynamicBitset();

	//function to add a byte to the bitset
	void addByte(unsigned char byte);
	void zeroOutArray();
	void zeroUpTo(unsigned int bitIndex);
	void operator++(int);

	bool operator[](unsigned int index);

	void printArray();
};