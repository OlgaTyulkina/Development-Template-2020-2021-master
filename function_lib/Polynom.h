#pragma once

#include <iostream>
#include "Monom.h"

using namespace std;

class TPolynom
{
protected:
	TMonom *start;
	int n;          
	int k;          
public:
	TPolynom();
	TPolynom(int _n);
	TPolynom(const TPolynom &A);
	~TPolynom();

	int GetN();
	int GetSize();
	TMonom* GetStart();
	TPolynom operator-(TPolynom &A);
	TPolynom operator+(TPolynom &A);
	TPolynom& operator=(const TPolynom &A);
	bool operator==(const TPolynom &A);
	bool operator!=(const TPolynom &A);
	TPolynom operator*(TPolynom &A);
	TPolynom& operator+=(const TMonom &m);
	TPolynom& operator-=(const TMonom &m);
	friend std::ostream& operator<<(std::ostream &ostr, TPolynom& Tm);
};

TPolynom::TPolynom()
{
	n = 0;
	k = 0;
	start = NULL;
}

TPolynom::TPolynom(int _n)
{
	if (_n <= 0)
		throw "Error";
	n = _n;
	k = 0;
	start = NULL;
}

TPolynom::TPolynom(const TPolynom &A)
{
	n = A.n;
	k = A.k;
	if (A.start == NULL)
		start = NULL;
	else
	{
		start = new TMonom(*A.start);
		for (TMonom* i = A.start->GetNext(); i != NULL; i = i->GetNext())
		{
			start->SetNext(new TMonom(*i));
		}
	}
}

TPolynom::~TPolynom()
{
	if (start == NULL)
		return;
	TMonom* next_elem;
	for (TMonom* i = start; i != NULL; )
	{
		next_elem = i->GetNext();
		i->~TMonom();
		i = next_elem;
	}
}

int TPolynom::GetN()
{
	return n;
}

int TPolynom::GetSize()
{
	return k;
}

TMonom* TPolynom::GetStart()
{
	return start;
}

TPolynom& TPolynom::operator=(const TPolynom &A)
{
	if (*this != A)
	{
		if (start != NULL)
		{
			TMonom* next_elem;
			for (TMonom* i = start; i != NULL; )
			{
				next_elem = i->GetNext();
				i->~TMonom();
				i = next_elem;
			}
		}

		start = new TMonom(*A.start);
		TMonom* source_elem = start;
		for (TMonom* i = A.start->GetNext(); i != NULL; i = i->GetNext())
		{
			source_elem->SetNext(new TMonom(*i));
			source_elem = source_elem->GetNext();
		}

		n = A.n;
		k = A.k;
	}
	return *this;
}

TPolynom &TPolynom::operator+=(const TMonom &m)
{
	if (m.GetCoeff() == 0)
		return *this;
	if (start == NULL)
	{
		start = new TMonom(m);
		start->SetCoeff(start->GetCoeff());
		k++;
	}
	else
	{
		TMonom* last_elem = NULL;
		for (TMonom *ptr = start; ptr != NULL; ptr = ptr->GetNext())
		{
			if (ptr->ComparePowers(m))
			{
				*ptr += m;
				break;
			}
			else if (ptr->GetNext() == NULL)
			{
				last_elem = ptr;
			}
		}

		if (last_elem != NULL)
		{
			last_elem->SetNext(new TMonom(m));
			last_elem->SetCoeff(last_elem->GetCoeff());
			k++;
		}
	}
	return *this;
}


TPolynom &TPolynom::operator-=(const TMonom &m)
{

	if (m.GetCoeff() == 0)
		return *this;
	if (start == NULL)
	{
		start = new TMonom(m);
		start->SetCoeff(start->GetCoeff() * (-1));
		k++;
	}
	else
	{
		TMonom* last_elem = NULL;
		for (TMonom *ptr = start; ptr != NULL; ptr = ptr->GetNext())
		{
			if (ptr->ComparePowers(m))
			{
				*ptr -= m;
				break;
			}
			else if (ptr->GetNext() == NULL)
			{
				last_elem = ptr;
			}
		}

		if (last_elem != NULL)
		{
			last_elem->SetNext(new TMonom(m));
			last_elem->SetCoeff(last_elem->GetCoeff() * (-1));
			k++;
		}
	}
	return *this;
}

bool TPolynom::operator==(const TPolynom &A)
{
	if (this->n != A.n)
		throw "Error";
	if (this->k != A.k)
		return false;
	for (TMonom* source_ptr = start; source_ptr != NULL; source_ptr = source_ptr->GetNext())
		for (TMonom* p_ptr = start; p_ptr != NULL; p_ptr = p_ptr->GetNext())
		{
			if (*source_ptr == *p_ptr)
			{
				break;
			}
			else if (p_ptr->GetNext() == NULL)
			{
				return false;
			}
		}
	return true;
}

bool TPolynom::operator!=(const TPolynom &A)
{
	return !(*this == A);
}

TPolynom TPolynom::operator*(TPolynom &A)
{
	if (n != A.n)
		throw "Error";
	TPolynom tmp(n);

	for (TMonom* source_ptr = start; source_ptr != NULL; source_ptr = source_ptr->GetNext())
		for (TMonom* p_ptr = A.start; p_ptr != NULL; p_ptr = p_ptr->GetNext())
		{
			tmp += (*source_ptr) * (*p_ptr);
		}
	return tmp;
}

TPolynom TPolynom::operator+(TPolynom &A)
{
	TPolynom tmp(A);

	for (TMonom* p_ptr = start; p_ptr != NULL; p_ptr = p_ptr->GetNext())
	{
		tmp += *p_ptr;
	}

	return tmp;
}

TPolynom TPolynom::operator-(TPolynom &A)
{
	TPolynom tmp(A);

	for (TMonom* p_ptr = start; p_ptr != NULL; p_ptr = p_ptr->GetNext())
	{
		tmp -= *p_ptr;
	}

	return tmp;
}

ostream& operator<<(ostream &ostr, TPolynom& Tm)
{
	if (Tm.start == NULL)
		ostr << "Empty";
	else
	{
		for (TMonom* ptr = Tm.start; ptr != NULL; ptr = ptr->GetNext())
		{
			ostr << *ptr;
			if (ptr->GetNext() != NULL)
				ostr << "+";
		}
	}
	return ostr;
}