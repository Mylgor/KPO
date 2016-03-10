#pragma once
#include "ÑFigures.h"
#define M_PI 3.14

class CCircle : public ÑFigures
{
public:
	CCircle(Point &point, int &radius);
	virtual int GetPerimeter() const;
	virtual int GetArea() const;
	virtual std::string GetName() const;

private:
	Point m_centerPoint;
	int m_radius;
};



class CircleCreator : CCreator
{
public:
	static CCircle *GetInstance(Point &point, int radius)
	{
		if (!m_instance)
		{
			m_instance = new CCircle(point, radius);
		}
		return m_instance;
	}
private:
	static CCircle *m_instance;
};