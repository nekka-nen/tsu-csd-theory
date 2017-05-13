/* Copyright 2017 vankarish */

#include "../initializations.h"

#include "./../../biky-basic-functions.h"

double** initUnit(int matrixSize) {
  double** inverse = new double*[matrixSize];

  for (int i = 0; i < matrixSize; i++) {
    inverse[i] = new double[matrixSize];
    for (int j = 0; j < matrixSize; j++) {
      if (i == j) {
        inverse[i][j] = 1;
      } else {
        inverse[i][j] = 0;
      }
    }
  }

  return inverse;
}

void swapRows(double** matrix, int first, int second, int length, int startFrom) {
  for (int i = startFrom; i < length; i++) {
    swap(matrix[first][i], matrix[second][i]);
  }
  return;
}