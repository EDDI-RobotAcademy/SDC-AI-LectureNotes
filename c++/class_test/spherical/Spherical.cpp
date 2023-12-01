//
// Created by eddi on 23. 11. 30.
//

#include <iostream>
#include <cmath>
#include "Spherical.h"


Spherical::Spherical(float _r, float _theta, float _phi) : r(_r), theta(_theta), phi(_phi) {
    std::cout << "구면 좌표 생성 완료: (" << r << "," << theta << "," << phi <<")" << std::endl;
}

Spherical::~Spherical() {
    std::cout << "구면 좌표 사라진다~" << std::endl;
}

float Spherical::getR() {
    return r;
}

float Spherical::getTheta() {
    return theta;
}

float Spherical::getPhi() {
    return phi;
}
