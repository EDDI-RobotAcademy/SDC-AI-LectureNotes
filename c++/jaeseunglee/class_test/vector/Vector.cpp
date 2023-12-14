//
// Created by eddi on 23. 11. 30.
//

#include "Vector.h"
#include <cmath>
#include <iostream>
#include "../utility/Random_generator.h"


Vector::Vector(int _x, int _y, int _z) : x(_x), y(_y), z(_z)
{
    std::cout << "벡터맨~ 벡터맨~!" << std::endl;

}
float Vector::getVectorAmount()
{
    float amount;
    amount = (float)sqrt(pow(x,2) + pow(y,2) + pow(z,2));
    return amount;
}
Vector::~Vector()
{
    std::cout << "벡터 터져욧~~~~" << std::endl;
}

int Vector::getX() {
    return x;
}

int Vector::getY() {
    return y;
}

int Vector::getZ() {
    return z;
}

Vector Vector::vectorSum(Vector & _vectorToSum) {
    int _x = x + _vectorToSum.getX();
    int _y = y + _vectorToSum.getY();
    int _z = z + _vectorToSum.getZ();
    Vector result_vector(_x, _y, _z);
    return result_vector;
}

Vector Vector::vectorScalarProduct(int _amount) {
    int _x = x * _amount;
    int _y = y * _amount;
    int _z = z * _amount;
    Vector result_vector(_x, _y, _z);
    return result_vector;
}

Vector Vector::vectorCrossProduct(Vector & _vectorToProduct) {

    int _x = y*_vectorToProduct.getZ() - z*_vectorToProduct.getY();
    int _y = z*_vectorToProduct.getX() - x*_vectorToProduct.getZ();
    int _z = x*_vectorToProduct.getY() - y*_vectorToProduct.getX();

    Vector result_vector(_x, _y, _z);
    return result_vector;
}


