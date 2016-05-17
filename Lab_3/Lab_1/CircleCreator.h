#pragma once

#include "Circle.h"

class CCircleCreator
{
public:
	static CCircleCreator *GetInstance()
	{
		if (!m_instance)
		{
			m_instance = new CCircleCreator();
		}
		return m_instance;
	}

	CCircle *factoryMethod(Point &point, int radius)
	{
		return new CCircle(point, radius);
	}

protected:
	CCircleCreator() {};
	CCircleCreator(const CCircleCreator& circleCreator) {};

private:
	static CCircleCreator *m_instance;
};

