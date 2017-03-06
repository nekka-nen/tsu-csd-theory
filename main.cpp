/* Copyright 2017 Pollonium */
#include "iostream"
#include "sort.h"
#include "basics.h"

int main() {
    int i = 0;
    int n = 99;

    std::cout << i << ' ' << n << std::endl << "Swapping:" << std::endl;

    swap(&i, &n);

    std::cout << i << ' ' << n << std::endl;

    int X[1000];

    std::cin >> n;

    for (i = 0; i < n; i++) {
        std::cin >> X[i];
    }

    for (i = 0; i < n; i++) {
        std::cout << X[i] << ' ';
    }

    std::cout << std::endl;

    sortPlain(X, n);

    for (i = 0; i < n; i++) {
        std::cout << X[i] << ' ';
    }

    std::cout << std::endl;

    return 0;
}
