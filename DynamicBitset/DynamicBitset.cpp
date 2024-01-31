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
	unsigned int lastCharBitIndex = bitIndex - (subArrayLength * 8);
	unsigned char powerMask = 1;
  	unsigned char bitMask = (powerMask << lastCharBitIndex) - 1;

  	bitMask = ~bitMask;

  	this->array[subArrayLength] &= bitMask;
	
	for(int i = 0; i < subArrayLength; i++)
	{
		this->array[i] = 0;
	}
	
}

DynamicBitset DynamicBitset::operator++(int)
{
	unsigned int byteCount = 0;
	unsigned int bitIndex = 0;
	
	while((this->array[byteCount] >> bitIndex & 1) != 0)
  	{
		if ((unsigned int)(bitIndex / 8) > this->arrayLength)
		{
			this->zeroOutArray();
			this->addByte(1);
			return *this;
		}
		if (bitIndex % 8 == 0)
		{
			byteCount = bitIndex / 8;
		}
		bitIndex++;
	}

	unsigned int subArrayLength = (unsigned int)(bitIndex / 8);
	unsigned int lastCharBitIndex = bitIndex - (subArrayLength * 8);
	unsigned char powerMask = 1;

	this->zeroUpTo(bitIndex);

	std::cout << (powerMask << lastCharBitIndex) << std::endl;
	std::cout << (int) this->array[subArrayLength] << std::endl;

	this->array[subArrayLength] += (powerMask << lastCharBitIndex);

	return *this;
}

DynamicBitset& DynamicBitset::operator++()
{
	return *this;
}

void DynamicBitset::printArray()
{
	std::cout << this->array[1] << std::endl;

	for (int i = 0; i < this->arrayLength; i++)
	{
		std::cout << (int) this->array[i] << ", ";
	}
}
