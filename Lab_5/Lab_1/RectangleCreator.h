#pragma once

#include "Rectangle.h"

class CRectangleCreator
{
public:
	static CRectangleCreator *GetInstance()
	{
		if (!m_instance)
		{
			m_instance = new CRectangleCreator();
		}
		return m_instance;
	}

	CRectangle *factoryMethod(Point &point1, Point &point2)
	{
		return new CRectangle(point1, point2);
	}

protected:
	CRectangleCreator() {};
	CRectangleCreator(const CRectangleCreator& rectCreator) {};

private:
	static CRectangleCreator *m_instance;
};

