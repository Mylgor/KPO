// Lab_2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "BigNumber.h"

using namespace std;

bool CheckSymbolOnEqualOper(char symbol)
{
	if ((symbol == '+') || (symbol == '-') || (symbol == '*') || (symbol == '/'))
		return true;
	return false;
}

void ReadDataFromFile(vector<int> &number1, vector<int> &number2, char &oper, ifstream &readStream)
{

	bool firstOrSecondNumber = true;
	bool endFile = false;
	vector<int> tempNumber;
	char symbol = ' ';
	while (!endFile && symbol != '\n')
	{
		readStream.get(symbol);
		if (readStream.eof())
			endFile = true;

		if (CheckSymbolOnEqualOper(symbol))
		{
			oper = symbol;
		}
		if (symbol >= '0' && symbol <= '9' && !endFile)
		{
			tempNumber.push_back(atoi(&symbol));
		}
		else
		{
			if (tempNumber.size() != 0 && symbol != ' ')
			{
				if (firstOrSecondNumber)
				{
					number1 = tempNumber;
					firstOrSecondNumber = !firstOrSecondNumber;
				}
				else
				{
					number2 = tempNumber;
				}
				tempNumber.clear();
			}
		}
	}
}

void PrintAnswer(BigNumber::CMegaNumber &number1, BigNumber::CMegaNumber &number2, 
	BigNumber::CMegaNumber &answer, char oper, ofstream &writeStream)
{
	cout << number1.ToString() << " " << oper << " " << number2.ToString() << " = " << answer.ToString() << endl;
}

int main()
{
	char oper = ' ';
	int numberLine = 0;
	vector<int> number1, number2;
	ifstream readStream("input.txt");
	ofstream writeStream("output.txt");
	if (!readStream.is_open())
		return 1;

	while (!readStream.eof())
	{
		ReadDataFromFile(number1, number2, oper, readStream);
		numberLine++;

		if (oper == '+')
		{
			BigNumber::CMegaNumber megaNumber1, megaNumber2, answer;
			megaNumber1 = number1;
			megaNumber2 = number2;
			answer = megaNumber1 + megaNumber2;
			PrintAnswer(megaNumber1, megaNumber2, answer, oper, writeStream);
		}
		else if (oper == '-')
		{
			BigNumber::CMegaNumber megaNumber1, megaNumber2, answer;
			megaNumber1 = number1;
			megaNumber2 = number2;
			answer = megaNumber1 - megaNumber2;
			PrintAnswer(megaNumber1, megaNumber2, answer, oper, writeStream);
		}
		else if (oper == '*')
		{
			BigNumber::CMegaNumber megaNumber1, megaNumber2, answer;
			megaNumber1 = number1;
			megaNumber2 = number2;
			answer = megaNumber1 * megaNumber2;
			PrintAnswer(megaNumber1, megaNumber2, answer, oper, writeStream);
		}
		else if (oper == '/')
		{
			BigNumber::CMegaNumber megaNumber1, megaNumber2, answer;
			megaNumber1 = number1;
			megaNumber2 = number2;
			answer = megaNumber1 / megaNumber2;
			PrintAnswer(megaNumber1, megaNumber2, answer, oper, writeStream);
		}
		else
		{
			cout << "Error: read line - " << numberLine << endl;
		}

		if (number1.size() != 0)
			number1.clear();
		if (number2.size() != 0)
			number2.clear();
		oper = ' ';
	}

	readStream.close();
	writeStream.close();

	return 0;
}