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

double** readMatrix(std::ifstream& source, int matrixSize) {
  double** matrix = init(matrixSize);
  for (int i = 0; i < matrixSize; i++) {
    for (int j = 0; j < matrixSize; j++) {
      source >> matrix[i][j];
    }
  }
  return matrix;
}

double** init(int matrixSize) {
  double** matrix = new double*[matrixSize];
  for (int i = 0; i < matrixSize; i++) {
    matrix[i] = new double[matrixSize];
  }
  return matrix;
}

void swapRows(double** matrix, int first, int second, int length, int startFrom) {
  for (int i = startFrom; i < length; i++) {
    swap(matrix[first][i], matrix[second][i]);
  }
  return;
}

void releaseMemory(double** matrix, int& size) {
  for (int i = 0; i < size; i++) {
    delete [] matrix[i];
  }
  delete [] matrix;
}

double** copyMatrix(double** matrix, int matrixSize) {
  double** copy = new double*[matrixSize];

  for (int i = 0; i < matrixSize; i++) {
    copy[i] = new double[matrixSize];
    for (int j = 0; j < matrixSize; j++) {
      copy[i][j] = matrix[i][j];
    }
  }

  return copy;
}