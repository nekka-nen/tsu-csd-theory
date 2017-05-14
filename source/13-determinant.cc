/* Copyright 2017 vankarish */

#include "./13-determinant.h"

#include "iostream"
#include "fstream"
#include "cmath"
#include "string"
#include "./biky-linear-algebra/initializations.h"
#include "./biky-linear-algebra/linear-operations.h"

double calculateDeterminant(double** originalMatrix, int matrixSize) {
  double** matrix = copyMatrix(originalMatrix, matrixSize);
  int sign = 1;

  for (int i = 0; i < matrixSize; i++) {
    int leadingRow = i;
    for (int j = i + 1; j < matrixSize; j++) {
      if (fabs(matrix[j][i]) > fabs(matrix[leadingRow][i])) {
        leadingRow = j;
      }
    }

    if (fabs(matrix[leadingRow][i]) < eps) {
      releaseMemory(matrix, matrixSize);
      return 0;
    } else {
      if (leadingRow != i) {
        sign *= -1;
        swapRows(matrix, i, leadingRow, matrixSize);
      }
      for (int k = i + 1; k < matrixSize; k++) {
        matrix[k] = subtract(matrix[k], matrix[i], matrixSize, i, matrix[k][i] / matrix[i][i]);
      }
    }
  }

  double determinant = sign;
  for (int i = 0; i < matrixSize; i++) {
    determinant *= matrix[i][i];
  }
  releaseMemory(matrix, matrixSize);
  return determinant;
}

void solveDeterminants() {
  std::string dir = ".\\..\\tests\\determinants\\";
  int matrixSize;
  double** matrix;
  double expectedDeterminant;

  for (int testNumber = 1; testNumber <= 5; testNumber++) {
    std::ifstream test(dir + std::to_string(testNumber));
    test >> matrixSize;
    matrix = readMatrix(test, matrixSize);
    test >> expectedDeterminant;
    test.close();

    std::cout << "Test " << std::to_string(testNumber);
    fabs(calculateDeterminant(matrix, matrixSize) - expectedDeterminant) < eps ? std::cout << " passed" : std::cout << " failed";
    std::cout << std::endl;
    releaseMemory(matrix, matrixSize);
  }
}
