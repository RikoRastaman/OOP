#include "stdafx.h"
#include "Rational.h"
#include <iostream>
int main()
{
	CRational rational(-1, -2);
	std::cout << rational.GetNumerator() << "/" << rational.GetDenominator();
    return 0;
}

