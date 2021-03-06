/* Copyright 2017 vankarish */
#include "sort.h"
#include "biky-basic-functions.h"

bool sortPlain(int* array, int length) {
    if (length > 0) {
        int i = 0;
        while (i < length - 1) {
            if (array[i] <= array[i + 1]) {
                i++;
            } else {
                swap(&array[i], &array[i + 1]);
                if (i > 0) {
                    i--;
                }
            }
        }
        return true;
    }
    return false;
}
