#pragma once
#include "BigNumber.h"

////////////////////////////
//������� �����
////////////////////////////
class �Figures
{
public:
	virtual BigNumber GetPerimeter() const = 0;
	virtual BigNumber GetArea() const = 0;
	virtual std::string GetName() const = 0;
};

struct Point
{
	BigNumber x, y;
};