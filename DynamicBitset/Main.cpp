#include <iostream>
#include "DynamicBitset.h"

int main()
{
	DynamicBitset bitset;

    unsigned char count = 97;
    unsigned int ultraCount = 0;

    try 
    {
        while (ultraCount < 10000000)
        {
            if (count > 122)
            {
                count = 97;
            }

            bitset.addByte(count);

            count++;
            ultraCount++;
        }
    }
    catch (const std::bad_alloc&) 
    {
        std::cout << "UltraCount: " << ultraCount << std::endl;
        std::cerr << "Memory allocation failed!" << std::endl;
    }

    std::cout << "UltraCount: " << ultraCount << std::endl;

	return 0;
}