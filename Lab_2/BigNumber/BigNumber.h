#ifdef BIGNUMBER_EXPORTS
#define BIGNUMBER_API __declspec(dllexport) 
#else
#define BIGNUMBER_API __declspec(dllimport) 
#endif

namespace BigNumber
{
	class CMegaNumber
	{
	public:
		BIGNUMBER_API CMegaNumber();
		BIGNUMBER_API CMegaNumber(int count);

		BIGNUMBER_API std::vector<int> GetNumber() const;
		BIGNUMBER_API void SetNumber(std::vector<int> const &number);
		BIGNUMBER_API size_t length() const;
		BIGNUMBER_API CMegaNumber const ReverseMegaNumber(CMegaNumber &megNumber) const;
		BIGNUMBER_API std::string ToString();
		BIGNUMBER_API void Erase(int index);

		BIGNUMBER_API CMegaNumber const operator =(std::vector<int> const &number);
		BIGNUMBER_API CMegaNumber const operator =(CMegaNumber const &number);

		BIGNUMBER_API CMegaNumber const operator +(CMegaNumber const &number) const;
		BIGNUMBER_API CMegaNumber const operator -(CMegaNumber const &number) const;
		BIGNUMBER_API CMegaNumber const operator *(CMegaNumber const &number) const;
		BIGNUMBER_API CMegaNumber const operator *(int number) const;
		BIGNUMBER_API CMegaNumber const operator /(CMegaNumber const &number) const;

		BIGNUMBER_API int &operator [](int ind);
		BIGNUMBER_API void const operator +=(int number);

	private:
		void Minus(std::vector<int> &number1, std::vector<int> &number2, CMegaNumber &answer, int len) const;
		int ComparNumber(CMegaNumber &number1, CMegaNumber &number2) const;
		int GetMaxPossibleNumber(CMegaNumber &number1, CMegaNumber &number2) const;

		std::vector<int> m_number;
	};
}