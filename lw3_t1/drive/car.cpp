#include "pch.h"
#include "car.h"
#include <string>

const std::string GEAR_ERROR = "undefined gear";
const std::string DIRECTION_ERROR = "undefined direction";

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
	return DIRECTION_ERROR;
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
	return GEAR_ERROR;

}

bool car::TurnOnEngine()
{
	if (!m_engine)
	{
		m_engine = true;
		return true;
	}
	return true;
}

bool car::TurnOffEngine()
{
	if (!m_engine) return true;
	if (m_engine && m_speed == 0 && m_gear == Gear::NEUTRAL)
	{
		m_engine = false;
		return true;
	}
	return false;
}

bool car::SetSpeed(int speed)
{
	if (speed == 0)
	{
		m_speed = speed;
		m_direction = Direction::STAND_STILL;
		return true;
	}

	if (!m_engine)
	{
		return false;
	}
	switch (m_gear)
	{
	case Gear::REVERSE:
		if (speed <= REVERSE_SPEED.gear_maxSpeed && speed >= REVERSE_SPEED.gear_minSpeed)
		{
			m_speed = speed;
			m_direction = Direction::BACKWARD;
			return true;
		}
		return false;
	case Gear::NEUTRAL:
		if (m_speed < speed)
		{
			return false;
		}
		m_speed = speed;
		return true;
	case Gear::FIRST:
		if (speed <= FIRST_SPEED.gear_maxSpeed && speed >= FIRST_SPEED.gear_minSpeed)
		{
			m_speed = speed;
			m_direction = Direction::FORWARD;
			return true;
		}
		return false;
	case Gear::SECOND:
		if (speed <= SECOND_SPEED.gear_maxSpeed && speed >= SECOND_SPEED.gear_minSpeed)
		{
			m_speed = speed;
			m_direction = Direction::FORWARD;
			return true;
		}
		return false;
	case Gear::THIRD:
		if (speed <= THIRD_SPEED.gear_maxSpeed && speed >= THIRD_SPEED.gear_minSpeed)
		{
			m_speed = speed;
			m_direction = Direction::FORWARD;
			return true;
		}
		return false;
	case Gear::FOURTH:
		if (speed <= FOURTH_SPEED.gear_maxSpeed && speed >= FOURTH_SPEED.gear_minSpeed)
		{
			m_speed = speed;
			m_direction = Direction::FORWARD;
			return true;
		}
		return false;
	case Gear::FIFTH:
		if (speed <= FIFTH_SPEED.gear_maxSpeed && speed >= FIFTH_SPEED.gear_minSpeed)
		{
			m_speed = speed;
			m_direction = Direction::FORWARD;
			return true;
		}
		return false;
	default:
		return false;
	}
}

bool car::SetGear(int gear)
{
	if (m_gear == Gear(gear))
	{
		return true;
	}

	if (!m_engine)
	{
		return false;
	}

	switch(gear)
	{ 
		case -1:
			if (m_speed == 0)
			{
				m_gear = Gear::REVERSE;
				return true;
			}
			else
			{
				return false;
			}
		case 0:
			m_gear = Gear::NEUTRAL;
			return true;
		case 1:
			if (m_gear == Gear::REVERSE)
			{
				if (m_speed == 0)
				{
					m_gear = Gear::FIRST;
					return true;
				}
				return false;
			}
			if (m_gear == Gear::NEUTRAL && m_direction == Direction::BACKWARD)
			{
				return false;
			}
			
			if (m_speed <= FIRST_SPEED.gear_maxSpeed && m_speed >= FIRST_SPEED.gear_minSpeed)
			{
				m_gear = Gear::FIRST;
				return true;
			}
			return false;
		case 2:
			if (m_speed <= SECOND_SPEED.gear_maxSpeed && m_speed >= SECOND_SPEED.gear_minSpeed)
			{
				m_gear = Gear::SECOND;
				return true;
			}
			return false;
		case 3:
			if (m_speed <= THIRD_SPEED.gear_maxSpeed && m_speed >= THIRD_SPEED.gear_minSpeed)
			{
				m_gear = Gear::THIRD;
				return true;
			}
			return false;
		case 4:
			if (m_speed <= FOURTH_SPEED.gear_maxSpeed && m_speed >= FOURTH_SPEED.gear_minSpeed)
			{
				m_gear = Gear::FOURTH;
				return true;
			}
			return false;
		case 5:
			if (m_speed <= FIFTH_SPEED.gear_maxSpeed && m_speed >= FIFTH_SPEED.gear_minSpeed)
			{
				m_gear = Gear::FIFTH;
				return true;
			}
			return false;
		default:
			return false;
	}
}

car::~car()
{

}