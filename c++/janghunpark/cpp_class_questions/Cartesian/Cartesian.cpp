//
// Created by eddi on 23. 12. 1.
//

#include "Cartesian.h"

#include <iostream>

#include <random>

Cartesian::Cartesian() {}

//void Cartesian::getRandomCartesianCoordinate() {
//    std::random_device rand_device;
//    std::mt19937 mersenneTwister(rand_device());
//    std::uniform_int_distribution<int> distribution(MIN_VALUE, MAX_VALUE);
//
//    xValue = distribution(mersenneTwister);
//    yValue = distribution(mersenneTwister);
//}

void Cartesian::setCartesianCoordinate(float num1, float num2) {
    xValue = num1;
    yValue = num2;
}

//float lengthBetweenTwoPoint(Cartesiancoordinate1, Cartesian *coordinate2) {
//    float tmpX, tmpY, length;
//    tmpX = coordinate1->xValue - coordinate2->xValue;
//    tmpY = coordinate1->yValue - coordinate2->yValue;
//    length = sqrtf(tmpX*tmpX + tmpY*tmpY);
//    return length;
//}

Cartesian::~Cartesian() {}