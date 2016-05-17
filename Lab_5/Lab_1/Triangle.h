#pragma once
#include "ÑFigures.h"
#include "Visitor.h"

class CTriangle : public ÑFigures
{
public:
	CTriangle(Point &p1, Point &p2, Point &p3);
	virtual BigNumber GetPerimeter() const;
	virtual BigNumber GetArea() const;
	virtual std::string GetName() const;
	void accept(class Visitor &v, std::ofstream &stream);

private:
	Point m_point1, m_point2, m_point3;
	BigNumber m_area;
	BigNumber m_perimeter;
};