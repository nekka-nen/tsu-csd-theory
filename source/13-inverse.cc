/* Copyright 2017 vankarish */

#include "13-inverse.h"

#include "iostream"
#include "fstream"
#include "cmath"
#include "./biky-linear-algebra/initializations.h"
#include "./biky-linear-algebra/linear-operations.h"
#include "./biky-linear-algebra/products.h"

bool isInvertedCorrectly(double** matrix, double** inverted, int matrixSize) {
  double** unitMatrix = initUnit(matrixSize);
  double** product = multiplyMatrices(matrix, inverted, matrixSize, matrixSize, matrixSize);

  for (int i = 0; i < matrixSize; i++) {
    for (int j = 0; j < matrixSize; j++) {
      if (fabs(product[i][j] - unitMatrix[i][j]) >= eps) {
        releaseMemory(product, matrixSize);
        releaseMemory(unitMatrix, matrixSize);
        return false;
      }
    }
  }

  releaseMemory(product, matrixSize);
  releaseMemory(unitMatrix, matrixSize);
  return true;
}

double** getInverse(double** originalMatrix, int matrixSize) {
  double** inverse = initUnit(matrixSize);
  double** matrix = copyMatrix(originalMatrix, matrixSize);
  int leadingRow;

  for (int i = 0; i < matrixSize; i++) {
    /*выбор ведущего элемента matrix[leadingRow][i]*/
    leadingRow = i;
    for (int j = i + 1; j < matrixSize; j++) {
      if (fabs(matrix[j][i]) > fabs(matrix[leadingRow][i])) {
        leadingRow = j;
      }
    }

    if (fabs(matrix[leadingRow][i]) < eps) {
      releaseMemory(matrix, matrixSize);
      releaseMemory(inverse, matrixSize);
      return nullptr;
    } else {
      if (leadingRow != i) {
        swapRows(matrix, i, leadingRow, matrixSize, i);
        swapRows(inverse, i, leadingRow, matrixSize);
      }
      inverse[i] = divide(inverse[i], matrix[i][i], matrixSize);
      matrix[i] = divide(matrix[i], matrix[i][i], matrixSize, i);

      for (int j = 0; j < matrixSize; j++) {
        if (j != i) {
          inverse[j] = subtract(inverse[j], inverse[i], matrixSize, 0, matrix[j][i]);
          matrix[j] = subtract(matrix[j], matrix[i], matrixSize, i, matrix[j][i]);
        }
      }
    }
  }
  releaseMemory(matrix, matrixSize);
  return inverse;
}

bool equal(std::ifstream& test, double** matrix, int matrixSize) {
  double expectedValue;

  for (int i = 0; i < matrixSize; i++) {
    for (int j = 0; j < matrixSize; j++) {
      test >> expectedValue;
      if (fabs(matrix[i][j] - expectedValue) >= eps) {
        test.close();
        return false;
      }
    }
  }

  test.close();
  return true;
}

void solveInverses() {
  std::string testDir = ".\\..\\tests\\inverses\\";
  std::string answerDir = testDir + "answers\\";
  std::ifstream test;
  int matrixSize;
  double** matrix;
  double** inverse;
  bool testPassed;

  for (int testNumber = 1; testNumber <= 4; testNumber++) {
    test.open(testDir + std::to_string(testNumber));
    test >> matrixSize;
    matrix = readMatrix(test, matrixSize);
    test.close();

    inverse = getInverse(matrix, matrixSize);
    test.open(answerDir + std::to_string(testNumber));
    if (inverse != nullptr) {
      testPassed = equal(test, inverse, matrixSize) && isInvertedCorrectly(matrix, inverse, matrixSize);
      releaseMemory(inverse, matrixSize);
    } else {
      std::string buffer;
      test >> buffer;
      testPassed = buffer == "вырождена";
    }
    test.close();

    std::cout << "Test " << std::to_string(testNumber);
    testPassed ? std::cout << " passed" : std::cout << " failed";
    std::cout << std::endl;
    releaseMemory(matrix, matrixSize);
  }
}
