/* Copyright 2017 pollonium */
#include "array.hpp"

bool arrayCopy(int* source, int* copy, int length) {
    if (length > 0) {
        for (int i = 0; i < length; i++) {
            copy[i] = source[i];
        }
        return true;
    }
    return false;
}

bool arraySetToZero(int* array, int length) {
    if (length < 1) {
        return false;
    }
    for (int i = 0; i < length; i++) {
        array[i] = 0;
    }
    return true;
}

bool arrayPrint(int* array, int length) {
    if (length <= 0) {
        return false;
    }
    for (int i = 0; i < length; i++) {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
    return true;
}

bool arrayScan(int* array, int& length) {
    std::cout << "Enter length:" << std::endl;
    std::cin >> length;

    if (length < 1) {
        std::cout << "Array length cannot me less than 1" << std::endl;
        return false;
    }

    std::cout << "Elements: " << std::endl;

    for (int i = 0; i < length; i++) {
        std::cin >> array[i];
    }
    return true;
}

void arrayFillStaticIndexed() {
    int array[ARRAY_LENGTH];

    //arraySetToZero(array, ARRAY_LENGTH);

    for (int i = 0; i < ARRAY_LENGTH; i++) {
        array[i] = i * i;
    }

    arrayPrint(array, ARRAY_LENGTH);

    return;
}

void arrayFillStaticPointed() {
    int array[ARRAY_LENGTH];

    arraySetToZero(array, ARRAY_LENGTH);

    for (int i = 0; i < ARRAY_LENGTH; i++) {
        *(array + i) = i * i;
    }

    arrayPrint(array, ARRAY_LENGTH);

    return;
}

void arrayFillDynamicIndexed() {
    int* array = new int[ARRAY_LENGTH];

    arraySetToZero(array, ARRAY_LENGTH);

    for (int i = 0; i < ARRAY_LENGTH; i++) {
        array[i] = i * i;
    }

    arrayPrint(array, ARRAY_LENGTH);

    delete array;

    return;
}

void arrayFillDynamicPointed() {
    int* array = new int[ARRAY_LENGTH];

    arraySetToZero(array, ARRAY_LENGTH);

    for (int i = 0; i < ARRAY_LENGTH; i++) {
        *(array + i) = i * i;
    }

    arrayPrint(array, ARRAY_LENGTH);

    delete array;

    return;
}
