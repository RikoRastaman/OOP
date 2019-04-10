#include "pch.h"
#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;

string uppercaseToLower(string str)
{
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}

void checkInDictionary(map<string, int> &dictionary, string str)
{
	if ((dictionary.find(str)) == dictionary.end())
	{
		dictionary.insert(pair<string, int>(str, 1));
	}
	else
	{
		dictionary.at(str) += 1;
	}
}

void printFrequency(map<string, int> &dictionary)
{
	for (map<string, int>::iterator it = dictionary.begin();
		it != dictionary.end(); ++it)
	{
		cout << it->first << " => " << it->second << endl;
	}
}

int main()
{
	map <string, int> dictionary = {};

	string str;
	while (cin >> str)
	{
		str = uppercaseToLower(str);
		checkInDictionary(dictionary, str);
	}
	printFrequency(dictionary);
}