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

	int GetPower(int i) const;
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
	TMonom& operator *= (TMonom& A);

	bool operator > (TMonom &A);
	bool operator < (TMonom &A);
	bool operator == (TMonom &A);

	friend istream& operator >> (istream &istr, TMonom &m);
	friend ostream& operator << (ostream &ostr, const TMonom &m);
};

ostream& operator<<(ostream& ostr, const TMonom& m)
{
	ostr << m.GetCoeff();
	for (int i = 0; i < m.GetN(); i++)
		ostr << "*" << "x" << i << "^" << m.GetPower(i);

	return ostr;
}

istream& operator >> (istream& istr, TMonom& m)
{
	istr >> m.coefficient;
	for (int i = 0; i < m.n; i++)
		istr >> m.power;
	return istr;
}

void TMonom::SetCoeff(double _coeff)
{
	coefficient = _coeff;
}

void TMonom::SetNext(TMonom* _next)
{
	next = _next;
}

int TMonom::GetPower(int i) const
{
	return getDigit(power, i);
}

int TMonom::GetN() const
{
	return n;
}

double TMonom::GetCoeff() const
{
	return coefficient;
}

TMonom* TMonom::GetNext()
{
	return next;
}

bool TMonom::ComparePowers(const TMonom& A)
{
	if (n != A.n)
		return false;
	for (int i = 0; i < n; i++)
		if (getDigit(power, i) != getDigit(A.power, i))
			return false;
	return true;
};

TMonom& TMonom::operator = (const TMonom& A)
{
	coefficient = A.coefficient;
	n = A.n;
	next = A.next;
	power = A.power;
	return *this;
}

TMonom TMonom::operator + (TMonom& A)
{
	TMonom tmp(*this);
	tmp += A;
	return tmp;
}

TMonom& TMonom::operator+=(const TMonom& A)
{
	if (ComparePowers(A))
		coefficient += A.coefficient;
	return *this;
}

TMonom TMonom::operator - (TMonom& A)
{
	TMonom tmp(*this);
	tmp -= A;
	return tmp;
}

TMonom& TMonom::operator-=(const TMonom& A)
{
	if (ComparePowers(A))
		coefficient -= A.coefficient;
	return *this;
}

TMonom TMonom::operator * (TMonom& A)
{
	TMonom tmp(*this);
	tmp *= A;
	return tmp;
}

TMonom& TMonom::operator *= (TMonom& A)
{
	if (n != A.n)
		throw "Error";
	coefficient *= A.coefficient;
	power += A.power;
	return *this;
}


bool TMonom::operator == (TMonom& A)
{
	if (n != A.n)
		throw "Error";
	if (coefficient != A.coefficient)
		return false;
	if (power != A.power)
		return false;
	return true;
}

bool TMonom::operator > (TMonom& A)
{
	if (n != A.n)
		throw "Error";

	if (power == A.power)
	{
		if (coefficient > A.coefficient)
			return true;
		else
			return false;
	}
	else if (power > A.power)
		return true;
	else
		return false;

}

bool TMonom::operator < (TMonom& A)
{
	if (n != A.n)
		throw "Error";

	if (power == A.power)
	{
		if (coefficient < A.coefficient)
			return true;
		else
			return false;
	}
	else if (power < A.power)
		return true;
	else
		return false;

}

TMonom::TMonom()
{
	n = 0;
	next = NULL;
	power = 0;
	coefficient = 0;
}

TMonom::TMonom(int _power, double _coeff)
{
	if (_power < 0)
		throw "Error";
	else if (_power == 0)
	{
		power = 0;
		next = NULL;
		coefficient = _coeff;
		n = 0;
	}
	else
	{
		n = numDigits(_power);
		coefficient = _coeff;
		next = 0;
		power = _power;
	}
}

TMonom::TMonom(const TMonom& A)
{
	n = A.n;
	coefficient = A.coefficient;
	next = A.next;
	if (n != 0) {
		power = A.power;
	}
	else
		power = 0;
}

TMonom::~TMonom()
{
	if (power != 0)
		power = 0;
	n = 0;
	coefficient = 0;
	next = 0;
}

void TMonom::SetPower(int _power)
{
	power = _power;
}

void TMonom::SetN(int _n)
{
	if (_n < 0)
		throw "Error";
	else if (_n == 0)
	{
		if (power != 0)
			power = 0;
	}
	else if (_n != n)
	{
		if (_n > n)
			power *= pow(10, _n);
		else
			power /= pow(10, _n);
	}
	n = _n;
}