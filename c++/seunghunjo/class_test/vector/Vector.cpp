//
// Created by eddi on 23. 11. 30.
//

#include <random>
#include "Vector.h"


Vector::Vector() { }

int Vector::randomOperation() {
    std::random_device rand_vector;
    std::mt19937 mersenneTwister(rand_vector());
    std::uniform_int_distribution<int> distribution(VECTOR_MIN, VECTOR_MAX);

    int number = distribution(mersenneTwister);

    return  number;
}

void Vector::vectorRandomResponse() {
    x = randomOperation();
    y = randomOperation();
    z = randomOperation();
}

void Vector::vectorAdd(Vector vector1, Vector vector2)
{
    x = vector1.x + vector2.x;
    y = vector1.y + vector2.y;
    z = vector1.z + vector2.z;
}

void Vector::vectorSub(Vector vector1, Vector vector2)
{
    x = vector1.x - vector2.x;
    y = vector1.y - vector2.y;
    z = vector1.z - vector2.z;
}

Vector::~Vector() { }