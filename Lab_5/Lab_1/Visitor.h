#pragma once

class CCircle;
class CRectangle;
class CTriangle;

class Visitor
{
public:
	virtual void visit(CCircle * e, std::ofstream &stream) = 0;
	virtual void visit(CRectangle * e, std::ofstream &stream) = 0;
	virtual void visit(CTriangle * e, std::ofstream &stream) = 0;
};