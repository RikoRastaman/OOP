#include "pch.h"
#include "car.h"


car::car()
{
	m_engine = false;
	m_gear = GearName::NEUTRAL;
}

bool car::SetGear(int gear)
{
	m_gear = GearName(gear);
	return true;
}


car::~car()
{

}