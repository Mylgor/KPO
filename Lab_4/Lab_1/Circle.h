#pragma once
#include "�Figures.h"

#define M_PI 3.14

class CCircle : public �Figures
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