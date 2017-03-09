/* Copyright 2017 Pollonium */
#include "basics.hpp"

void swap(int* first, int* second) {
    int swapped = *first;
    *first = *second;
    *second = swapped;
}
