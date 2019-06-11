#include "stdafx.h"
#include "Rational.h"
#include <iostream>
int main()
{
	CRational rational(5, 3333);
	std::cout << rational.GetNumerator() << "/" << rational.GetDenominator();
    return 0;
}

