#include "pch.h"
#include <iostream>
#include <string>
#include "FindAndReplace_functions.h"


const std::string ARG_ERROR = "Wrong number of arguments, please enter: ""search string"" and ""replace string"" ";


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
