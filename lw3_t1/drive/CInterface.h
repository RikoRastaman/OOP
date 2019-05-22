#pragma once
class CInterface
{
public:

	CInterface(std::istream& input, std::ostream& output, car& car);

	void InicialCommand();
	void ShowInfo(car& car)const;

private:
	bool SetGearByInterface(std::string& str);
	bool SetSpeedByInterface(std::string& str);
	int RecognizeNumber(std::string& str);

	std::istream& m_input;
	std::ostream& m_output;
	car& m_car;
};

