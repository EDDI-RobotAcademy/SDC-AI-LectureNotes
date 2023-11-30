//
// Created by eddi on 23. 11. 30.
//

#include "Vector.h"
#include <random>
#include <iostream>

Vector::Vector() : x(0),y(0),z(0) {
    std::cout<< "벡터 시작\n"<< std::endl;
}
void Vector::VectorRandom() {
    std::random_device rand_device;
    std::mt19937 mersenneTwister(rand_device());
    std::uniform_int_distribution<int> distribution(MIN_NUM, MAX_NUM);
    std::uniform_int_distribution<int> distribution2(MIN_NUM, MAX_NUM);
    std::uniform_int_distribution<int> distribution3(MIN_NUM, MAX_NUM);

    x = distribution(mersenneTwister);
    y = distribution(mersenneTwister);
    z = distribution(mersenneTwister);
}


Vector::Vector(int x, int y, int z) : x(x), y(y), z(z){ }

Vector Vector::VectorAdd(const Vector &v1, const Vector &v2) {
    return Vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}
Vector Vector::VectorSub(const Vector &v1, const Vector &v2) {
    return Vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

Vector::~Vector() {
    std::cout<< "벡터 끝\n" << std::endl;
}