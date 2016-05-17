#pragma once
#include "Visitor.h"

class CoutVisitor : public Visitor
{
public:
	void visit(CRectangle * e, std::ofstream &stream);
	void visit(CCircle * e, std::ofstream &stream);
	void visit(CTriangle * e, std::ofstream &stream);
};

