#include "pch.h"
#include <iostream>
#define CATCH_CONFIG_MAIN 
#include <catch2/catch.hpp>
#include "lw2_t1/vector/vector/vector_functions.h"

TEST_CASE("minimum float")
{
	vector<float>massiv = { 0.1, 0.2, 0.3, 0.4 };
	REQUIRE(findMinimum(massiv) == 0.1f);
}

TEST_CASE("minimum empty")
{
	vector<float>massiv = {};
	REQUIRE(findMinimum(massiv) == NULL);
}

TEST_CASE("multiple on integer")
{
	vector<float>massiv = { 1.1, 1.2, 1.3, 1.4, 1.5 };
	vector<float>result = { 2.2, 2.4, 2.6, 2.8, 3.0 };
	int multipler = 2;
	multiplicMassiv(massiv, multipler);
	REQUIRE(massiv  == result);
}

TEST_CASE("multiple on zero")
{
	vector<float>massiv = { 1.1, 1.2, 1.3, 1.4, 1.5 };
	vector<float>result = { 0, 0, 0, 0, 0 };
	int multipler = 0;
	multiplicMassiv(massiv, multipler);
	REQUIRE(massiv == result);
}

TEST_CASE("sort massiv")
{
	vector<float>massiv = { 9.1, 2.1, 4.1, 1.1, 8.1 };
	vector<float>result = { 1.1, 2.1, 4.1, 8.1, 9.1 };
	sortMassiv(massiv);
	REQUIRE(massiv == result);
}

TEST_CASE("sort empty massiv")
{
	vector<float>massiv = {};
	vector<float>result = {};
	sortMassiv(massiv);
	REQUIRE(massiv == result);
}