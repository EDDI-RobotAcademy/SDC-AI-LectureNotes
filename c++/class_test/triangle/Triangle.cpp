//
// Created by eddi on 23. 11. 30.
//

#include "Triangle.h"
#include <cmath>

Triangle::Triangle(float _side1, float _side2, float _side3) :
    side1(_side1), side2(_side2), side3(_side3){

}

Triangle::~Triangle() {

}

float Triangle::getTriangleArea() {
    float s = (side1+side2+side3)/2;
    return std::sqrt(s*(s-side1)*(s-side2)*(s-side3));
}


