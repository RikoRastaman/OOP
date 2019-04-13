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

TEST_CASE("sum digit with zero argument")
{
	REQUIRE(sumDigit(0) == 0);
}

TEST_CASE("add to set numbers with even sums")
{
	std::set<int>originalSet = {};
	std::set<int>returnedSet = {2, 4, 6, 8};
	originalSet = addEvenSum(originalSet, 10);

	REQUIRE(originalSet == returnedSet);
}

TEST_CASE("add to set numbers with even sums with zero as argument")
{
	std::set<int>originalSet = {};
	std::set<int>returnedSet = {};
	originalSet = addEvenSum(originalSet, 0);

	REQUIRE(originalSet == returnedSet);
}

TEST_CASE("add to set numbers without remainder")
{
	std::set<int>originalSet = {};
	std::set<int>returnedSet = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	originalSet = addSumWithNoRemainder(originalSet, 10);

	REQUIRE(originalSet == returnedSet);
}

TEST_CASE("add to set numbers without remainder with zero as argument")
{
	std::set<int>originalSet = {};
	std::set<int>returnedSet = {};
	originalSet = addSumWithNoRemainder(originalSet, 0);

	REQUIRE(originalSet == returnedSet);
}

TEST_CASE("cross sets with common numbers")
{
	std::set<int>firstSet = {1, 2, 3, 4, 5};
	std::set<int>secondSet = {3, 4, 5, 6, 7, 8};
	std::set<int>returnedSet = {3, 4, 5};
	firstSet = CrossSet(firstSet, secondSet);

	REQUIRE(returnedSet == firstSet);
}

TEST_CASE("cross sets without common numbers")
{
	std::set<int>firstSet = { 1, 2, 3, 4, 5 };
	std::set<int>secondSet = { 6, 7, 8, 9 };
	std::set<int>returnedSet = {};
	firstSet = CrossSet(firstSet, secondSet);

	REQUIRE(returnedSet == firstSet);
}

TEST_CASE("cross set with empty set")
{
	std::set<int>firstSet = {};
	std::set<int>secondSet = { 6, 7, 8, 9 };
	std::set<int>returnedSet = {};
	firstSet = CrossSet(firstSet, secondSet);

	REQUIRE(returnedSet == firstSet);
}