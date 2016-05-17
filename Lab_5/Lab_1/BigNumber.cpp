// BigNumber.cpp: определяет экспортированные функции для приложения DLL.
//
#include "stdafx.h"
#include "BigNumber.h"

using namespace std;

vector<int> ReverseVector(vector<int> const &vec)
{
	vector<int> tempStr;
	for (int i = vec.size() - 1; i >= 0; i--)
	{
		tempStr.push_back(vec[i]);
	}
	return tempStr;
}

int ModINT(int number)
{
	if (number < 0)
		number *= -1;
	return number;
}

int DifferenceLenght(vector<int> const &number1, vector<int> const &number2)
{
	int dif = number1.size() - number2.size();
	dif = ModINT(dif);
	return dif;
}

BigNumber::BigNumber(int count)
{
	for (int i = 0; i < count; i++)
	{
		m_number.push_back(0);
	}
}

BigNumber::BigNumber()
{}

BigNumber PowMegNumber(BigNumber const &number, int x)
{
	BigNumber tempNumber = number;
	if (x == 0)
	{
		tempNumber += 0;
	}
	else if (x > 0)
	{
		for (int i = 1; i < x; i++)
		{
			tempNumber = tempNumber * number;
		}
	}
	return tempNumber;
}

BigNumber SqrtMegNumber(const BigNumber &number)
{
	BigNumber l, r = number;
	BigNumber res;

	BigNumber one;
	BigNumber two;
	one += 1;
	two += 2;
	
	int count = 0;
	while (l <= r)
	{
		BigNumber m = (l + r) / two;
		if (m * m <= number)
		{
			if (res < m)
				res = m;
			l = m + one;
		}
		else
		{
			r = m - one;
		}
		count++;
		if (count > 300)
			break;
	}
	return res;
}

string BigNumber::ToString() const
{
	string str = "";
	if (m_number.size() != 0)
	{
		for (int i = 0; i < m_number.size(); i++)
		{
			str += char(m_number[i] + '0');
		}
	}
	else
	{
		str = "NULL";
	}
	return str;
}

vector<int> BigNumber::GetNumber() const
{
	return m_number;
}

void BigNumber::SetNumber(vector<int> const &number)
{
	m_number = number;
}

size_t BigNumber::length() const
{
	return m_number.size();
}

int const &BigNumber::operator [](int ind) const
{
	return m_number[ind];
}

int &BigNumber::operator [](int ind)
{
	return m_number[ind];
}

void const BigNumber::operator +=(int number)
{
	m_number.push_back(number);
}

void BigNumber::Erase(int index)
{
	m_number.erase(m_number.begin() + index);
}

BigNumber const BigNumber::ReverseMegaNumber(BigNumber &megNumber) const
{
	BigNumber tempMegNumber;
	for (int i = megNumber.length() - 1; i >= 0; i--)
	{
		tempMegNumber += megNumber[i];
	}
	return tempMegNumber;
}

BigNumber const BigNumber::operator +(BigNumber const &number) const
{
	BigNumber answer;
	vector<int> number1 = ReverseVector(number.GetNumber());
	vector<int> number2 = ReverseVector(m_number);
	bool whichIsBigger;
	int len, c, m, t;
	len = c = m = t = 0;
	int dif = DifferenceLenght(number1, number2);

	if (number1.size() < number2.size())
	{
		len = number1.size();
		whichIsBigger = true;
	}
	else
	{
		len = number2.size();
		whichIsBigger = false;
	}
	for (int i = 0; i < len; i++)
	{
		t = number1[i] + number2[i] + m;
		c = t % 10;
		m = t / 10;
		answer += c;
	}
	for (int i = 0; i < dif; i++)
	{
		if (whichIsBigger)
		{
			if (m != 0)
			{
				answer += number2[len + i] + m;
				m = 0;
			}
			else
			{
				answer += number2[len + i];
			}
		}
		else
		{
			if (m != 0)
			{
				answer += number1[len + i] + m;
				m = 0;
			}
			else
			{
				answer += number1[len + i];
			}
		}
	}
	if (m != 0)
		answer += m;
	return ReverseMegaNumber(answer);
}

void BigNumber::Minus(vector<int> &number1, vector<int> &number2, BigNumber &answer, int len) const
{
	for (int i = 0; i < len; i++)
	{
		if (i < number2.size())
		{
			if (number1[i] >= number2[i])
			{
				answer += number1[i] - number2[i];
			}
			else
			{
				number1[i + 1]--;
				answer += 10 - number2[i] + number1[i];
			}
		}
		else
		{
			if (number1[i] < 0)
			{
				if (i != len - 1)
				{
					answer += 9;
					number1[i + 1]--;
				}
			}
			else
			{
				answer += number1[i];
			}
		}
	}
}

std::ostream & operator <<(std::ostream  &stream, BigNumber &numb)
{
	stream << numb.ToString();
	return stream;
}

BigNumber const BigNumber::operator -(int number) const
{
	BigNumber tempNumber;
	int a;

	do
	{
		a = number % 10;
		number /= 10;
		tempNumber += a;
	} while (number != 0);

	return *this - ReverseMegaNumber(tempNumber);
}

BigNumber const BigNumber::operator -(BigNumber const &number) const
{
	BigNumber answer;
	vector<int> number1 = ReverseVector(number.GetNumber());
	vector<int> number2 = ReverseVector(m_number);
	int k = 3;
	int len = number1.size();
	if (number1.size() > number2.size())
	{
		len = number1.size();
		k = 1;
	}
	else
	{
		if (number2.size() > number1.size())
		{
			len = number2.size();
			k = 2;
		}
		else
		{
			for (int ix = len - 1; ix >= 0; ix--)
			{
				if (number1[ix] > number2[ix])
				{
					k = 1;
					break;
				}

				if (number2[ix] > number1[ix])
				{
					k = 2;
					break;
				}
			}
		}
	}
	if (k == 1)
		Minus(number1, number2, answer, len);
	else if (k == 2)
		Minus(number2, number1, answer, len);
	else if (k == 3)
	{
		answer += 0;
		return answer;
	}
	while (answer[len - 1] <= 0 && len > 1)
	{
		len--;
		answer.Erase(len);
	}
	return ReverseMegaNumber(answer);
}

