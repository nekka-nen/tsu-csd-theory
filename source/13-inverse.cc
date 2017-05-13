/* Copyright 2017 vankarish */

#include "13-inverse.h"

#include "iostream"
#include "fstream"
#include "cmath"
#include "./biky-linear-algebra/initializations.h"
#include "./biky-linear-algebra/linear-operations.h"
#include "./13-determinant.h"

bool isInvertedCorrectly(double** matrix, double** inverted, double** E, int n)
{
  double** multiplication = new double*[n];
  for (int i = 0; i < n; i++)
  {
    multiplication[i] = new double[n];
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      multiplication[i][j] = 0;
      for (int k = 0; k < n; k++)
      {
        multiplication[i][j] += matrix[i][k] * inverted[k][j];
      }

    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (fabs(multiplication[i][j] - E[i][j]) >= eps)
        return false;
    }
  }

  return true;
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

double** getInverse(double** matrix, double** inverse, int matrixSize) {
  // ...calculating inverse
  int rank = matrixSize;

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
  return inverse;
}

void solveInverses() {
  std::string testDir = ".\\..\\tests\\inverses\\";
  std::string answerDir = testDir + "answers\\";

  int matrixSize;
  double** matrix;
  double** inverse;
  double** copy;
  double** E;

  E = initUnit(matrixSize);

  for (int testNumber = 1; testNumber <= 4; testNumber++) {
    std::ifstream test(testDir + std::to_string(testNumber));

    // initialization
    test >> matrixSize;
    matrix = new double*[matrixSize];

    for (int i = 0; i < matrixSize; i++) {
      matrix[i] = new double[matrixSize];
      for (int j = 0; j < matrixSize; j++) {
        test >> matrix[i][j];
      }
    }

    copy = copyMatrix(matrix, matrixSize);
    double determinant = calculateDeterminant(copy, matrixSize);
    copy = copyMatrix(matrix, matrixSize);
    bool isDegenerate = !(bool)determinant;

    inverse = initUnit(matrixSize);
    inverse = getInverse(matrix, inverse, matrixSize);

    std::ifstream degenerateChecking(answerDir + std::to_string(testNumber));
    std::string buffer;
    bool expectedDegenerate = false;
    degenerateChecking >> buffer;

    if (buffer == "вырождена") {
      expectedDegenerate = true;
    }

    // checking
    if ((!isDegenerate && equal(answerDir, testNumber, inverse, matrixSize) && isInvertedCorrectly(copy, inverse, E, matrixSize)) || (expectedDegenerate && isDegenerate)) {
      std::cout << "Test " << std::to_string(testNumber) << " passed" << std::endl;
    } else {
      std::cout << "Test " << std::to_string(testNumber) << " failed" << std::endl;
    }

    // cleanup
    for (int j = 0; j < matrixSize; j++) {
      delete [] matrix[j];
      delete [] copy[j];
    }

    delete [] matrix;
    delete [] copy;

    if (!isDegenerate) {
      for (int j = 0; j < matrixSize; j++) {
        delete [] inverse[j];
      }
      delete [] inverse;
    }

    test.close();
  }
}