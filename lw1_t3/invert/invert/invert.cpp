﻿#include<iostream>
#include"pch.h"
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>

const std::string ZERO_DETERMINANT = "Determinant is zero, matrix can't be inversed";
const std::string WRONG_ARGUMENT = "Wrong argument, please enter file with matrix";
const std::string FILE_ERROR = "Can't open file";

void readMatrix( float( &mat )[3][3], std::fstream& input)
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
		std::cout << ZERO_DETERMINANT << "\n";
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
			std::cout << std::setprecision(3) << matrixToPrint[i][j] << "\t" << std::fixed;
		}
		std::cout << "\n";
	}
}

void checkArguments(int argc)
{
	if (argc != 2)
	{
		std::cout << WRONG_ARGUMENT;
		exit(1);
	}
}

void checkFile(std::fstream& input)
{
	if (!(input.is_open()))
	{
		std::cout << FILE_ERROR << "\n";
		exit(1);
	}
}

int main(int argc, char* argv[]) 
{
	float mat[3][3] = {};
	float result[3][3] = {};
	float determinant = 0;	
	checkArguments(argc);
	std::fstream input(argv[1]);
	checkFile(input);
	readMatrix(mat, input);
	determinant = calculateDeterminant(mat);
	checkDeterminant(determinant);
	calculateInverse(mat, determinant, result);
	printMatrix(result);
	return 0;
}
