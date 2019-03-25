#include<iostream>
#include"pch.h"
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>

using namespace std;
const string ZERO_DETERMINANT = "Determinant is zero, matrix can't be inversed";
const string WRONG_ARGUMENT = "Wrong argument, please enter file with matrix";
const string FILE_ERROR = "Can't open file";

void readMatrix( float( &mat )[3][3], fstream& input)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			input >> mat[i][j];
		}
	}
}

float calculateDeterminant( float( &mat )[3][3] )
{
	float determinant = 0;
	for (int i = 0; i < 3; i++)
	{
		determinant = determinant + (mat[0][i] * (mat[1][(i + 1) % 3] * mat[2][(i + 2) % 3] - mat[1][(i + 2) % 3] * mat[2][(i + 1) % 3]));
	}
	return determinant;
}

void checkDeterminant( float &determinant)
{
	if (determinant == 0)
	{
		cout << ZERO_DETERMINANT << "\n";
		exit(1);
	}
}

void calculateInverse( float(&mat)[3][3], float &determinant, float(&result)[3][3] )
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			result[i][j] = ((mat[(j + 1) % 3][(i + 1) % 3] * mat[(j + 2) % 3][(i + 2) % 3]) - (mat[(j + 1) % 3][(i + 2) % 3] * mat[(j + 2) % 3][(i + 1) % 3])) / determinant;
		}
	}
}

void printMatrix( float(&matrixToPrint)[3][3] )
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << std::setprecision(3) << matrixToPrint[i][j] << "\t" << std::fixed;
		}
		cout << "\n";
	}
}

int main(int argc, char* argv[]) 
{

	float mat[3][3];
	float result[3][3] = {};
	int i = 0;
	int j = 0;
	float determinant = 0;
	

	if (argc != 2)
	{
		cout << WRONG_ARGUMENT;
		return 1;
	}

	fstream input(argv[1]);

	if(!(input.is_open()))
	{
		cout << FILE_ERROR << endl;
		return 1;
	}

	readMatrix(mat, input);
	determinant = calculateDeterminant(mat);
	checkDeterminant(determinant);
	calculateInverse(mat, determinant, result);
	printMatrix(result);
	return 0;
}
/*
for (j = 0; j < 3; j++)
	cout << std::setprecision(3) << ((mat[(j + 1) % 3][(i + 1) % 3] * mat[(j + 2) % 3][(i + 2) % 3]) - (mat[(j + 1) % 3][(i + 2) % 3] * mat[(j + 2) % 3][(i + 1) % 3])) / determinant << "\t";
std::cout << std::fixed;

cout << "\n";
	}
	*/