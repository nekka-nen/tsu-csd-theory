/* Copyright 2017 vankarish */

#include "./13-determinant.h"

#include "iostream"
#include "fstream"
#include "cmath"
#include "string"
#include "./biky-linear-algebra/initializations.h"

void print(double** matrix, int matrixSize) {
  for (int i = 0; i < matrixSize; i++) {
    for (int j = 0; j < matrixSize; j++) {
      std::cout << matrix[i][j] << ' ';
    }
    std::cout << std::endl;
  }
}

double calculateDeterminant(double** originalMatrix, int matrixSize) {
  double** matrix = copyMatrix(originalMatrix, matrixSize);

  int rank = matrixSize;
  int sign = 1;
  double determinant;

  for (int i = 0; i < rank; i++) {
    /*выбор ведущего элемента matrix[leadingRow][i]*/
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
      /*перестановка строк*/
      if (leadingRow != i) {
        sign *= -1;
        swapRows(matrix, i, leadingRow, matrixSize);
      }
      /*вычитание строк матрицы*/
      for (int k = i + 1; k < matrixSize; k++) {
        double c = matrix[k][i] / matrix[i][i];
        for (int j = i; j < matrixSize; j++) {
          matrix[k][j] = matrix[k][j] - c * matrix[i][j];
        }
      }
    }
  }

  determinant = sign;
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
  double determinant;
  double expectedDeterminant;

  for (int testNumber = 1; testNumber <= 5; testNumber++) {
    std::ifstream test(dir + std::to_string(testNumber));

    // initialization
    test >> matrixSize;
    matrix = new double*[matrixSize];
    for (int i = 0; i < matrixSize; i++) {
      matrix[i] = new double[matrixSize];
      for (int j = 0; j < matrixSize; j++) {
        test >> matrix[i][j];
      }
    }

    determinant = calculateDeterminant(matrix, matrixSize);
    test >> expectedDeterminant;

    if (fabs(determinant - expectedDeterminant) < eps) {
      std::cout << "Test " << std::to_string(testNumber) << " passed" << std::endl;
    } else {
      std::cout << "Test " << std::to_string(testNumber) << " failed" << std::endl
                << "Expected: " << expectedDeterminant << std::endl
                << "Calculated: " << determinant << std::endl;
    }

    // cleanup
    releaseMemory(matrix, matrixSize);
    test.close();
  }
}
