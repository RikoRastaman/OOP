#include "pch.h"
#include "car.h"


car::car()
{
	m_engine = false;
	m_direction = Direction::STAND_STILL;
	m_gear = Gear::NEUTRAL;
	m_speed = 0;
}



int car::getSpeed() const
{

	return m_speed;
}

bool car::getEngineCondition() const
{
	return m_engine;
}

std::string car::getDirection() const
{
	if (m_direction == Direction::BACKWARD)
	{
		return "BACKWARD";
	}
	else if (m_direction == Direction::FORWARD)
	{
		return "FORWARD";
	}
	else if (m_direction == Direction::STAND_STILL)
	{
		return "STAND STILL";
	}
	return "undefined direction";
}

std::string car::getGear() const
{
	if (m_gear == Gear::REVERSE)
	{
		return "REVERSE";
	}
	else if (m_gear == Gear::NEUTRAL)
	{
		return "NEUTRAL";
	}
	else if (m_gear == Gear::FIRST)
	{
		return "FIRST";
	}
	else if (m_gear == Gear::SECOND)
	{
		return "SECOND";
	}
	else if (m_gear == Gear::THIRD)
	{
		return "THIRD";
	}
	else if (m_gear == Gear::FOURTH)
	{
		return "FOURTH";
	}
	else if (m_gear == Gear::FIFTH)
	{
		return "FIFTH";
	}
	return "undefined gear";

}

bool car::TurnOnEngine()
{
	if (!m_engine)
	{
		return m_engine = true;
	}
	return false;
}

bool car::TurnOffEngine()
{
	if (m_engine)
	{
		m_engine = false;
		return true;
	}
	return true;
}

bool car::SetSpeed(int speed)
{
	m_speed = speed;
	return true; //add
}

bool car::SetGear(int gear)
{
	if (!m_engine)
	{
		return false;
	}
	switch(gear)
	{ 
	case(-1):
		if (m_speed == 0 )
		{
			m_gear = Gear::REVERSE;
			return true;
		}
		else
		{
			return false;
		}
	case(0):
		m_gear = Gear::NEUTRAL;
		return true;
	case(1):
	

	}
}

car::~car()
{

}