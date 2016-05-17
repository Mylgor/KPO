#pragma once
#include "�Figures.h"
#include "Visitor.h"

class CRectangle : public �Figures
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