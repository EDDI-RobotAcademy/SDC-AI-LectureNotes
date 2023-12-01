//
// Created by eddi on 23. 11. 30.
//

#include "Vector.h"
#include <random>
#include <iostream>

Vector::Vector() {
}
void Vector::VectorRandom() {
    std::random_device rand_device;
    std::mt19937 mersenneTwister(rand_device());
    std::uniform_int_distribution<int> distribution(MIN_NUM, MAX_NUM);
//    std::uniform_int_distribution<int> distribution2(MIN_NUM, MAX_NUM);
//    std::uniform_int_distribution<int> distribution3(MIN_NUM, MAX_NUM);

    x = distribution(mersenneTwister);
    y = distribution(mersenneTwister);
    z = distribution(mersenneTwister);
}
int Vector::getVectorX() {
    return x;
}
int Vector::getVectorY() {
    return y;
}
int Vector::getVectorZ() {
    return z;
}
void Vector::VectorAdd(Vector v1, Vector v2) {
    x = v1.x + v2.x;
    y = v1.y + v2.y;
    z = v1.z + v2.z;
}
void Vector::VectorSub(Vector v1, Vector v2) {
    x = v1.x - v2.x;
    y = v1.y - v2.y;
    z = v1.z - v2.z;
}
