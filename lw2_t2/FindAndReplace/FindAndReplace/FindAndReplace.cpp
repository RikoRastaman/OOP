#include "pch.h"
#include <iostream>
#include <string>

const std::string ARG_ERROR = "Wrong number of arguments, please enter: ""search string"" and ""replace string"" ";
std::string findAndReplace(std::string& originalString, const std::string& search, const std::string& replace)
{
	size_t pos = 0;
	while ((pos = originalString.find(search, pos)) != std::string::npos) {
		originalString.replace(pos, search.length(), replace);
		pos += replace.length();
	}
	return originalString;
}

int main(int argc, char* argv[])
{	
	std::string originalString = "";


	if (argc != 3)
	{
		std::cout << ARG_ERROR << "\n";
		exit(1);
	}
	
	while (getline(std::cin, originalString))
	{
		originalString = findAndReplace(originalString, argv[1], argv[2]);
		std::cout << originalString << std::endl;
	}
	return 0;
}
