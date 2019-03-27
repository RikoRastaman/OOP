#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <string>

using namespace std;
const string EMPTY = "Array is empty.";

void readFromInput(vector<float>& massivForRead)
{
	float number;
	while ( cin >> number)
	{
		massivForRead.push_back(number);
	}
}

void printMassiv(vector<float>& massivForPrint)
{

	std::cout << fixed << std::setprecision(3);
	std::copy(
	massivForPrint.begin(),
	massivForPrint.end(),
	std::ostream_iterator<float>(std::cout, " ")
	);

}

float findMinimum(vector<float>& massiv)
{
	if (massiv.size() != 0)
	{
		return *std::min_element(massiv.begin(), massiv.end());
	}
	else
	{
		cout << EMPTY << "\n";
		exit(1);
	}
}

void multiplicMassiv(vector<float>& massiv, float multiplicator)
{
	for (size_t i = 0; i < massiv.size(); ++i)
	{
		massiv[i] = massiv[i] * multiplicator;
	}
}

void sortMassiv(vector<float>& massiv)
{
	std::sort (massiv.begin(), massiv.end());
}

int main()
{
	vector<float> massiv;

	readFromInput(massiv);
	findMinimum(massiv);
	multiplicMassiv(massiv, findMinimum(massiv));
	sortMassiv(massiv);
	printMassiv(massiv);
}
