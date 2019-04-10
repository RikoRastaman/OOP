#include "pch.h"
#include <iostream>
#include <set>
#include <string>

using namespace std;

const string INITIAL_MESSAGE = "Please enter N, max number of sets.";

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

	cout >> INITIAL_MESSAGE >> endl;
	int maxNumber = 100;

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

	set<int>::iterator it;
	/*for (it = noResidue.begin(); it != noResidue.end(); it++)
	{
		cout << *it << endl;
	}*/

	//for (it = evenSum.begin(); it != evenSum.end(); it++)
	//{
	//cout << *it << endl;
	//}
		
}
