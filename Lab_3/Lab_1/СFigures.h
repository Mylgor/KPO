#pragma once

////////////////////////////
//������� �����
////////////////////////////
class �Figures
{
public:
	virtual int GetPerimeter() const = 0;
	virtual int GetArea() const = 0;
	virtual std::string GetName() const = 0;
};