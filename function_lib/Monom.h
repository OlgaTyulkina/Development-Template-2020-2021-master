#pragma once
#include <iostream>
#include <string>

using namespace std;

int numDigits(int n)
{
	std::string s = std::to_string(n);
	return s.length();
}

int getDigit(int n, int i)
{
	std::string s = std::to_string(n);
	return (int)s[i] - 48;
}

class TMonom
{
protected:
	int power;      
	int n;           
	double coefficient; 
	TMonom *next; 
public:
	TMonom();
	TMonom(int _power, double _coeff);
	TMonom(const TMonom &A);
	~TMonom();

	void SetPower(int _power);
	void SetN(int _n);
	void SetCoeff(double _coeff);
	void SetNext(TMonom* _next);

	int GetPower(int i);
	int GetN() const;
	double GetCoeff() const;
	TMonom* GetNext();

	bool ComparePowers(const TMonom &A);

	TMonom &operator = (const TMonom &A);
	TMonom operator + (TMonom &A);
	TMonom &operator += (const TMonom &A);
	TMonom operator - (TMonom &A);
	TMonom &operator -= (const TMonom &A);
	TMonom operator * (TMonom &A);

	bool operator > (TMonom &A);
	bool operator < (TMonom &A);
	bool operator == (TMonom &A);

	friend istream& operator >> (istream &istr, TMonom &m);
	friend ostream& operator << (ostream &ostr, const TMonom &m);
};

