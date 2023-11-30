//
// Created by eddi on 23. 11. 30.
//

#include <iostream>
#include <random>
#include "Vector.h"

Vector::Vector(std::string& vectorName, int vectorX, int vectorY, int vectorZ)
: vectorName(vectorName), vectorX(vectorX), vectorY(vectorY), vectorZ(vectorZ)
{
    std::cout << "vector 생성자" << std::endl;
}

std::string Vector::getVectorName() // std::string = char *
{
    return vectorName;
}

void Vector::randomVectorValue()
{
    std::random_device rand_vector;
    std::mt19937 mt(rand_vector());
    std::uniform_int_distribution<int> distributionX(VECTOR_MIN, VECTOR_MAX);
    std::uniform_int_distribution<int> distributionY(VECTOR_MIN, VECTOR_MAX);
    std::uniform_int_distribution<int> distributionZ(VECTOR_MIN, VECTOR_MAX);
    vectorX = distributionX(mt);
    vectorY = distributionY(mt);
    vectorZ = distributionZ(mt);
}

int Vector::getVectorX()
{
    return vectorX;
}

int Vector::getVectorY()
{
    return vectorY;
}

int Vector::getVectorZ()
{
    return vectorZ;
}

Vector::~Vector()
{
    std::cout << "vector 소멸자" << std::endl;
}
