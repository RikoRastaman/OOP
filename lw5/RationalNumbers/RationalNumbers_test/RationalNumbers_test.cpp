#include "pch.h"
#include "../RationalNumbers/Rational.h"
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"

TEST_CASE("Test_Greates_Common_Denominator")
{

	REQUIRE(GCD(2, 3) == 1u);
	REQUIRE(GCD(3, 2) == 1u);
	REQUIRE(GCD(12, 8) == 4u);
	REQUIRE(GCD(8, 12) == 4u);
	REQUIRE(GCD(0, 2) == 2u);
	REQUIRE(GCD(2, 0) == 2u);
	REQUIRE(GCD(0, 0) == 1u);
}


void VerifyRational(const CRational & r, int expectedNumerator, int expectedDenominator)
{
	REQUIRE(r.GetNumerator() == expectedNumerator);
	REQUIRE(r.GetDenominator() == expectedDenominator);
}

TEST_CASE("is_0_by_default")
{
	VerifyRational(CRational(), 0, 1);
}

TEST_CASE("can_be_constructed_from_integer")
{
	VerifyRational(CRational(10), 10, 1);
	VerifyRational(CRational(-10), -10, 1);
	VerifyRational(CRational(0), 0, 1);
}

TEST_CASE("can_be_constructed_with_numerator_and_denominator")
{
	VerifyRational(CRational(5, 2), 5, 2);
	VerifyRational(CRational(-5, 2), -5, 2);
	VerifyRational(CRational(5, -2), -5, 2);
	VerifyRational(CRational(-5, -2), 5, 2);
}

TEST_CASE("is_normalized_after_construction")
{
	VerifyRational(CRational(6, 8), 3, 4);
	VerifyRational(CRational(6, -8), -3, 4);
	VerifyRational(CRational(-6, 8), -3, 4);
	VerifyRational(CRational(-6, -8), 3, 4);
	VerifyRational(CRational(-10, 20), -1, 2);
}

TEST_CASE("cant_have_zero_denominator")
{
	REQUIRE_THROWS_AS(CRational(1, 0), std::invalid_argument);
}

TEST_CASE("rational_can_be_converted_to_double")
{
	CRational r(3, 5);
	REQUIRE(r.ToDouble() == 0.6);
}

TEST_CASE("has_unary_plus_that_return_itself")
{
	VerifyRational(+CRational(3, 5), 3, 5);
	VerifyRational(+CRational(-3, 5), -3, 5);
}

TEST_CASE("has_unary_minus_that_negates_itself")
{
	VerifyRational(-CRational(3, 5), -3, 5);
	VerifyRational(-CRational(-3, 5), 3, 5);
}

TEST_CASE("has_binary_addition_operation")
{
	VerifyRational(CRational(1, 2) + CRational(1, 6), 2, 3);
	VerifyRational(CRational(1, 2) + 1, 3, 2);
	VerifyRational(1 + CRational(1, 2), 3, 2);
}

TEST_CASE("has_binary_subtraction_operation")
{
	VerifyRational(CRational(1, 2) - CRational(1, 6), 1, 3);
	VerifyRational(CRational(1, 2) - 1, -1, 2);
	VerifyRational(1 - CRational(1, 2), 1, 2);
}

TEST_CASE("has_adding_assignment_operator")
{
	VerifyRational(CRational(1, 2) += CRational(1, 6), 2, 3);
	VerifyRational(CRational(1, 2) += 1, 3, 2);
	VerifyRational(CRational(1, 2) += CRational(0, 6), 1, 2);
}

TEST_CASE("has_subtracting_assignment_operator")
{
	VerifyRational(CRational(1, 2) -= CRational(1, 6), 1, 3);
	VerifyRational(CRational(1, 2) -= 1, -1, 2);
	VerifyRational(CRational(1, 2) -= CRational(0, 6), 1, 2);
}

TEST_CASE("has_binary_multiplication_operation")
{
	VerifyRational(CRational(1, 2) * CRational(2, 3), 1, 3);
	VerifyRational(CRational(1, 2) * (-3), -3, 2);
	VerifyRational(7 * CRational(2, 3), 14, 3);
}

