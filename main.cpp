/* Copyright 2017 Pollonium */
#include <iostream>

int main() {
    int i;
    int n;
    int z;
    int X[1000];

    std::cin >> n;

    for (i = 0; i < n; i++) {
        std::cin >> X[i];
    }

    i = 0;

    while (i < n - 1) {
        if (X[i] <= X[i + 1]) {
            i++;
        } else {
            z = X[i];
            X[i] = X[i + 1];
            X[i + 1] = z;
            if (i > 0) {
                i--;
            }
        }
    }

    for (i = 0; i < n; i++) {
        std::cout << X[i] << ' ';
    }

    std::cout << std::endl;

    return 0;
}
