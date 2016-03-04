#pragma once
#include "ÑFigures.h"
class CRectangle : public ÑFigures
{
public:
	CRectangle(Point &point1, Point &point2);
	virtual int GetPerimeter() const;
	virtual int GetArea() const;
	virtual std::string GetName() const;

private:
	Point m_point1, m_point2;
};