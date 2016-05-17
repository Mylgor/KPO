// Lab_1.cpp: определяет точку входа для консольного приложения.
// Vasyukov Dmitriy 

#include "stdafx.h"
#include "СFigures.h"
#include "Circle.h"
#include "CircleCreator.h"
#include "Rectangle.h"
#include "RectangleCreator.h"
#include "Triangle.h"
#include "TriangleCreator.h"
#include "BigNumber.h"
#include "CoutVisitor.h"

using namespace std;


string GetNameFigures(ifstream &readStream)
{
	char symbol;
	bool isFind = true;
	string nameFigures = "";

	while ((!readStream.eof()) && isFind)
	{
		readStream.get(symbol);
		
		if (symbol == ':')
			isFind = false;
		else
			nameFigures += symbol;
	}

	return nameFigures;
}

void GetVetices(ifstream &readStream, vector<Point> &points)
{
	char symbol = ' ';
	vector<int> number;
	int count = 0;
	int index = 0;
	bool isWrite = false;	
	bool endFile = false;

	while (!endFile && symbol != '\n')
	{
		readStream.get(symbol);
		if (readStream.eof())
			endFile = true;

		if (symbol >= '0' && symbol <= '9' && isWrite && !endFile)
		{
			number.push_back(symbol - '0');
		}
		else
		{
			if (number.size() != 0)
			{
				switch (count)
				{
				case 0:
					points[index].x = number;
					count++;
					break;
				case 1:
					points[index].y = number;
					count = 0;
					index++;
					isWrite = false;
					break;
				}
			}
			number.clear();
		}

		if (symbol == '=' || symbol == ':')
			isWrite = true;
	}
}

void PrintAreaAndPerimeter(СFigures *figure, ofstream &outputStream)
{
	cout << figure->GetName() << ": P = " << figure->GetPerimeter() << "; S = " << figure->GetArea() << endl;
}


int main(int argс, char *argv[])
{
	setlocale(LC_ALL, "Russian");

	if (argс < 3)
	{
		cout << "Неверное число переданных параметров" << endl;
		return 1;
	}

	ifstream readSteam(argv[1]);
	ofstream outputStream(argv[2]);

	СFigures *figure = nullptr;

	CTriangleCreator* triangleCreator = CTriangleCreator::GetInstance();
	CRectangleCreator* rectCreator = CRectangleCreator::GetInstance();
	CCircleCreator* circCreator = CCircleCreator::GetInstance();

	CoutVisitor cVisit;

	while (!readSteam.eof())
	{
		string nameFigures = GetNameFigures(readSteam);

		try
		{
			if (nameFigures == "TRIANGLE")
			{
				vector<Point> points = { Point(), Point(), Point() };
				GetVetices(readSteam, points);

				figure = triangleCreator->factoryMethod(points[0], points[1], points[2]);

				points.clear();
			}
			else if (nameFigures == "RECTANGLE")
			{
				vector<Point> points = { Point(), Point()};
				GetVetices(readSteam, points);
				
				figure = rectCreator->factoryMethod(points[0], points[1]);

				points.clear();
			}
			else if (nameFigures == "CIRCLE")
			{
				vector<Point> points = { Point(), Point() };
				GetVetices(readSteam, points);
			
				figure = circCreator->factoryMethod(points[0], points[1].x);

				points.clear();
			}
			else
			{
				cout << "Неизвестная фигура: " << nameFigures << endl;
				figure = nullptr;
			}

			if (figure != nullptr)
			{
				figure->accept(cVisit, outputStream);
				delete figure;
			}
		}
		catch (const std::exception &ex)
		{
			cout << ex.what() << endl;
		}
	}



	outputStream.close();
	readSteam.close();
    return 0;
}

