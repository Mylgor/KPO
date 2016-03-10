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



class RectangleCreator
{
public:
	static CRectangle *GetInstance(Point &point1, Point &point2)
	{
		if (!m_instance)
		{
			m_instance = new CRectangle(point1, point2);
		}
		return m_instance;
	}
private:
	static CRectangle *m_instance;
};