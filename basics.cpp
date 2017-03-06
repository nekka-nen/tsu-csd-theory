/* Copyright 2017 Pollonium */
#include "basics.h"

void swap(int* first, int* second) {
    int swapped = *first;
    *first = *second;
    *second = swapped;
}
