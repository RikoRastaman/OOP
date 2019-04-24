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
	

	enum class Gear { REVERSE = -1, NEUTRAL, FIRST, SECOND, THIRD, FOURTH, FIFTH };
	enum class Direction { FORWARD, STAND_STILL, BACKWARD };
	bool m_engine;
	Gear m_gear;
	Direction m_direction;
	int m_speed;

	struct speedRange
	{
		int gear_minSpeed;
		int gear_maxSpeed;
	};

	const speedRange REVERSE_SPEED = { 0, 20 };
	const speedRange NEUTRAL_SPEED = { 0, 150 };
	const speedRange FIRST_SPEED = { 0, 30 };
	const speedRange SECOND_SPEED = { 20, 50 };
	const speedRange THIRD_SPEED = { 30, 60 };
	const speedRange FOURTH_SPEED = { 40, 60 };
	const speedRange FIFTH_SPEED = { 50, 150 };
};

