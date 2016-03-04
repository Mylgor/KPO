#pragma once
#include "ÑFigures.h"

class CTriangle : public ÑFigures
{
public:
	CTriangle(Point &p1, Point &p2, Point &p3);
	virtual int GetPerimeter() const;
	virtual int GetArea() const;
	virtual std::string GetName() const;

private:
	Point m_point1, m_point2, m_point3;
};