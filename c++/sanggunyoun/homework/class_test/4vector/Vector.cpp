//
// Created by eddi on 23. 12. 1.
//

#include <iostream>
#include <random>
#include "Vector.h"

Vector::Vector() {
    std::cout << "백크터!" << std::endl;
}

void Vector::rollVector() {
    std::random_device rand_vector;
    std::mt19937 mersenneTwister(rand_vector());
    std::uniform_int_distribution<int> distribution(VECTOR_MIN, VECTOR_MAX);

    x = distribution(mersenneTwister);
    y = distribution(mersenneTwister);
    z = distribution(mersenneTwister);
}

    int Vector::getVectorX(){
    return  x;
    }
    int Vector::getVectorY(){
    return  y;
    }
    int Vector::getVectorZ(){
    return  z;
    }

    void Vector::addVector(Vector v1, Vector v2) {
    x = v1.x + v2.x;
    y = v1.y + v2.y;
    z = v1.z + v2.z;
    }
void Vector::subVector(Vector v1, Vector v2) {
    x = v1.x - v2.x;
    y = v1.y - v2.y;
    z = v1.z - v2.z;
    }



//Vector::~Vec// tor() {
//    std::cout << "백터 끝! " << std::endl;
//