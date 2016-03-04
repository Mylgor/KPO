#include "stdafx.h"
#include "Triangle.h"

CTriangle::CTriangle(Point &point1, Point &point2, Point &point3) :
	m_point1(point1), m_point2(point2), m_point3(point3) {}

int CTriangle::GetPerimeter() const
{
	int size1 = sqrt(pow((m_point2.x - m_point1.x), 2) + pow((m_point2.y - m_point1.y), 2));
	int size2 = sqrt(pow((m_point3.x - m_point1.x), 2) + pow((m_point3.y - m_point1.y), 2));
	int size3 = sqrt(pow((m_point3.x - m_point2.x), 2) + pow((m_point3.y - m_point2.y), 2));

	return abs(size1 + size2 + size3);
}

int CTriangle::GetArea() const
{
	int area = abs(((m_point1.x - m_point3.x) * (m_point2.y - m_point3.y) -
		(m_point2.x - m_point3.x) * (m_point1.y - m_point3.y)) / 2);
	return area;
}

std::string CTriangle::GetName() const
{
	return "TRIANGLE";
}