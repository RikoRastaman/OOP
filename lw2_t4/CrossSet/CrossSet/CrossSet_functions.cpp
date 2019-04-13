#include "pch.h"
#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <iterator>

int sumDigit(int n)
{
	int sum = 0;
	do
	{
		sum += (n % 10);
		n /= 10;
	} while (n > 0);
	return sum;
};

std::set<int> CrossSet(std::set<int> const& set1, std::set<int> const& set2)
{
	std::set<int>intersection = {};
	set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), std::inserter(intersection, intersection.begin()));
	return intersection;
}

std::set<int> addSumWithNoRemainder(std::set<int>&noRemainder, int maxNumber)
{
	for (int n = 1; n <= maxNumber; n++)
	{
		if (n % sumDigit(n) == 0)
		{
			noRemainder.insert(n);
		}
	}
	return noRemainder;
}

std::set<int> addEvenSum(std::set<int>&evenSum, int maxNumber)
{
	for (int n = 1; n <= maxNumber; n++)
	{
		if (sumDigit(n) % 2 == 0)
		{
			evenSum.insert(n);
		}
	}
	return evenSum;
}

void printSet(std::set<int>&setToprint)
{
	std::set<int>::iterator it;
	for (it = setToprint.begin(); it != setToprint.end(); it++)
	{

		std::cout << *it << ' ';
	}
}