//
// Created by eddi on 23. 11. 30.
//

// 4. 벡터 클래스를 만들어 봅시다.

#include <iostream>
#include <random>
#include "4.h"

void Vector::rollVector() {
    std::random_device rand_device;
    std::mt19937 mersenneTwister(rand_device());
    std::uniform_int_distribution<int> distribution(VECTOR_MIN, VECTOR_MAX);

    x = distribution(mersenneTwister);
    y = distribution(mersenneTwister);
    z = distribution(mersenneTwister);
}

Vector::Vector() { }

int Vector::getX()
{
    return x;
}

int Vector::getY()
{
    return y;
}

int Vector::getZ()
{
    return z;
}

void Vector::sumVector(Vector vector1, Vector vector2) {
     x = vector1.x + vector2.x;
     y = vector1.y + vector2.y;
     z = vector1.z + vector2.z;
     std::cout << "\n벡터 덧셈" << std::endl;
     std::cout << "vector1 : " << vector1.x << ", " << vector1.y << ", " << vector1.z << std::endl;
     std::cout << "vector2 : " << vector2.x << ", " << vector2.y << ", " << vector2.z << std::endl;
     std::cout << "result : " << x << ", " << y << ", " << z << std::endl;
}

void Vector::subVector(Vector vector1, Vector vector2) {
    x = vector1.x - vector2.x;
    y = vector1.y - vector2.y;
    z = vector1.z - vector2.z;
    std::cout << "\n벡터 뺄셈" << std::endl;
    std::cout << "vector1 : " << vector1.x << ", " << vector1.y << ", " << vector1.z << std::endl;
    std::cout << "vector2 : " << vector2.x << ", " << vector2.y << ", " << vector2.z << std::endl;
    std::cout << "result : " << x << ", " << y << ", " << z << std::endl;
}

Vector::~Vector() { }