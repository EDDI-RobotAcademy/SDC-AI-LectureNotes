//
// Created by eddi on 23. 11. 30.
//
#include <iostream>
#include <random>
#include "Vector.h"

Vector::Vector() {}

void Vector::getRandomValue() {
    std::random_device rand_device;
    std::mt19937 mersenneTwister(rand_device());
    std::uniform_int_distribution<int> distribution(MIN_VALUE, MAX_VALUE);

    x = distribution(mersenneTwister);
    y = distribution(mersenneTwister);
    z = distribution(mersenneTwister);
}

int Vector::getVectorXValue() {
    return x;
}

int Vector::getVectorYValue() {
    return y;
}

int Vector::getVectorZValue() {
    return z;
}

Vector *Vector::addVector(Vector *final, Vector *a, Vector *b) {
    final->x = a->x + b->x;
    final->y = a->y + b->y;
    final->z = a->z + b->z;

    return final;
}

//Vector *getAngleBtwTwoVectors(Vector *a, Vector *b) {
//
//}

Vector::~Vector() {}