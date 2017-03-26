/* Copyright 2017 vankarish */
#include "biky-basic-functions.h"

void swap(int* first, int* second) {
    int swapped = *first;
    *first = *second;
    *second = swapped;
}
