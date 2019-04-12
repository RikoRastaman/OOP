#include "pch.h"
#include "lw2_t4/CrossSet/CrossSet/CrossSet_functions.h"
#include <iostream>
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE("sum digit")
{
	REQUIRE(sumDigit(1) == 1);
	REQUIRE(sumDigit(12) == 3);
	REQUIRE(sumDigit(256) == 13);
	REQUIRE(sumDigit(999) == 27);
	REQUIRE(sumDigit(100000000) == 1);
}

TEST_CASE("sum digit when zero")
{
	REQUIRE(sumDigit(0) == 0);
}
