#include "pch.h"
#include "lw2_t3/map/map/map_functions.h"
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE("apper case to lower case")
{
	std::string str1 = "APPER CASE";
	std::string str2 = "apper case";
	str1 = uppercaseToLower(str1);

	REQUIRE( str1 == str2);
}

TEST_CASE("apper case with empty string")
{
	std::string str1 = "";
	std::string str2 = "";

	REQUIRE(str1 == str2);
}

TEST_CASE("check word in empty dictionary")
{
	std::map<std::string, int>originalDictionary = {};
	std::map<std::string, int>editedDictionary = { {"word", 1} };
	std::string str = "word";
	checkInDictionary(originalDictionary, str);

	REQUIRE(originalDictionary == editedDictionary);
}

TEST_CASE("add word to dictionary")
{
	std::map<std::string, int>originalDictionary = { {"word", 1} };
	std::map<std::string, int>editedDictionary = { {"word", 2} };
	std::string str = "word";
	checkInDictionary(originalDictionary, str);

	REQUIRE(originalDictionary == editedDictionary);
}

TEST_CASE("check empty string in dictionary")
{
	std::map<std::string, int>originalDictionary = { {"word", 1} };
	std::map<std::string, int>editedDictionary = { {"word", 1} };
	std::string str = "";
	checkInDictionary(originalDictionary, str);

	REQUIRE(originalDictionary == editedDictionary);
}
