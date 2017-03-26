/* Copyright 2017 vankarish */

#ifndef SOURCE_BIKY_LINEAR_ALGEBRA_PRODUCTS_H_
#define SOURCE_BIKY_LINEAR_ALGEBRA_PRODUCTS_H_

int multiplyScalar(int* first, int* second, int length);

int* multiplyVectorMatrix(int* vector, int** matrix, int rows, int columns);

int* multiplyMatrixVector(int** matrix, int rows, int columns, int* vector);

int** multiplyMatrices(int** first, int** second, int rows, int commonDimension, int columns);

#endif  // SOURCE_BIKY_LINEAR_ALGEBRA_PRODUCTS_H_
