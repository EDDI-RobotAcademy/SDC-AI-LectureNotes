//
// Created by eddi on 23. 11. 30.
//

#include "Triangle.h"
#include "../utility/System_changer.h"
#include <cmath>
#include <iostream>

Triangle::Triangle(){
    std::cout << "삼각김밥먹고싶다" << std::endl;
}

Triangle::Triangle(float _side1, float _side2, float _side3) :
    side1(_side1), side2(_side2), side3(_side3){
    std::cout << "SSS로 생성~ 삼각김밥먹고싶다" << std::endl;
}

Triangle::~Triangle() {
    std::cout << "격하게 삼각김밥 너무 먹고싶다!!!!" << std::endl;
}

float Triangle::getTriangleArea() {
    float s = (side1+side2+side3)/2;
    return std::sqrt(s*(s-side1)*(s-side2)*(s-side3));
}

void Triangle::getTriangleFromASA(float _angle2, float _side1, float _angle3) {
    side1 = _side1;
    System_changer changer;
    float _angle1 = 180 - _angle2 - _angle3;
    float angle2 = changer.getRadianFromDegree(_angle2);
    float angle3 = changer.getRadianFromDegree(_angle3);
    float angle1 = changer.getRadianFromDegree(_angle1);
    std::cout << "angle1 " << angle1 << std::endl;
    std::cout << "sin1 " << (float)sin(angle1) << std::endl;
    side2 = side1/sin(angle1) * sin(angle2);
    std::cout << "sin2 " << sin(angle2) << std::endl;
    side3 = side1/sin(angle1) * sin(angle3);
    std::cout << "sin3 " << sin(angle3) << std::endl;


    printTriangleSides();
}



void Triangle::getTriangleFromSAS(float _side1, float _angle3, float _side2) {
    side1 = _side1;
    side2 = _side2;
    System_changer changer;
    float angle3 = changer.getRadianFromDegree(_angle3);
    side3 = sqrt(pow(side1,2)+pow(side2,2) + 2*side1*side2*cos(angle3));
    printTriangleSides();
}

void Triangle::printTriangleSides() {
    std::cout << "삼각형 세 변의 길이: " << side1 << " , "
              << side2 << " , " << side3  << std::endl;
}


