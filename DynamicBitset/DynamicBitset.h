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
		DynamicBitset(DynamicBitset& originalBitset);
		//Deconstructor
		~DynamicBitset();
	
		unsigned int getArrayLength();
	
		//function to add a byte to the bitset
		void addByte(unsigned char byte);
		void zeroOutArray();
		void zeroUpTo(unsigned int bitIndex);
		void operator++(int);
		//DynamicBitset operator++(int);
	
		bool operator[](unsigned int index);
	
		void printArray();
	};
}
