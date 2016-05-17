#include "stdafx.h"
#include "Triangle.h"

CTriangle::CTriangle(Point &point1, Point &point2, Point &point3) :
	m_point1(point1), m_point2(point2), m_point3(point3) 
{
	BigNumber size1 = SqrtMegNumber(PowMegNumber((m_point2.x - m_point1.x), 2) + PowMegNumber((m_point2.y - m_point1.y), 2));
	BigNumber size2 = SqrtMegNumber(PowMegNumber((m_point3.x - m_point1.x), 2) + PowMegNumber((m_point3.y - m_point1.y), 2));
	BigNumber size3 = SqrtMegNumber(PowMegNumber((m_point3.x - m_point2.x), 2) + PowMegNumber((m_point3.y - m_point2.y), 2));

	m_perimeter = size1 + size2 + size3;
	m_area = SqrtMegNumber(m_perimeter * (m_perimeter - size1) * (m_perimeter - size2) * (m_perimeter - size3));
}

BigNumber CTriangle::GetPerimeter() const
{
	return m_perimeter;
}

BigNumber CTriangle::GetArea() const
{
	return m_area;
}

std::string CTriangle::GetName() const
{
	return "TRIANGLE";
}

void CTriangle::accept(class Visitor &v, std::ofstream &stream)
{
	v.visit(this, stream);
}