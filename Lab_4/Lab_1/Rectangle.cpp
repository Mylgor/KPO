#include "stdafx.h"
#include "Rectangle.h"

CRectangle::CRectangle(Point &point1, Point &point2) :
	m_point1(point1), m_point2(point2) {}

BigNumber CRectangle::GetPerimeter() const
{
	BigNumber perimeter = ((m_point2.x - m_point1.x) + (m_point2.y - m_point1.y)) * 2;
	return perimeter;
}

BigNumber CRectangle::GetArea() const
{
	BigNumber area = (m_point1.x - m_point2.x) * (m_point1.y - m_point2.y);
	return area;
}
std::string CRectangle::GetName() const
{
	return "RECTANGLE";
}