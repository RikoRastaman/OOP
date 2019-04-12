#pragma once
#include <set>

std::set<int> CrossSet(std::set<int> const& set1, std::set<int> const& set2);
int sumDigit(int n);
std::set<int> addSumWithNoRemainder(std::set<int>&noRemainder, int maxNumber);
std::set<int> addEvenSum(std::set<int>&evenSum, int maxNumber);
void printSet(std::set<int>&setToprint);