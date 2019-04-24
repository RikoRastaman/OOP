
#include "pch.h"
#include <iostream>
#include "car.h"

int main()
{
	car car1;
	car1.TurnOnEngine();
	car1.SetGear(-1);
	
	//car1.TurnOffEngine();
	std::cout << car1.getGear() << std::endl;
}
