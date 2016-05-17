#pragma once
#include "ÑFigures.h"
#include "Visitor.h"
#define M_PI 3.14

class CCircle : public ÑFigures
{
public:
	CCircle(Point &point, BigNumber &radius);
	virtual BigNumber GetPerimeter() const;
	virtual BigNumber GetArea() const;
	virtual std::string GetName() const;
	void accept(class Visitor &v, std::ofstream &stream);

private:
	Point m_centerPoint;
	BigNumber m_radius;
};