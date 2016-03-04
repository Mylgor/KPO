// BigNumber.cpp: определяет экспортированные функции для приложения DLL.
//

#include "stdafx.h"
#include "BigNumber.h"
#include <stdexcept>

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





namespace BigNumber
{
	CMegaNumber::CMegaNumber(int count)
	{
		for (int i = 0; i < count; i++)
		{
			m_number.push_back(0);
		}
	}

	CMegaNumber::CMegaNumber()
	{}

	string CMegaNumber::ToString()
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

	vector<int> CMegaNumber::GetNumber() const
	{
		return m_number;
	}

	void CMegaNumber::SetNumber(vector<int> const &number)
	{
		m_number = number;
	}

	size_t CMegaNumber::length() const
	{
		return m_number.size();
	}

	int &CMegaNumber::operator [](int ind)
	{
		return m_number[ind];
	}

	void const CMegaNumber::operator +=(int number)
	{
		m_number.push_back(number);
	}

	void CMegaNumber::Erase(int index)
	{
		m_number.erase(m_number.begin() + index);
	}

	CMegaNumber const CMegaNumber::ReverseMegaNumber(CMegaNumber &megNumber) const
	{
		CMegaNumber tempMegNumber;
		for (int i = megNumber.length() - 1; i >= 0; i--)
		{
			tempMegNumber += megNumber[i];
		}
		return tempMegNumber;
	}

	CMegaNumber const CMegaNumber::operator +(CMegaNumber const &number) const
	{
		CMegaNumber answer;
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

	void CMegaNumber::Minus(vector<int> &number1, vector<int> &number2, CMegaNumber &answer, int len) const
	{
		for (int i = 0; i < len; i++)
		{
			if (answer.length() <= i)
				answer += 0;

			if (i < (len - 1))
			{
				number1[i + 1]--;
				answer[i] += (10 + number1[i]);
			}
			else  
				answer[i] += number1[i]; 

			if (answer[i] > 0 && i <= (number2.size() - 1))
				answer[i] -= number2[i];

			if (answer[i] / 10 > 0)
			{
				if (answer.length() <= i + 1 && i != (len - 2))
				{
					answer += 0;
					answer[i + 1]++;
				}
				answer[i] %= 10;
			}
			else if (i == len - 1 && answer[i] != 0)
				answer[i]++;
		}
	}

	CMegaNumber const CMegaNumber::operator -(CMegaNumber const &number) const
	{
		CMegaNumber answer;
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
		while (answer[len - 1] <= 0)
		{
			len--;
			answer.Erase(len);
		}
		return ReverseMegaNumber(answer);
	}

	CMegaNumber const CMegaNumber::operator *(CMegaNumber const &number) const
	{
		vector<int> number1 = ReverseVector(number.GetNumber());
		vector<int> number2 = ReverseVector(m_number);
		int len = number1.size() + number2.size() + 1;
		CMegaNumber answer(len);
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

	CMegaNumber const CMegaNumber::operator *(int number) const
	{
		CMegaNumber answer;
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

	int CMegaNumber::GetMaxPossibleNumber(CMegaNumber &number1, CMegaNumber &number2) const
	{
		CMegaNumber checkNumber;
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

	CMegaNumber const CMegaNumber::operator /(CMegaNumber const &number) const
	{
		CMegaNumber answer;
		if (number.length() > m_number.size())
		{
			answer += 0;
			return answer;
		}
		else
		{
			CMegaNumber curNumber;
			CMegaNumber number1 = *this;
			CMegaNumber number2 = number;
			int count = 0;
			int len = number1.length();
			for (count = 0; count < number2.length(); count++)
			{
				curNumber += number1[count];
			}
			while (count < len)
			{
				while (curNumber[0] == 0 && count < len && number1[count] == 0)
				{
					answer += 0;
					count++;
				}
				if (count < len)
				{
					while (ComparNumber(curNumber, number2) == -1)
					{
						curNumber += number1[count++];
					}
					int i = GetMaxPossibleNumber(curNumber, number2);
					answer += i;
					curNumber = curNumber - number2 * i;
				}
			}
			return answer;
		}
	}
	
	CMegaNumber const CMegaNumber::operator =(vector<int> const &number)
	{
		if (m_number.size() != 0)
			m_number.clear();
		this->SetNumber(number);
		return *this;
	}

	CMegaNumber const CMegaNumber::operator =(CMegaNumber const &number)
	{
		if (m_number.size() != 0)
			m_number.clear();
		this->SetNumber(number.GetNumber());
		return *this;
	}

	int CMegaNumber::ComparNumber(CMegaNumber &number1, CMegaNumber &number2) const
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
}