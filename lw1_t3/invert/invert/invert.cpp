#include<iostream>
#include"pch.h"
#include<iostream>
#include<fstream>
#include <iomanip>
#include <string>

using namespace std;
const string ZERO_DETERMINANT = "Determinant is zero, matrix can't be inversed";
const string WRONG_ARGUMENT = "Wrong argument, please enter file with matrix";


int main(int argc, char* argv[]) 
{
	if (argc != 2)
	{
		cout << ;
		return 1;
	}


	fstream input(argv[1]);

	if(!(input.is_open()))
	{
		cout << "Can't open file." << endl;
		return 1;
	}

	int mat[3][3];
	int i = 0;
	int j = 0;
	float determinant = 0;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			input >> mat[i][j];

	for (i = 0; i < 3; i++)
		determinant = determinant + (mat[0][i] * (mat[1][(i + 1) % 3] * mat[2][(i + 2) % 3] - mat[1][(i + 2) % 3] * mat[2][(i + 1) % 3]));

	//cout << "\n\nDeterminant: " << determinant<< endl;

	if (determinant == 0)
	{
		cout << ZERO_DETERMINANT << "\n";
		return 1;
	}

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++)
			cout << std::setprecision(3) << ((mat[(j + 1) % 3][(i + 1) % 3] * mat[(j + 2) % 3][(i + 2) % 3]) - (mat[(j + 1) % 3][(i + 2) % 3] * mat[(j + 2) % 3][(i + 1) % 3])) / determinant << "\t";
		std::cout << std::fixed;

		cout << "\n";
	}

	return 0;
}