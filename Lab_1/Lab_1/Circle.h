#pragma once
#include "�Figures.h"
#define M_PI 3.14

class CCircle : public �Figures
{
public:
	CCircle(Point &point1, int &radius);
	virtual int GetPerimeter() const;
	virtual int GetArea() const;
	virtual std::string GetName() const;

private:
	Point m_centerPoint;
	int m_radius;
};