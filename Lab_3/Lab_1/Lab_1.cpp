// Lab_1.cpp: определяет точку входа для консольного приложения.
// Vasyukov Dmitriy 

#include "stdafx.h"
#include "СFigures.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

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
	string number = "";
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
			number += symbol;
		}
		else
		{
			if (number != "")
			{
				switch (count)
				{
				case 0:
					points[index].x = stoi(number);
					count++;
					break;
				case 1:
					points[index].y = stoi(number);
					count = 0;
					index++;
					isWrite = false;
					break;
				}
			}
			number = "";
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

	Point point1 = Point();
	Point point2 = Point();
	Point point3 = Point();

	ifstream readSteam(argv[1]);
	ofstream outputStream(argv[2]);

	СFigures *figure = nullptr;

	while (!readSteam.eof())
	{
		string nameFigures = GetNameFigures(readSteam);

		try
		{
			if (nameFigures == "TRIANGLE")
			{
				vector<Point> points = { point1, point2, point3 };
				GetVetices(readSteam, points);
				figure = TriangleCreator::GetInstance(points[0], points[1], points[2]);
				points.clear();
			}
			else if (nameFigures == "RECTANGLE")
			{
				vector<Point> points = { point1, point2 };
				GetVetices(readSteam, points);

				figure = RectangleCreator::GetInstance(points[0], points[1]);
				points.clear();
			}
			else if (nameFigures == "CIRCLE")
			{
				vector<Point> points = { point1, point2 };
				GetVetices(readSteam, points);

				figure = CircleCreator::GetInstance(points[0], points[1].x);
				points.clear();
			}
			else
			{
				cout << "Неизвестная фигура: " << nameFigures << endl;
			}

			if (figure != nullptr)
			{
				PrintAreaAndPerimeter(figure, outputStream);
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

