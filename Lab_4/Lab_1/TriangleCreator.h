#pragma once

#include "Triangle.h"

class CTriangleCreator
{
public:
	static CTriangleCreator *GetInstance()
	{
		if (!m_instance)
		{
			m_instance = new CTriangleCreator();
		}
		return m_instance;
	}

	CTriangle *factoryMethod(Point &point1, Point &point2, Point &point3)
	{
		return new CTriangle(point1, point2, point3);
	}

protected:
	CTriangleCreator() {};
	CTriangleCreator(const CTriangleCreator& trgCreator) {};

private:
	static CTriangleCreator *m_instance;
};

