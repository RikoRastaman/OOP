#include "pch.h"
#include "CTriangle.h"
#include <math.h>
#include <stdexcept>

CTriangle::CTriangle(double side1, double side2, double side3)
{
	if (side1 < 0 || side2 < 0 || side3 < 0)
		throw std::invalid_argument("Negative side size");

	if (side1 > side2 + side3
		|| side2 > side1 + side3
		|| side3 > side1 + side2)
		throw std::domain_error("Degenerate triangle");

	m_side1 = side1;
	m_side2 = side2;
	m_side3 = side3;

	m_perimiter = m_side1 + m_side2 + m_side3;
	double halfPerimiter = m_perimiter / 2;
	m_area = sqrt(halfPerimiter * (halfPerimiter - m_side1) * (halfPerimiter - m_side2) * (halfPerimiter - m_side3));
}

double CTriangle::GetSide1() const
{
	return m_side1;
}

double CTriangle::GetSide2() const
{
	return m_side2;
}

double CTriangle::GetSide3() const
{
	return m_side3;
}

double CTriangle::GetArea() const
{
	return m_area;
}

double CTriangle::GetPerimeter() const
{
	return m_perimiter;
}
