/* Copyright 2017 vankarish */

#include "../products.h"

int multiplyScalar(int* first, int* second, int length) {
    int product = 0;

    for (int i = 0; i < length; i++) {
        product += first[i] * second[i];
    }

    return product;
}

int* multiplyVectorMatrix(int* vector, int** matrix, int rows, int columns) {
    int* product = new int[columns];

    for (int j = 0; j < columns; j++) {
        product[j] = 0;
        for (int i = 0; i < rows; i++) {
            product[j] += vector[i] * matrix[i][j];
        }
    }

    return product;
}

int* multiplyMatrixVector(int** matrix, int rows, int columns, int* vector) {
    int* product = new int[rows];

    for (int i = 0; i < rows; i++) {
        product[i] = 0;
        for (int j = 0; j < columns; j++) {
            product[i] += vector[j] * matrix[i][j];
        }
    }

    return product;
}

int** multiplyMatrices(int** first, int** second, int rows, int commonDimension, int columns) {
    int** product = new int*[rows];

    for (int i = 0; i < rows; i++) {
        product[i] = new int[columns];
        for (int j = 0; j < columns; j++) {
            product[i][j] = 0;
            for (int k = 0; k < commonDimension; k++) {
                product[i][j] += first[i][k] * second[k][j];
            }
        }
    }
    
    return product;
}
