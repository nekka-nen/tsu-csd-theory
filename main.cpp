/* Copyright 2017 Pollonium */
#include "iostream"
#include "sort.h"
#include "basics.h"

int main() {
    int i;
    int length;

    int staticArray[1000];

    std::cin >> length;

    for (i = 0; i < length; i++) {
        std::cin >> staticArray[i];
    }

    int* dynamicArray = new int[length];

    arrayCopy(staticArray, dynamicArray, length);

    for (i = 0; i < length; i++) {
        std::cout << staticArray[i] << ' ';
    }

    std::cout << std::endl;

    sortPlain(staticArray, length);

    for (i = 0; i < length; i++) {
        std::cout << staticArray[i] << ' ';
    }

    std::cout << std::endl;

    sortPlain(dynamicArray, length);

    for (i = 0; i < length; i++) {
        std::cout << dynamicArray[i] << ' ';
    }

    std::cout << std::endl;

    delete dynamicArray;

    return 0;
}
