#include "DynamicBitset.h"

DynamicBitset::DynamicBitset()
{
		this->array = nullptr;
		this->arrayLength = 0;
		this->bitLength = 0;
}

DynamicBitset::DynamicBitset(unsigned int bitLength)
{
	if (bitLength % 8 == 0)
	{
		this->arrayLength == bitLength / 8;
		this->array = new unsigned char[this->arrayLength];
		this->bitLength = bitLength;
	}
	else if (bitLength % 8 > 0)
	{
		this->arrayLength = (int)(bitLength / 8) + 1;
		this->array = new unsigned char[this->arrayLength];
		this->bitLength = bitLength;
	}
	else
	{
		this->arrayLength = 0;
		this->array = nullptr;
		this->bitLength = 0;
	}
}

DynamicBitset::~DynamicBitset()
{
	delete[] this->array;
}

void DynamicBitset::addByte(unsigned char byte)
{
	unsigned char* tempArray = new unsigned char[this->arrayLength + 1];
	memcpy(tempArray, this->array, this->arrayLength);
	delete[] this->array;
	tempArray[this->arrayLength] = byte;
	this->array = tempArray;
	this->arrayLength++;
	this->bitLength += 8;
}

void DynamicBitset::zeroOutArray()
{
	for(int i = 0; i < this->arrayLength; i++)
	{
		this->array[i] = 0;
	}
}

void DynamicBitset::zeroUpTo(unsigned int bitIndex)
{
	unsigned int subArrayLength = (unsigned int)(bitIndex / 8);
	unsigned int bitMask =  
	
	for(int i = 0; i < subArrayLength; i++)
	{
		this->array[i] = 0;
	}

	
}

DynamicBitset& DynamicBitset::operator++()
{
	int byteCount = 0;
	for(int i = 0; (this->array[byteCount] << i & 1) != 0; i++)
	{
		if ((int)(i / 8) > this->arrayLength)
		{
			this->zeroOutArray();
			this->addByte(1);
			return *this;
		}
		if (i % 8 == 0)
		{
			byteCount = i / 8;
		}
	}

	this->array[this->arrayLength - 1] += 1;
	return *this;
}

DynamicBitset DynamicBitset::operator++(int)
{
	return *this;
}

void DynamicBitset::printArray()
{
	for (int i = 0; i < this->arrayLength; i++)
	{
		std::cout << this->array[i] << ", ";
	}
}
