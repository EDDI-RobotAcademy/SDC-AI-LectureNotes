//
// Created by eddi on 23. 11. 30.
//

#include <iostream>
#include <cmath>
#include "Orthogonal.h"



Orthogonal::Orthogonal(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {
    std::cout << "좌표 생성 완료: (" << x << "," << y << "," << z <<")" << std::endl;
}


Orthogonal::Orthogonal(Vector & _vec) : x(_vec.getX()), y(_vec.getY()), z(_vec.getZ()) {
    std::cout << "벡터로부터 좌표 생성 완료: (" << x << "," << y << "," << z << ")" << std::endl;
}

Orthogonal::~Orthogonal() {
    std::cout << "직교 좌표 사라진다~" << std::endl;
}



float Orthogonal::getX() {
    return x;
}
float Orthogonal::getY() {
    return y;
}
float Orthogonal::getZ() {
    return z;
}