BigNumber const BigNumber::operator *(BigNumber const &number) const
{
	vector<int> number1 = ReverseVector(number.GetNumber());
	vector<int> number2 = ReverseVector(m_number);
	int len = number1.size() + number2.size() + 1;
	BigNumber answer(len);
	for (int i = 0; i < number1.size(); i++)
	{
		for (int j = 0; j < number2.size(); j++)
		{
			answer[i + j] += number1[i] * number2[j];
		}
	}

	for (int i = 0; i < len - 1; i++)
	{
		answer[i + 1] += answer[i] / 10;
		answer[i] %= 10;
	}

	while (answer[len - 1] == 0 && answer.length() != 1)
	{
		len--;
		answer.Erase(len);
	}
	return ReverseMegaNumber(answer);
}

BigNumber const BigNumber::operator *(int number) const
{
	BigNumber answer;
	if (number == 0)
	{
		answer += 0;
		return answer;
	}
	else
	{
		int l = 0, k;
		for (int i = m_number.size() - 1; i >= 0; i--)
		{
			int composition = m_number[i] * number + l;
			k = composition % 10;
			l = composition / 10;
			answer += k;
		}
		if (l != 0)
			answer += l;
		return ReverseMegaNumber(answer);
	}
}

int BigNumber::GetMaxPossibleNumber(BigNumber &number1, BigNumber &number2) const
{
	BigNumber checkNumber;
	int i;
	for (i = 0; i <= 9; i++)
	{
		checkNumber = number2 * i;

		if (ComparNumber(number1, checkNumber) == -1)
		{
			break;
		}
	}
	return i - 1;
}

bool const BigNumber::operator ==(BigNumber const &number) const
{
	if (number.length() != length())
	{
		return false;
	}
	else
	{
		for (int i = 0; i < length(); i++)
		{
			if (number[i] != m_number[i])
			{
				return false;
			}
		}
	}
	return true;
}

bool const BigNumber::operator >=(BigNumber const &number) const
{
	if (number.length() > m_number.size())
	{
		return false;
	}
	else if (number.length() < m_number.size())
	{
		return true;
	}
	else if (number.length() == m_number.size())
	{
		for (int i = 0; i < m_number.size(); i++)
		{
			if (m_number[i] < number[i])
			{
				return false;
			}
			else if (m_number[i] > number[i])
			{
				return true;
			}
		}
	}
	return true;
}

bool const BigNumber::operator <(BigNumber const &number) const
{
	if (number.length() > m_number.size())
	{
		return true;
	}
	else if (number.length() < m_number.size())
	{
		return false;
	}
	else if (number.length() == m_number.size())
	{
		for (int i = 0; i < m_number.size(); i++)
		{
			if (m_number[i] < number[i])
			{
				return true;
			}
			else if (m_number[i] > number[i])
			{
				return false;
			}
		}
		return false;
	}
}

bool const BigNumber::operator <=(BigNumber const &number) const
{
	if (number.length() > m_number.size())
	{
		return true;
	}
	else if (number.length() < m_number.size())
	{
		return false;
	}
	else if (number.length() == m_number.size())
	{
		for (int i = 0; i < m_number.size(); i++)
		{
			if (m_number[i] < number[i])
			{
				return true;
			}
			else if(m_number[i] > number[i])
			{
				return false;
			}
		}
		return true;
	}
}

BigNumber const BigNumber::operator /(BigNumber const &number) const
{
	BigNumber answer;
	if (number.length() > m_number.size())
	{
		answer += 0;
		return answer;
	}
	else
	{
		BigNumber curNumber;
		BigNumber number1 = *this;
		BigNumber number2 = number;
		if (number2[0] == 0)
		{
			throw overflow_error("Devide by zero");
		}
		int count = 0;
		int len = number1.length();
		for (count = 0; count < number2.length(); count++)
		{
			curNumber += number1[count];
		}
		do
		{
			while (curNumber[0] == 0 && count < len && number1[count] == 0)
			{
				answer += 0;
				count++;
			}
			if (count <= len)
			{
				if (curNumber[0] == 0 && count != len)
				{
					curNumber[0] = number1[count++];
				}
				while (ComparNumber(curNumber, number2) == -1 && count != len)
				{
					curNumber += number1[count++];
				}
				int i = GetMaxPossibleNumber(curNumber, number2);
				if (curNumber[0] != 0)
				{
					answer += i;
					curNumber = curNumber - number2 * i;
				}
			}
		} while (count < len);

		return answer;
	}
}

BigNumber const BigNumber::operator =(vector<int> const &number)
{
	if (m_number.size() != 0)
		m_number.clear();
	this->SetNumber(number);
	return *this;
}

BigNumber const BigNumber::operator =(BigNumber const &number)
{
	if (m_number.size() != 0)
		m_number.clear();
	this->SetNumber(number.GetNumber());
	return *this;
}

int BigNumber::ComparNumber(BigNumber &number1, BigNumber &number2) const
{
	if (number1.length() > number2.length())
		return 1;
	else if (number1.length() < number2.length())
		return -1;
	else
	{
		for (int i = 0; i < number1.length(); i++)
		{
			if (number1[i] > number2[i])
				return 1;
			else if (number1[i] < number2[i])
				return -1;
		}
		return 0;
	}
}