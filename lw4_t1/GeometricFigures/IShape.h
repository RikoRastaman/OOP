#pragma once
#include <string>
#include <cstdint>

class IShape
{
public:
	IShape() = default;;
	virtual ~IShape() = default;;

	virtual double GetArea() const = 0;;
	virtual double GetPerimetre() const = 0;;
	virtual std::string ToString() const = 0;;
	virtual std::string GetOutlineColor() const = 0;;

};