TEST_CASE("has_division_operation")
{
	VerifyRational(CRational(1, 2) / CRational(2, 3), 3, 4);
	VerifyRational(CRational(1, 2) / 5, 1, 10);
	VerifyRational(7 / CRational(2, 3), 21, 2);
	REQUIRE_THROWS_AS(CRational(2, 3) / 0, std::invalid_argument);
	REQUIRE_THROWS_AS(CRational(2, 3) / CRational(0, 1), std::invalid_argument);
}

TEST_CASE("has_multiply_assignment_operator")
{
	VerifyRational(CRational(1, 2) *= CRational(2, 3), 1, 3);
	VerifyRational(CRational(1, 2) *= 3, 3, 2);
}

TEST_CASE("has_division_assignment_operator")
{
	VerifyRational(CRational(1, 2) /= CRational(2, 3), 3, 4);
	VerifyRational(CRational(3, 4) /= CRational(3, 8), 2, 1);
	VerifyRational(CRational(1, 2) /= 3, 1, 6);
	REQUIRE_THROWS_AS((CRational(2, 3) /= 0), std::invalid_argument);
}

TEST_CASE("can_be_compared_for_equality")
{
	REQUIRE((CRational(1, 2) == CRational(1, 2)));
	REQUIRE((CRational(1, 3) == CRational(2, 6)));
	REQUIRE((CRational(4, 1) == 4));
	REQUIRE((3 == CRational(3, 1)));
	REQUIRE((!(CRational(1, 2) == CRational(2, 3))));
	REQUIRE((!(CRational(1, 2) == 7)));
	REQUIRE(!(3 == CRational(2, 3)));
	REQUIRE(!(CRational(1, 2) != CRational(1, 2)));
	REQUIRE(!(CRational(1, 3) != CRational(2, 6)));
	REQUIRE(!(CRational(4, 1) != 4));
	REQUIRE(!(3 != CRational(3, 1)));
	REQUIRE((CRational(1, 2) != CRational(2, 3)));
	REQUIRE((CRational(1, 2) != 7));
	REQUIRE((3 != CRational(2, 3)));
}

TEST_CASE("less")
{
	REQUIRE((CRational(1, 2) < 7));
	REQUIRE(!(7 < CRational(1, 3)));
	REQUIRE((CRational(1, 2) < CRational(2, 3)));
	REQUIRE(!(CRational(1, 2) < CRational(1, 4)));
}

TEST_CASE("less_or_equal")
{
	REQUIRE(!(CRational(1, 2) <= CRational(1, 3)));
	REQUIRE((3 <= CRational(7, 2)));
	REQUIRE((CRational(1, 4) <= CRational(1, 2)));
	REQUIRE((CRational(6, 2) <= 3));
}

TEST_CASE("more")
{
	REQUIRE((CRational(3, 1) > 2));
	REQUIRE(!(CRational(1, 2) > 7));
	REQUIRE((CRational(1, 2) > CRational(1, 4)));
	REQUIRE(!(CRational(1, 4) > CRational(2, 3)));
}

TEST_CASE("more_or_equal")
{
	REQUIRE((CRational(1, 2) >= CRational(1, 3)));
	REQUIRE(!(3 >= CRational(8, 2)));
	REQUIRE(!(CRational(1, 4) >= CRational(1, 3)));
	REQUIRE((CRational(8, 4) >= 2));
}

TEST_CASE("rational_can_be_converted_to_compound_fraction")
{
	{
		CRational r(9, 4);
		std::pair<int, CRational> compoundRational = r.ToCompoundFraction();
		REQUIRE(compoundRational.first == 2);
		VerifyRational(compoundRational.second, 1, 4);
	}

	{
		CRational r(-8, 3);
		std::pair<int, CRational> compoundRational = r.ToCompoundFraction();
		REQUIRE(compoundRational.first == -2);
		VerifyRational(compoundRational.second, -2, 3);
	}

	{
		CRational r(5, 6);
		std::pair<int, CRational> compoundRational = r.ToCompoundFraction();
		REQUIRE(compoundRational.first == 0);
		VerifyRational(compoundRational.second, 5, 6);
	}
}