//
// Created by eddi on 23. 11. 30.
//

#include "Displacement.h"
#include <cmath>
#include <iostream>

Displacement::Displacement(Vector& _start, Vector& _end) : start_vector(_start), end_vector(_end) {
    std::cout << "변위 생겨욧~" << std::endl;
}

Displacement::~Displacement() {
    std::cout << "변위 터져욧~" << std::endl;
}

float Displacement::getSizeofDisplacement() {
    int x = end_vector.getX() - start_vector.getX();
    int y = end_vector.getY() - start_vector.getY();
    int z = end_vector.getZ() - start_vector.getZ();
    float size;
    size = (float)sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    return size;
}
