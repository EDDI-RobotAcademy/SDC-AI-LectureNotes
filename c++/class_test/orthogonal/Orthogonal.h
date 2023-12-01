//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_ORTHOGONAL_H
#define CLASS_TEST_ORTHOGONAL_H

#include "../vector/Vector.h"
#include "../spherical/Spherical.h"

class Orthogonal {
private:
    float x;
    float y;
    float z;
public:
    Orthogonal(float, float, float);
    Orthogonal(Vector&);

    float getX();
    float getY();
    float getZ();

    ~Orthogonal();
};


#endif //CLASS_TEST_ORTHOGONAL_H
