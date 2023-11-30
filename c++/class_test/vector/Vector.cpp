//
// Created by eddi on 23. 11. 30.
//

#include "Vector.h"
#include <cmath>


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
