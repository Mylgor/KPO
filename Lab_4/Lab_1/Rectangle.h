#pragma once
#include "�Figures.h"

class CRectangle : public �Figures
{
public:
	CRectangle(Point &point1, Point &point2);
	virtual BigNumber GetPerimeter() const;
	virtual BigNumber GetArea() const;
	virtual std::string GetName() const;

private:
	Point m_point1, m_point2;
};