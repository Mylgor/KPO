#pragma once
#include "BigNumber.h"

////////////////////////////
//¡¿«Œ¬€…  À¿——
////////////////////////////
class —Figures
{
public:
	virtual BigNumber GetPerimeter() const = 0;
	virtual BigNumber GetArea() const = 0;
	virtual std::string GetName() const = 0;
	virtual void accept(class Visitor &v, std::ofstream &stream) = 0;
};

struct Point
{
	BigNumber x, y;
};