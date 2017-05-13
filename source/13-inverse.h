/* Copyright 2017 vankarish */

#ifndef inverse_h_
#define inverse_h_

#include "string"

double** copyMatrix(double** matrix, int matrixSize);

bool equal(std::string dir, int testNumber, double** matrix, int matrixSize);

double** getInverse(double** matrix, double** inverse, int matrixSize);

void solveInverses();

#endif  // inverse_h_
