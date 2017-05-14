/* Copyright 2017 vankarish */

#include "13-inverse.h"

#include "iostream"
#include "fstream"
#include "cmath"
#include "./biky-linear-algebra/initializations.h"
#include "./biky-linear-algebra/linear-operations.h"
#include "./13-determinant.h"


bool isInvertedCorrectly(double** originalMatrix, double** inverted, int n) {
  double** unitMatrix = initUnit(n);
  double** matrix = copyMatrix(originalMatrix, n);
  double** multiplication = new double*[n];
  for (int i = 0; i < n; i++) {
    multiplication[i] = new double[n];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      multiplication[i][j] = 0;
      for (int k = 0; k < n; k++) {
        multiplication[i][j] += matrix[i][k] * inverted[k][j];
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (fabs(multiplication[i][j] - unitMatrix[i][j]) >= eps) {
        releaseMemory(unitMatrix, n);
        releaseMemory(matrix, n);
        return false;
      }
    }
  }

  releaseMemory(matrix, n);
  releaseMemory(unitMatrix, n);
  return true;
}

bool equal(std::string dir, int testNumber, double** matrix, int matrixSize) {
  std::ifstream test(dir + std::to_string(testNumber));
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

double** getInverse(double** originalMatrix, int matrixSize) {
  // ...calculating inverse
  int rank = matrixSize;
  double** inverse = initUnit(matrixSize);
  double** matrix = copyMatrix(originalMatrix, matrixSize);

  for (int i = 0; i < rank; i++) {
    /*выбор ведущего элемента matrix[leadingRow,i]*/
    int leadingRow = i;
    for (int j = i + 1; j < matrixSize; j++) {
      if (fabs(matrix[j][i]) > fabs(matrix[leadingRow][i])) {
        leadingRow = j;
      }
    }
    if (fabs(matrix[leadingRow][i]) < eps) {
      rank = i - 1;
    } else {
      /*перестановка строк*/
      if (leadingRow != i) {
        swapRows(matrix, i, leadingRow, matrixSize, i);
        swapRows(inverse, i, leadingRow, matrixSize);
      }

      /*деление i-й строки на matrix[i][i]*/
      double coefficient = matrix[i][i];
      matrix[i] = divide(matrix[i], matrixSize, coefficient, i);
      inverse[i] = divide(inverse[i], matrixSize, coefficient);

      /*вычитание уравнений*/
      for (int j = 0; j < matrixSize; j++) {
        if (j != i) {
          coefficient = matrix[j][i];
          matrix[j] = subtract(matrix[j], matrix[i], matrixSize, i, coefficient);
          inverse[j] = subtract(inverse[j], inverse[i], matrixSize, 0, coefficient);
        }
      }
    }
  }
  releaseMemory(matrix, matrixSize);
  return inverse;
}

void solveInverses() {
  std::string testDir = ".\\..\\tests\\inverses\\";
  std::string answerDir = testDir + "answers\\";
  std::ifstream test;
  int matrixSize;
  double** matrix;
  double** inverse;
  bool isInvertible;
  bool testPassed;

  for (int testNumber = 1; testNumber <= 4; testNumber++) {
    test.open(testDir + std::to_string(testNumber));
    test >> matrixSize;
    matrix = readMatrix(test, matrixSize);
    test.close();
    isInvertible = (bool)calculateDeterminant(matrix, matrixSize);

    if (isInvertible) {
      inverse = getInverse(matrix, matrixSize);
      testPassed = equal(answerDir, testNumber, inverse, matrixSize) && isInvertedCorrectly(matrix, inverse, matrixSize);
      releaseMemory(inverse, matrixSize);
    } else {
      test.open(answerDir + std::to_string(testNumber));
      std::string buffer;
      test >> buffer;
      testPassed = buffer == "вырождена";
      test.close();
    }

    std::cout << "Test " << std::to_string(testNumber);
    testPassed ? std::cout << " passed" : std::cout << " failed";
    std::cout << std::endl;

    releaseMemory(matrix, matrixSize);
  }
}
