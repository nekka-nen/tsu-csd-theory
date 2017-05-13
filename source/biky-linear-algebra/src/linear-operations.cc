/* Copyright 2017 vankarish */

#include "../linear-operations.h"

int* add(int* first, int* second, int length) {
    int* sum = new int[length];

    for (int i = 0; i < length; i++) {
        sum[i] = first[i] + second[i];
    }

    return sum;
}

int** add(int** first, int** second, int rows, int columns) {
    int** sum = new int*[rows];

    for (int i = 0; i < rows; i++) {
        sum[i] = add(first[i], second[i], columns);
    }

    return sum;
}

int* subtract(int* first, int* second, int length) {
    int* difference = new int[length];

    for (int i = 0; i < length; i++) {
        difference[i] = first[i] - second[i];
    }

    return difference;
}

int** subtract(int** first, int** second, int rows, int columns) {
    int** difference = new int*[rows];

    for (int i = 0; i < rows; i++) {
        difference[i] = subtract(first[i], second[i], columns);
    }

    return difference;
}

int* multiply(int* source, int length, int coefficient) {
    int* product = new int[length];

    for (int i = 0; i < length; i++) {
        product[i] = source[i] * coefficient;
    }

    return product;
}

int** multiply(int** source, int rows, int columns, int coefficient) {
    int** product = new int*[rows];

    for (int i = 0; i < rows; i++) {
        product[i] = multiply(source[i], columns, coefficient);
    }

    return product;
}

double* divide(double* source, int length, double coefficient, int startingFrom) {
  double* quotient = new double[length];

  for (int i = startingFrom; i < length; i++) {
    quotient[i] = source[i] / coefficient;
  }

  return quotient;
}

double* subtract(double* first, double* second, int length, int startingFrom, double coefficient) {
  double* subtraction = new double[length];

  for (int i = startingFrom; i < length; i++) {
    subtraction[i] = first[i] - coefficient * second[i];
  }

  return subtraction;
}