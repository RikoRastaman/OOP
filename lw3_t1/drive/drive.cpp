
#include "pch.h"
#include <iostream>
#include "car.h"

int main()
{
	car car1;
	car1.TurnOnEngine();
	car1.SetGear(-1);
	car1.SetSpeed(19);
	
	//car1.TurnOffEngine();
	std::cout << car1.getSpeed() << std::endl;
	std::cout << car1.getDirection() << std::endl;
	car1.SetGear(0);
	std::cout << car1.getDirection() << std::endl;
	std::cout << car1.getGear() << std::endl;
	car1.SetGear(-1);
	std::cout << car1.getGear() << std::endl;
}
