//
// Created by eddi on 23. 12. 1.
//

#include <cmath>
#include <iostream>
#include "System_changer.h"

System_changer::System_changer() {
    std::cout << "바꿔버려~!" << std::endl;
}

System_changer::~System_changer() {
    std::cout << "메타몽진화~!" << std::endl;
}

Spherical System_changer::getSphericalFromOrthogonal(Orthogonal & _orthogonalToChange) {
    float x = _orthogonalToChange.getX();
    float y = _orthogonalToChange.getY();
    float z = _orthogonalToChange.getZ();
    auto tmp_r = (float)sqrt(pow(x,2)+pow(y,2)+pow(z,2));
    auto tmp_theta = (float)acos((double) z/tmp_r);
    auto tmp_phi = (float)atan((double) y/x);

    auto *spherical = new Spherical(tmp_r, tmp_theta, tmp_phi);

    return *spherical;
}

Orthogonal System_changer::getOrthogonalFromSpherical(Spherical & _sphericalToChange) {
    float r = _sphericalToChange.getR();
    float theta = _sphericalToChange.getTheta();
    float phi = _sphericalToChange.getPhi();

    float _x = r * sin(theta) * cos(phi);
    float _y = r * sin(theta) * sin(phi);
    float _z = r * cos(theta);
    auto *orthogonal = new Orthogonal(_x, _y, _z);
    return *orthogonal;
}

Vector System_changer::getVectorFromOrthogonal(Orthogonal & _orthogonalToChange) {
    float x = _orthogonalToChange.getX();
    float y = _orthogonalToChange.getY();
    float z = _orthogonalToChange.getZ();

    auto *vector = new Vector(x,y,z);

    return *vector;
}

float System_changer::getDegreeFromRadian(float _rad){
    return _rad * 180 / M_PI;
}

float System_changer::getRadianFromDegree(float _degree) {
    return _degree * M_PI / 180;
}
