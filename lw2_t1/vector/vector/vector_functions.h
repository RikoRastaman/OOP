#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <string>

using namespace std;

void readFromInput(vector<float>& massivForRead);
void printMassiv(vector<float>& massivForPrint);
float findMinimum(vector<float>& massiv);
void multiplicMassiv(vector<float>& massiv, float multiplicator);
void sortMassiv(vector<float>& massiv);
