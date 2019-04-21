#include <string>
#pragma once
class car
{
public:
	car();
	~car();

	//bool getEngineCondition();
	//std::string getDirection()const;
	//int getSpeed()const;
	//std::string getGear()const;

	//bool TurnOnEngine();
	//bool TurnOffEngine();
	bool SetGear(int gear);
	//bool SetSpeed(int speed);

private:
	bool m_engine;

	enum class GearName { REVERSE = -1, NEUTRAL = 0, FIRST = 1, SECOND = 2, THIRD = 3, FOURTH = 4, FIFTH = 5 };

	enum class Direction { FORWARD, STAND_STILL, BACKWARD };

	GearName m_gear;
};

