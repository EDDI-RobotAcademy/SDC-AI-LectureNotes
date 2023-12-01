//
// Created by eddi on 23. 11. 30.
//

#include "Vector.h"
#include <cmath>
#include "../utility/Random_generator.h"


Vector::Vector(int _x, int _y, int _z) : x(_x), y(_y), z(_z)
{


}
float Vector::getVectorAmount()
{
    float amount;
    amount = (float)sqrt(pow(x,2) + pow(y,2) + pow(z,2));
    return amount;
}
Vector::~Vector()
{

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

Vector Vector::vectorSum(Vector & _vector_to_sum) {
    int _x = x + _vector_to_sum.getX();
    int _y = y + _vector_to_sum.getY();
    int _z = z + _vector_to_sum.getZ();
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

Vector Vector::vectorCrossProduct(Vector & _vector_to_product) {
    int _x = y*_vector_to_product.getZ() - z*_vector_to_product.getY();
    int _y = z*_vector_to_product.getX() - x*_vector_to_product.getZ();
    int _z = x*_vector_to_product.getY() - y*_vector_to_product.getX();

    Vector result_vector(_x, _y, _z);
    return result_vector;
}


