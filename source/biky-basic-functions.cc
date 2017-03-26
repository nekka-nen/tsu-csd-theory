/* Copyright 2017 vankarish */
#include "biky-basic-functions.h"

void swap(int* first, int* second) {
    int swapped = *first;
    *first = *second;
    *second = swapped;
}

int power(int base, unsigned int exponent) {
    int result = 1;
    unsigned int tempExp = exponent;
    int tempBase = base;

    while (tempExp > 0) {
        if (tempExp & 1) {
            tempExp--;
            result *= tempBase;
        }
        tempExp /= 2;
        tempBase *= tempBase;
    }

    return result;
}
