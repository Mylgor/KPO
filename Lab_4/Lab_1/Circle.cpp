#include "stdafx.h"
#include "Circle.h"

CCircle::CCircle(Point &point, BigNumber &radius) :
	m_centerPoint(point), m_radius(radius) {}

BigNumber CCircle::GetPerimeter() const
{
	BigNumber perimeter = m_radius * 2 * M_PI;
	return perimeter;
}

BigNumber CCircle::GetArea() const
{
	BigNumber area = PowMegNumber(m_radius, 2) * M_PI;
	return area;
}

std::string CCircle::GetName() const
{
	return "CIRCLE";
}