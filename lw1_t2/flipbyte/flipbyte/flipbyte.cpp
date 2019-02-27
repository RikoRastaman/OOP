#include "pch.h"
#include <iostream>
//using namespace std;

int swapParts(int b)
{
	b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
	b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
	b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
	return b;
}

bool isNumeral(std::string str)
{
	char* p;
	strtol(str.c_str(), &p, 10);
	return *p == 0;

}

int main(int argc, char *argv[])
{
	int inputNumber = 0;

	if (argc != 2)
	{
		std::cout << "Wrong agrument, please enter number in range 0-255." << std::endl;
		return 1;
	}

	std::string str = argv[1];
	if (!isNumeral(str))
	{
		std::cout << "Entered line is not number, please enter number in range 0-255.";
		return 1;
	}

	inputNumber = atoi(str.c_str());
	
	if (inputNumber < 0 || inputNumber > 255)
	{
		std::cout << "Out of range." << std::endl;
		return 1;
	}
	std::cout << swapParts(inputNumber);
	return 0;
}