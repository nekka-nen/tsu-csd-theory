/* Copyright 2017 vankarish */

#ifndef initializations_h_
#define initializations_h_

const double eps = 0.001;

double** initUnit(int matrixSize);

void swapRows(double** matrix, int first, int second, int length, int startFrom = 0);

#endif  // initializations_h_
