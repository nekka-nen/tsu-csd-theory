/* Copyright 2017 vankarish */

#ifndef SOURCE_BIKY_LINEAR_ALGEBRA_LINEAR_OPERATIONS_H_
#define SOURCE_BIKY_LINEAR_ALGEBRA_LINEAR_OPERATIONS_H_

int* add(int* first, int* second, int length);

int** add(int** first, int** second, int rows, int columns);

int* subtract(int* first, int* second, int length);

int** subtract(int** first, int** second, int rows, int columns);

int* multiply(int* source, int length, int coefficient);

int** multiply(int** source, int rows, int columns, int coefficient);

#endif  // SOURCE_BIKY_LINEAR_ALGEBRA_LINEAR_OPERATIONS_H_
