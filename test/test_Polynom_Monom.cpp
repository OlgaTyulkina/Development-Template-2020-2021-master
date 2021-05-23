#include "Polynom.h"

#include <gtest.h>

TEST(TMonom, can_create_default_monom)
{
	ASSERT_NO_THROW(TMonom A);
}

TEST(TMonom, can_set_and_get_power)
{
	int a[3] = { 1,2,3 };
	TMonom A;
	ASSERT_NO_THROW(A.SetPower(123));
	ASSERT_EQ(1, A.GetPower(0));
	ASSERT_EQ(2, A.GetPower(1));
	ASSERT_EQ(3, A.GetPower(2));
}

TEST(TMonom, can_set_and_get_size)
{
	TMonom A;
	ASSERT_NO_THROW(A.SetN(5));
	ASSERT_EQ(5, A.GetN());
}

TEST(TMonom, can_sum_monoms_with_equal_size)
{
	TMonom A(123, 3.1);
	TMonom B(123, 0.5);
	ASSERT_NO_THROW(A + B);
	TMonom C;
	C = A + B;
	ASSERT_EQ(3.6, C.GetCoeff());
}

TEST(TMonom, can_subtract_monoms_with_equal_size)
{
	TMonom A(123, 3.1);
	TMonom B(123, 0.5);
	ASSERT_NO_THROW(A - B);
	TMonom C;
	C = A - B;
	ASSERT_EQ(2.6, C.GetCoeff());
}

TEST(TMonom, can_multiply_monoms_with_equal_size)
{
	int a[3] = { 1,2,3 };
	int a2[3] = { 3,2,1 };
	TMonom A(123, 3.1);
	TMonom B(321, 0.5);
	ASSERT_NO_THROW(A * B);
	TMonom C;
	C = A * B;
	ASSERT_EQ(3.1*0.5, C.GetCoeff());
	for (int i = 0; i < 3; i++)
		ASSERT_EQ(C.GetPower(i), 4);
}

TEST(TMonom, can_equivalence_equal_monoms)
{
	int a[3] = { 1,2,3 };
	TMonom A(123, 3.1);
	TMonom B(123, 3.1);
	ASSERT_TRUE(A == B);
}

TEST(TPolynom, can_create_polynom)
{
	ASSERT_NO_THROW(TPolynom A);
}

TEST(TPolynom, can_create_polynom_with_positive_n)
{
	ASSERT_NO_THROW(TPolynom A(4));
}

TEST(TPolynom, throws_when_create_polynom_with_negative_n)
{
	ASSERT_ANY_THROW(TPolynom A(-4));
}

TEST(TPolynom, can_create_copy_polynom)
{
	TPolynom A(3);
	ASSERT_NO_THROW(TPolynom B(A));
	TPolynom C(A);
	ASSERT_EQ(C.GetSize(), 0);
	ASSERT_EQ(C.GetN(), 3);
	if (C.GetStart() != NULL)
		ASSERT_TRUE(false);
}

TEST(TPolynom, can_sum_polynoms_with_equal_n)
{
	TPolynom P1(2);
	TPolynom P2(2);
	ASSERT_NO_THROW(P1 + P2);
}

TEST(TPolynom, can_subtract_polynoms_with_equal_n)
{
	TPolynom P1(2);
	TPolynom P2(2);
	ASSERT_NO_THROW(P1 - P2);
}

TEST(TMonom, can_sum_monoms_with_diff_size)
{
	TMonom A(123, 3.1);
	TMonom B(1234, 0.5);
	TPolynom P;
	ASSERT_NO_THROW(P += A);
	ASSERT_NO_THROW(P += B);
}

TEST(TMonom, can_subtract_monoms_with_diff_size)
{
	TMonom A(123, 3.1);
	TMonom B(1234, 0.5);
	TPolynom P;
	ASSERT_NO_THROW(P -= A);
	ASSERT_NO_THROW(P -= B);
}
