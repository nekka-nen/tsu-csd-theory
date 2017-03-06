/* Copyright 2017 Pollonium */
#include "basics.h"

void swap(int* first, int* second) {
    int swapped = *first;
    *first = *second;
    *second = swapped;
}

bool arrayCopy(int* source, int* copy, int length) {
    if (length > 0) {
        for (int i = 0; i < length; i++) {
            copy[i] = source[i];
        }
        return true;
    }
    return false;
}
