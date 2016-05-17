#include "stdafx.h"
#include "CoutVisitor.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include <iostream>

using namespace std;

void CoutVisitor::visit(CRectangle * e, ofstream &stream)
{
	stream << "RECTANGLE" << ": P = " << e->GetPerimeter() << "; S = " << e->GetArea() << endl;
}
void CoutVisitor::visit(CCircle * e, ofstream &stream)
{
	stream << "CICLE" << ": P = " << e->GetPerimeter() << "; S = " << e->GetArea() << endl;
}

void CoutVisitor::visit(CTriangle * e, ofstream &stream)
{
	stream << "TRIANGLE" << ": P = " << e->GetPerimeter() << "; S = " << e->GetArea() << endl;
}
