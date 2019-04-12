#include "pch.h"
#include "map_functions.h"
#include <iostream>
#include <map>

int main()
{
	std::map<std::string, int> dictionary = {};

	std::string str;
	while (std::cin >> str)
	{
		str = uppercaseToLower(str);
		checkInDictionary(dictionary, str);
	}
	printFrequency(dictionary);
}