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



class TriangleCreator
{
public:
	static CTriangle *GetInstance(Point &point1, Point &point2, Point &point3)
	{
		if (!m_instance)
		{
			m_instance = new CTriangle(point1, point2, point3);
		}
		return m_instance;
	}
private:
	static CTriangle *m_instance;
};