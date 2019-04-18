#include "pch.h"
#include <iostream>
#include <string>
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "lw2_t2/FindAndReplace/FindAndReplace/FindAndReplace_functions.h"

TEST_CASE("find and replace string")
{
	std::string originalString = "old old";
	std::string searchString = "old";
	std::string replaceString = "new";
	std::string editedString = "new new";
	originalString = findAndReplace(originalString, searchString, replaceString);
	REQUIRE(originalString == editedString);
}

TEST_CASE("find and replace in empty string")
{
	std::string originalString = "";
	std::string searchString = "old";
	std::string replaceString = "new";
	std::string editedString = "";
	originalString = findAndReplace(originalString, searchString, replaceString);
	REQUIRE(originalString == editedString);
}

TEST_CASE("find and replace with empty search string")
{
	std::string originalString = "old old";
	std::string searchString = "";
	std::string replaceString = "new";
	std::string editedString = "old old";
	originalString = findAndReplace(originalString, searchString, replaceString);
	REQUIRE(originalString == editedString);
}

TEST_CASE("find and replace with empty replace string")
{
	std::string originalString = "old old";
	std::string searchString = "old";
	std::string replaceString = "";
	std::string editedString = "old old";
	originalString = findAndReplace(originalString, searchString, replaceString);
	REQUIRE(originalString == editedString);
}

--заменить 2 пробела на 1 и 1 пробел на 2 , в строке из 10 пробелов