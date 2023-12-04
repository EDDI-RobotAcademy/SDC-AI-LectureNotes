//
// Created by eddi on 23. 11. 30.
//

#include "Vector.h"
Vector:: Vector()
{}
int Vector::getxVector()
{
    return x;
}
int Vector::getyVector()
{
    return y;
}
int Vector::getzVector()
{
    return z;
}
int Vector::plusxVector()
{
    return x+=5;
}
int Vector::plusyVector()
{
    return y+=5;
}
int Vector::pluszVector()
{
    return z+=5;
}

Vector::~Vector(){}