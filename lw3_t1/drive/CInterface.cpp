#include "pch.h"
#include "car.h"
#include "CInterface.h"
#include "car.h"

const int MAX_SPEED = 150;
const int MIN_SPEED = 0;
const int MIN_GEAR = -1;
const int MAX_GEAR = 5;

CInterface::CInterface(std::istream& input, std::ostream& output, car& car): m_input(input), m_output(output), m_car(car)
{

}

void CInterface::ShowInfo(car & car)const
{
	car.getEngineCondition()? m_output << "Engine ON" << std::endl : m_output << "Engine OFF" << std::endl;
	m_output << car.getDirection() << std::endl;
	m_output << "Speed: " << car.getSpeed() << std::endl;
	m_output << "Gear: " << car.getGear() << std::endl;
}

bool CInterface::SetGearByInterface(std::string& str)
{
	m_input >> str;
	int number = RecognizeNumber(str);
	if (m_car.SetGear(number))
	{ 
		m_output << "Gear: " << m_car.getGear() << std::endl;
		return true;
	}
	else
	{
		m_output << "Error to change gear. Gear: " << m_car.getGear() << std::endl;
		return false;
	}

}

bool CInterface::SetSpeedByInterface(std::string& str)
{
	m_input >> str;
	int number = RecognizeNumber(str);
	if (m_car.SetSpeed(number))
	{
		m_output << "Speed: " << m_car.getSpeed() << std::endl;
		return true;
	}
	else
	{
		m_output << "Error to change speed. Speed: " << m_car.getSpeed() << std::endl;
		return false;
	}
}

int CInterface::RecognizeNumber(std::string& str)
{
	try
	{
		int number = 0;
		if (number = std::stoi(str));
	}
		catch (const std::invalid_argument&)
	{
		return false;
	}

}


void CInterface ::InicialCommand()
{
	std::string str;

	while (m_input >> str)
	{
		if (str == "Info")
		{
			ShowInfo(m_car);
		}
		else if (str == "EngineOn")
		{
			m_car.TurnOnEngine();
			m_car.getEngineCondition() ? m_output << "Engine On" << std::endl : m_output << "Engine Off" << std::endl;
		}
		else if (str == "EngineOff")
		{
			m_car.TurnOffEngine();
			m_car.getEngineCondition()? m_output << "Engine On" << std::endl : m_output << "Engine Off" << std::endl;
		}
		else if (str == "SetGear")
		{
			SetGearByInterface(str);
		}
		else if (str == "SetSpeed")
		{
			SetSpeedByInterface(str);
		}
		else
		{
			m_output << "Unknown command" << std::endl;
		}
		
	}
}
