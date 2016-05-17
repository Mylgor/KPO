#pragma once
#include "ÑFigures.h"
#include "Visitor.h"

class CRectangle : public ÑFigures
{
public:
	CRectangle(Point &point1, Point &point2);
	virtual BigNumber GetPerimeter() const;
	virtual BigNumber GetArea() const;
	virtual std::string GetName() const;
	void accept(class Visitor &v, std::ofstream &stream);

private:
	Point m_point1, m_point2;
};