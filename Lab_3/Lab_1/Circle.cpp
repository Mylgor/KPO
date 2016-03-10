#include "stdafx.h"
#include "Circle.h"

CCircle::CCircle(Point &point, int &radius) :
	m_centerPoint(point), m_radius(radius) {}

int CCircle::GetPerimeter() const
{
	int perimeter = abs(2.0 * M_PI * (double)m_radius);
	return perimeter;
}

int CCircle::GetArea() const
{
	int area = abs(M_PI * pow(m_radius, 2));
	return area;
}

std::string CCircle::GetName() const
{
	return "CIRCLE";
}

CCircle *CircleCreator::m_instance = 0;