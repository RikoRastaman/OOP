#include "pch.h"
#include "car.h"
#include "CInterface.h"
#include <iostream>

int main()
{
	car car1;
	CInterface CInterface1(std::cin, std::cout, car1);
	CInterface1.ShowInfo(car1);
	std::string str;
	while (!std::cin.eof())
	{
		CInterface1.InicialCommand();
	}

	return 0;
}