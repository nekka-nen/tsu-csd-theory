/* Copyright 2017 vankarish */
#include <iostream>
#include "./biky-linear-algebra/initializations.h"

#include "./13-determinant.h"
#include "./13-inverse.h"

int main() {
  std::cout << "Determinants:" << std::endl;

  solveDeterminants();

  std::cout << std::endl << "Inverses:" << std::endl;

  solveInverses();

  return 0;
}
