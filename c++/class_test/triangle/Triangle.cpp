//
// Created by eddi on 23. 11. 30.
//

#include "Triangle.h"
#include <cmath>
#include <iostream>

Triangle::Triangle(float _side1, float _side2, float _side3) :
    side1(_side1), side2(_side2), side3(_side3){
    std::cout << "삼각김밥먹고싶다" << std::endl;
}

Triangle::~Triangle() {
    std::cout << "격하게 삼각김밥 너무 먹고싶다!!!!" << std::endl;
}

float Triangle::getTriangleArea() {
    float s = (side1+side2+side3)/2;
    return std::sqrt(s*(s-side1)*(s-side2)*(s-side3));
}


