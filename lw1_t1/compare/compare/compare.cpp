#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char * argv[])
{
	string firstLine;
	string secondLine;
	int lineCount;
	lineCount = 0;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	if (argc != 3)
	{
		cout << "Not enough arguments" << endl;
		return 1;
	}
	ifstream first(argv[1]);
	ifstream second(argv[2]);

	if (!first.is_open())
	{
		cout << "Fail to open first file! " << endl;
		return 1;
	}

	if (!second.is_open())
	{
		cout << "Fail to open second file! " << endl;
		return 1;
	}

	while (!first.eof() && !second.eof())
	{
		getline(first, firstLine);
		getline(second, secondLine);

		lineCount++;
		if (!(firstLine == secondLine))
		{
			cout << "Files are different. Line number is " << lineCount << endl;
			return 1;
		}


		if (first.eof() && second.eof())
		{
			cout << "Files are equal" << endl;
			return 0;
		}

		if (first.eof())
		{
			cout << "Files are different. Line number is " << lineCount + 1 << endl;
			return 1;
		}

		if (second.eof())
		{
			cout << "Files are different. Line number is " << lineCount + 1 << endl;
			return 1;
		}
	}

	return 0;
}