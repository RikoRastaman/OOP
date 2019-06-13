#include "pch.h"
#include <iostream>
#include "CTriangle.h"

int main()
{
	double side1;
	double side2;
	double side3;

	while (!std::cin.eof())
	{
		std::cout << "Enter triangle sides sizes (first) (second) (third): " << std::endl;
		std::cin >> side1 >> side2 >> side3;

		try
		{
			CTriangle Triangle(side1, side2, side3);

			std::cout << "perimiter: " << Triangle.GetPerimeter() << " area: " << Triangle.GetArea() << std::endl;
		}
		catch (const std::exception& err)
		{
			std::cout << err.what() << std::endl;
		}
		
	}
}