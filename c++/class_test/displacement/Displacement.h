//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_DISPLACEMENT_H
#define CLASS_TEST_DISPLACEMENT_H

#include "../vector/Vector.h"

class Displacement {
private:
    Vector start_vector;
    Vector end_vector;
public:
    Displacement(Vector& _start, Vector& _end);
    float getSizeofDisplacement();
    ~Displacement();
};


#endif //CLASS_TEST_DISPLACEMENT_H
