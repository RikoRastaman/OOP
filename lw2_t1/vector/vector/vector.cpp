#include "pch.h"
#include "vector_functions.h"

int main()
{
	vector<float> massiv;
	readFromInput(massiv);
	findMinimum(massiv);
	multiplicMassiv(massiv, findMinimum(massiv));
	sortMassiv(massiv);
	printMassiv(massiv);
}
