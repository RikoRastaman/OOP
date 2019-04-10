#include "pch.h"
#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

const string INITIAL_MESSAGE = "Please enter N, max number of sets.";

std::set<int> CrossSet(std::set<int> const& set1, std::set<int> const& set2)
{
	set<int>intersection = {};
	set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), std::inserter(intersection, intersection.begin()));
	return intersection;
}

int SumDigit(int n)
{
	int sum = 0;
	do
	{
		sum += (n % 10);
		n /= 10;
	}
	while (n > 0);
	return sum;
};

int main()
{
	set<int>noResidue = {};
	set<int>evenSum = {};
	set<int>intersection = {};

	int maxNumber = 0;

	cout << INITIAL_MESSAGE << endl;
	cin >> maxNumber;


	for(int n = 1; n <= maxNumber; n++)
	{
		if(n % SumDigit(n) == 0)
		{
			noResidue.insert(n);
		}
	}

	for (int n = 1; n <= maxNumber; n++)
	{
		if (SumDigit(n) % 2 == 0)
		{
			evenSum.insert(n);
		}
	}

	intersection = CrossSet(noResidue, evenSum);

	set<int>::iterator it;

	/*for (it = noResidue.begin(); it != noResidue.end(); it++)
	{
		cout << *it << endl;
	}*/

	for (it = intersection.begin(); it != intersection.end(); it++)
	{
	cout << *it << ' ';
	}
		
}
