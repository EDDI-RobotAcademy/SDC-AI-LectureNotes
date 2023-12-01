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

int Vector::vectorSum(const Vector& other)
{
    int vectorSumX = vectorX + other.vectorX;
    int vectorSumY = vectorY + other.vectorY;
    int vectorSumZ = vectorZ + other.vectorZ;

    std::cout << "vectorX 의 합: " << vectorSumX/* + other.vectorX */<< "\n" <<
    "vectorY 의 합: " << vectorSumY/* + other.vectorY */<< "\n" <<
    "vectorZ 의 합: " << vectorSumZ/* + other.vectorZ */<< "\n" << std::endl;

    return 0;
}

int Vector::vectorCrossProduct(const Vector& other) const
{
    int vectorCrossX = (vectorY * other.vectorZ) - (vectorZ * other.vectorY);
    int vectorCrossY = (vectorZ * other.vectorX) - (vectorX * other.vectorZ);
    int vectorCrossZ = (vectorX * other.vectorY) - (vectorY * other.vectorX);
    std::cout << "vectorCrossX: " << vectorCrossX<< "\n" <<
              "vectorCrossY: " << vectorCrossY << "\n" <<
              "vectorCrossZ: " << vectorCrossZ << "\n" << std::endl;

    return 0;
}

int Vector::vectorScalarProduct(const Vector&, int amount)
{
    int vectorScalarX = vectorX * amount;
    int vectorScalarY = vectorY * amount;
    int vectorScalarZ = vectorZ * amount;
    std::cout << "vectorScalar" << getVectorName() << "X: " << vectorScalarX << "\n" <<
                 "vectorScalar" << getVectorName() << "Y: " << vectorScalarY << "\n" <<
                 "vectorScalar" << getVectorName() << "Z: " << vectorScalarZ << "\n" << std::endl;
    return 0;
}

Vector::~Vector()
{
    std::cout << "vector 소멸자" << std::endl;
}

