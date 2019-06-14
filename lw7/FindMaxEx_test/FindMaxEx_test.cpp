#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include <iostream>
#include <string>
#include "../FindMaxEx/FindMaxExFunctions.h"

struct SMan
{
	std::string name;
	double height;
	double weight;
};


bool IsHeigher(const SMan& lhs, const SMan& rhs)
{
	return (lhs.height < rhs.height);
}

bool IsMoreWeight(const SMan& lhs, const SMan& rhs)
{
	return (lhs.weight < rhs.weight);
}

void VerifyMan(const SMan& lhs, const SMan& rhs)
{
	REQUIRE(lhs.name == rhs.name);
	REQUIRE(lhs.height == rhs.height);
	REQUIRE(lhs.height == rhs.height);
}

SMan Ivan = { "Ivan", 195.0, 94.0 };
SMan Petr = { "Petr", 175.5, 75.5 };
SMan Dima = { "Dima", 191.3, 100 };

std::vector<SMan> men = {
	Ivan,
	Petr,
	Dima
};

TEST_CASE("Find man with max height")
{
	SMan highestMan;

	REQUIRE((FindMax(men, highestMan, IsHeigher)));

	VerifyMan(highestMan, Ivan);
}

TEST_CASE("Find man with max weight")
{
	SMan heaviestMan;

	REQUIRE(FindMax(men, heaviestMan, IsMoreWeight));

	VerifyMan(heaviestMan, Dima);
}

TEST_CASE("Test FindMax function with empty array")
{
	float maxNum = 0;
	REQUIRE_FALSE(FindMax({}, maxNum, [](const auto& lhi, const auto& rhi) {
		return (lhi < rhi);
	}));
	REQUIRE(maxNum == 0);
}

TEST_CASE("Exception check FindMax without last parametr")
{
	float maxNum = 0;
	REQUIRE_NOTHROW(FindMax({}, maxNum));
	REQUIRE(( maxNum == 0));
}

TEST_CASE("Find max without third parameter")
{
	int maxNum = 0;
	REQUIRE(FindMax({ -1, 1, 0, 15, 5 }, maxNum));
	REQUIRE(maxNum == 15);
}

TEST_CASE("Find min element in chars array by FindMax function")
{
	char minCh = '#';
	REQUIRE(FindMax({ 'a', 'b', 'c', 'e', 'd' }, minCh, [](const auto& lhc, const auto& rhc) {
		return (lhc > rhc);
	}));
	REQUIRE(minCh == 'a');
}