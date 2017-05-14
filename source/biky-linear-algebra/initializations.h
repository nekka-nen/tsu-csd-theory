/* Copyright 2017 vankarish */

#ifndef initializations_h_
#define initializations_h_

#include "fstream"

const double eps = 0.001;

double** initUnit(int matrixSize);

double** readMatrix(std::ifstream&, int matrixSize);

double** init(int matrixSize);

void swapRows(double** matrix, int first, int second, int length, int startFrom = 0);

void releaseMemory(double** matrix, int& size);

double** copyMatrix(double** matrix, int matrixSize);

#endif  // initializations_h_
