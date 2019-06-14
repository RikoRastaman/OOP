#include <iostream>
#include "../triangle/CTriangle.h"
#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"

void checkTriangle(CTriangle triangle, double side1, double side2, double side3)
{
	CHECK((triangle.GetSide1() == side1));
	CHECK((triangle.GetSide2() == side2));
	CHECK((triangle.GetSide3() == side3));
}

TEST_CASE("negative side size")
{
	REQUIRE_THROWS_WITH(CTriangle(-2, -1, 3), "Negative side size");
	REQUIRE_THROWS_AS(CTriangle(-2, -1, 3), std::invalid_argument);
}

TEST_CASE("exception one side longer then sum of others")
{
	REQUIRE_THROWS_WITH(CTriangle(10, 12, 24), "Degenerate triangle");
	REQUIRE_THROWS_AS(CTriangle(10, 12, 24), std::domain_error);
}

TEST_CASE("zero sides")
{
	checkTriangle(CTriangle(0, 0, 0), 0, 0, 0);
}

TEST_CASE("create triangle mesure perimeter and area")
{
	CTriangle triangle(3, 4, 5);
	checkTriangle(triangle, 3, 4, 5);
	CHECK(triangle.GetPerimeter() == 12);
	CHECK(triangle.GetArea() == 6.0);
}

TEST_CASE("create degenerated triangle with one side equals others")
{
	checkTriangle(CTriangle(1, 2 , 3), 1, 2, 3);
}

TEST_CASE("get sides")
{
	CTriangle triangle(3, 4, 5);
	checkTriangle(triangle, 3, 4, 5);
	CHECK(triangle.GetSide1() == 3);
	CHECK(triangle.GetSide2() == 4);
	CHECK(triangle.GetSide3() == 5);
}