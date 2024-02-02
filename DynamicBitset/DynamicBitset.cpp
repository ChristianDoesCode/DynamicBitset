#include "DynamicBitset.h"

cpStdLib::DynamicBitset::DynamicBitset()
{
		this->array = nullptr;
		this->arrayLength = 0;
		this->bitLength = 0;
}

cpStdLib::DynamicBitset::DynamicBitset(unsigned int bitLength)
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
		this->hasBeenCopied = false;
	}
}

cpStdLib::DynamicBitset::DynamicBitset(const DynamicBitset& originalBitset)
{
	delete[] this->array;

	this->arrayLength = originalBitset.arrayLength;
	this->bitLength = originalBitset.bitLength;
	
	if(originalBitset.array == nullptr)
	{
		this->array = nullptr;
	}
	else
	{
		this->array = new unsigned char[this->arrayLength];

		for (int i = 0; i < this->arrayLength; i++)
		{
			this->array[i] = originalBitset.array[i];
		}
	}
}

cpStdLib::DynamicBitset::~DynamicBitset()
{
	delete[] this->array;
}

unsigned int cpStdLib::DynamicBitset::getArrayLength()
{
	return this->arrayLength;
}

void cpStdLib::DynamicBitset::setBit(unsigned int bitIndex, unsigned char bitValue)
{
	if (bitValue > 1)
	{
		return;
	}

	unsigned int subArrayLength = (unsigned int)(bitIndex / 8);
	unsigned char bitMask = 255 - bitValue * (1 << (bitIndex - subArrayLength * 8));
	std::cout << "bitMask: " << (unsigned int) bitMask << std::endl;

	this->array[subArrayLength] = this->array[subArrayLength] & bitMask;
}

void cpStdLib::DynamicBitset::addByte(unsigned char byte)
{
	unsigned char* tempArray = new unsigned char[this->arrayLength + 1];
	memcpy(tempArray, this->array, this->arrayLength);
	tempArray[this->arrayLength] = byte;
	delete[] this->array;
	this->array = tempArray;
	this->arrayLength++;
	this->bitLength += 8;
}

void cpStdLib::DynamicBitset::zeroOutArray()
{
	for(int i = 0; i < this->arrayLength; i++)
	{
		this->array[i] = 0;
	}
}

void cpStdLib::DynamicBitset::zeroUpTo(unsigned int bitIndex)
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

cpStdLib::DynamicBitset& cpStdLib::DynamicBitset::operator++()
{
	unsigned int byteCount = 0;
	unsigned int shiftAmount = 0;
	unsigned int bitIndex = 0;

	while (((this->array[byteCount] >> shiftAmount) & 1) != 0)
	{
		shiftAmount++;
		bitIndex++;
		if (shiftAmount % 8 == 0)
		{
			byteCount = bitIndex / 8;
			shiftAmount = 0;
		}

		if ((byteCount >= this->arrayLength) && bitIndex == this->arrayLength * 8)
		{
			this->zeroOutArray();
			std::cout << "This Ran!" << std::endl;
			this->addByte(1);
			return *this;
		}
	}

	unsigned int subArrayLength = (unsigned int)(bitIndex / 8);
	unsigned int lastCharBitIndex = bitIndex - (subArrayLength * 8);
	unsigned char powerMask = 1;

	this->zeroUpTo(bitIndex);

	this->array[subArrayLength] += (powerMask << lastCharBitIndex);
	return *this;
}


cpStdLib::DynamicBitset cpStdLib::DynamicBitset::operator++(int)
{
	cpStdLib::DynamicBitset tmp(*this);
	++(*this);
	return tmp;
}



bool cpStdLib::DynamicBitset::operator[](unsigned int bitIndex)
{
	unsigned int arrayIndex = (unsigned int)(bitIndex / 8);
	unsigned int shiftAmount = bitIndex - (arrayIndex) * 8;
	if (arrayIndex >= this->arrayLength)
	{
		std::cout << "Index out of bounds at line 114 in DynamicBitset.cpp" << std::endl;
		exit(0);
	}
	return (bool)((this->array[arrayIndex] >> shiftAmount) & 1);
}

void cpStdLib::DynamicBitset::printArray()
{
	for (int i = 0; i < this->arrayLength; i++)
	{
		std::cout << (int) this->array[i] << ", ";
	}
}
