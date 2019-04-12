#pragma once
#include <string>
#include <map>

std::string uppercaseToLower(std::string str);
void checkInDictionary(std::map<std::string, int> &dictionary, std::string str);
void printFrequency(std::map<std::string, int> &dictionary);