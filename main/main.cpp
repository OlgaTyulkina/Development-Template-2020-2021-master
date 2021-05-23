#include <iostream>
#include <locale.h>

#include "Polynom.h"

using namespace std;

int main()
{
	TMonom A(121, 5);
	TMonom B(1214, 2);
	cout << "Monom A = " << A << endl;
	cout << "Monom B = " << B << endl;

	TPolynom P(3);
	P += A;
	P += B;
	cout << "\nPolynom P = A + B = " << P << endl;

	TPolynom P2(P);
	cout << "Polynom P2(P) = " << P2 << endl;

	TPolynom P3(3);
	P3 = P + P2;
	cout << "\nPolynom P3 = P + P2 = " << P3 << endl;

	return 0;
}