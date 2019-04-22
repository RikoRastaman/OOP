#include <string>
#pragma once

class car
{
public:
	car();
	~car();

	bool getEngineCondition()const;
	std::string getDirection()const;
	int getSpeed()const;
	std::string getGear()const;

	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gear);
	bool SetSpeed(int speed);

private:
	

	enum class Gear { REVERSE, NEUTRAL, FIRST, SECOND, THIRD, FOURTH, FIFTH };
	enum class Direction { FORWARD, STAND_STILL, BACKWARD };
	bool m_engine;
	Gear m_gear;
	Direction m_direction;
	int m_speed;
};

