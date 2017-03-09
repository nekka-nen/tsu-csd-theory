/* Copyright 2017 Pollonium */
#include "iostream"
#include "sort.hpp"
#include "basics.hpp"
#include "array.hpp"

int main() {
    const int LENGTH = 1000;
    int length;

    int staticArray[LENGTH];
    int staticArrayCopy[LENGTH];

    arraySetToZero(staticArray, LENGTH);
    arrayCopy(staticArray, staticArrayCopy, LENGTH);

    arrayScan(staticArray, length);

    arrayPrint(staticArray, length);

    sortMerge(0, length, staticArray, staticArrayCopy);

    arrayPrint(staticArray, length);

    return 0;
}
