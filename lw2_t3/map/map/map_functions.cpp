#include"pch.h"
#include <iostream>
#include<string>
#include<map>
#include<iterator>
#include <algorithm>

std::string uppercaseToLower(std::string str)
{
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}

void checkInDictionary(std::map<std::string, int>&dictionary, std::string str)
{
	if ((dictionary.find(str)) == dictionary.end())
	{
		dictionary.insert(std::pair<std::string, int>(str, 1));
	}
	else
	{
		dictionary.at(str) += 1;
	}
}

void printFrequency(std::map<std::string, int> &dictionary)
{
	for (std::map<std::string, int>::iterator it = dictionary.begin();
		it != dictionary.end(); ++it)
	{
		std::cout << it->first << " => " << it->second << std::endl;
	}
}
