#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip>

using namespace std;

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
}

void multiplicMassiv(vector<float>& massiv, float multiplicator)
{
	for (int i = 0; i < massiv.size(); ++i)
	{
		massiv[i] = massiv[i] * multiplicator;
	}
}

int main()
{
	vector<float> massiv;

	readFromInput(massiv);
	findMinimum(massiv);
	multiplicMassiv(massiv, findMinimum(massiv));
	printMassiv(massiv);
}
