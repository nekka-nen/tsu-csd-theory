/* Copyright 2017 pollonium */

#ifndef ARRAY_H_
#define ARRAY_H_

#include "iostream"

const int ARRAY_LENGTH = 10;

bool arraySetToZero(int*, int);

bool arrayPrint(int*, int);

bool arrayScan(int*, int&);

void arrayFillStaticIndexed();

void arrayFillStaticPointed();

void arrayFillDynamicIndexed();

void arrayFillDynamicPointed();

#endif  // ARRAY_H_
