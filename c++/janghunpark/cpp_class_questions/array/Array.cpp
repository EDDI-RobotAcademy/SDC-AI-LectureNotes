//
// Created by eddi on 23. 11. 30.
//

#include "Array.h"

#include <iostream>

#include <random>

Array::Array() {}

void Array::getRandomArray(){
    std::cout << "This is Random Array!" << std::endl;
    std::random_device rand_device;
    std::mt19937 mersenneTwister(rand_device());
    std::uniform_int_distribution<int> distribution(MIN_VALUE, MAX_VALUE);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            arr[i][j] = distribution(mersenneTwister);
        }
    }
}

int Array::getArrayValue(int a, int b, Array *test_array) {
    return test_array->arr[a][b];
}

Array::~Array() {}