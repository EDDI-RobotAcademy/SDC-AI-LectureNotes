//
// Created by eddi on 23. 12. 1.
//

#include "Vector.h"
#include "../utility/RandomGenerator.h"

Vector::Vector(float x, float y, float z) : x(x), y(y), z(z) { }

float Vector::getX()
{
    return x;
}

float Vector::getY()
{
    return y;
}

float Vector::getZ()
{
    return z;
}

Vector Vector::operator+(const Vector& other) const
{
    return Vector(x + other.x, y + other.y, z + other.z);
}

Vector Vector::operator-(const Vector& other)
{
    return Vector(x - other.x, y - other.y, z - other.z);
}

std::ostream& operator<<(std::ostream& os, const Vector& vec)
{
    os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
    return os;
}

Vector::~Vector() { }