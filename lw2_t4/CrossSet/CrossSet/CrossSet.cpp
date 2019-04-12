#include "pch.h"
#include "CrossSet_functions.h"
#include <iostream>
#include <set>
#include <string>

const std::string INITIAL_MESSAGE = "Please enter N, max number of sets.";
const std::string FIST_SET_MESSAGE = "First set of sums mod = 0:";
const std::string SECOND_SET_MESSAGE = "Second set of even sums: ";
const std::string CROSS_SET_MESSAGE = "Cross of sets: ";

int main()
{
	std::set<int>noRemainder = {};
	std::set<int>evenSum = {};
	std::set<int>intersection = {};
	int maxNumber = 0;
	std::cout << INITIAL_MESSAGE << std::endl;
	while (std::cin >> maxNumber)
	{
		if (std::cin.fail())
		{
			return 0;
		}
		noRemainder = addSumWithNoRemainder(noRemainder, maxNumber);
		std::cout << FIST_SET_MESSAGE << std::endl;
		printSet(noRemainder);
		std::cout << std::endl;
		evenSum = addEvenSum(evenSum, maxNumber);
		std::cout << SECOND_SET_MESSAGE << std::endl;
		printSet(evenSum);
		std::cout << std::endl;
		intersection = CrossSet(noRemainder, evenSum);
		std::cout << CROSS_SET_MESSAGE;
		std::cout << std::endl;
		printSet(intersection);
		std::cout << std::endl;
	}
}
