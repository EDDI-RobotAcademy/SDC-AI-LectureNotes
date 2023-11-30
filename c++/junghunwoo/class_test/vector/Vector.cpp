#include "Vector.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

#include <random>

Vector() { }
void Vector::randomx(){
    std::random_device rand_device;
    std::mt19937 mersenneTwister(rand_device());
    std::uniform_int_distribution<int> distribution(VECTOR_MIN, VECTOR_MAX);

    x = distribution(mersenneTwister);
}

void Vector::randomy(){
    std::random_device rand_device;
    std::mt19937 mersenneTwister(rand_device());
    std::uniform_int_distribution<int> distribution(VECTOR_MIN, VECTOR_MAX);

    y = distribution(mersenneTwister);
}

void Vector::randomz(){
    std::random_device rand_device;
    std::mt19937 mersenneTwister(rand_device());
    std::uniform_int_distribution<int> distribution(VECTOR_MIN, VECTOR_MAX);

    z = distribution(mersenneTwister);
}

int Vector::getvector(int, int, int);
~Vector() { }