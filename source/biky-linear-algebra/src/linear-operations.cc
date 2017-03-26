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

int scalarProduct(int* first, int* second, int length) {
    int product = 0;

    for (int i = 0; i < length; i++) {
        product += first[i] * second[i];
    }

    return product;
}
