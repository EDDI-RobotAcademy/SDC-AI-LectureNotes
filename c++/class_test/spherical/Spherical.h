//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_SPHERICAL_H
#define CLASS_TEST_SPHERICAL_H


#include "../orthogonal/Orthogonal.h"

class Spherical {
private:
    float r;
    float theta;
    float phi;
public:
    Spherical(float, float, float);
    Orthogonal getOrthogonalFromSpherical();
    ~Spherical();
};


#endif //CLASS_TEST_SPHERICAL_H
