#pragma once
#include <vector>
#include <string>
#include <stdexcept>

class BigNumber
{
public:
	BigNumber();
	BigNumber(int count);

	std::vector<int> GetNumber() const;
	void SetNumber(std::vector<int> const &number);
	size_t length() const;
	BigNumber const ReverseMegaNumber(BigNumber &megNumber) const;
	std::string ToString() const;
	void Erase(int index);

	BigNumber const operator =(std::vector<int> const &number);
	BigNumber const operator =(BigNumber const &number);

	friend std::ostream & operator <<(std::ostream &stream, BigNumber& numb);
	BigNumber const operator +(BigNumber const &number) const;

	BigNumber const operator -(BigNumber const &number) const;
	BigNumber const operator -(int number) const;

	BigNumber const operator *(BigNumber const &number) const;
	BigNumber const operator *(int number) const;

	BigNumber const operator /(BigNumber const &number) const;

	bool const operator ==(BigNumber const &number) const;
	bool const operator <=(BigNumber const &number) const;
	bool const operator >=(BigNumber const &number) const;
	bool const operator <(BigNumber const &number) const;

	int const &operator [](int ind) const;
	int &operator [](int ind);
	void const operator +=(int number);

private:
	void Minus(std::vector<int> &number1, std::vector<int> &number2, BigNumber &answer, int len) const;
	int ComparNumber(BigNumber &number1, BigNumber &number2) const;
	int GetMaxPossibleNumber(BigNumber &number1, BigNumber &number2) const;

	std::vector<int> m_number;
};

std::ostream& operator <<(std::ostream &stream, BigNumber& numb);
BigNumber PowMegNumber(BigNumber const &number, int x);
BigNumber SqrtMegNumber(const BigNumber &number);