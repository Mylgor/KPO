#pragma once
#include "ÑFigures.h"

#define M_PI 3.14

class CCircle : public ÑFigures
{
public:
	CCircle(Point &point, BigNumber &radius);
	virtual BigNumber GetPerimeter() const;
	virtual BigNumber GetArea() const;
	virtual std::string GetName() const;

private:
	Point m_centerPoint;
	BigNumber m_radius;
};