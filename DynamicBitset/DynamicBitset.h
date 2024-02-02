#pragma once
#include <cstring>
#include <iostream>

namespace cpStdLib
{
	class DynamicBitset
	{
	private:
		unsigned char* array;
		unsigned int arrayLength;
		unsigned int bitLength;
		bool hasBeenCopied;
	
	public:
		//Constructors
		DynamicBitset();
		DynamicBitset(unsigned int bitLength);
		//Copy Constructor
		DynamicBitset(const DynamicBitset& originalBitset);
		//Deconstructor
		~DynamicBitset();
	
		unsigned int getArrayLength();
	
		void setBit(unsigned int bitIndex, unsigned char bitValue);
		//function to add a byte to the bitset
		void addByte(unsigned char byte);
		//sets all the chars in the array to 0
		void zeroOutArray();
		//sets all the chars up to the char containg the bitIndex to 0 and then uses a mask to set all bits before the bitIndex to 0
		void zeroUpTo(unsigned int bitIndex);
		//operator++ overload to increment the value
		DynamicBitset& operator++();
		DynamicBitset operator++(int);
	
		bool operator[](unsigned int index);
	
		void printArray();
	};
}
