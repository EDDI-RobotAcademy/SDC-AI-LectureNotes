//
// Created by eddi on 23. 11. 30.
//

#include "Displacement.h"
#include <cmath>

Displacement::Displacement(Vector& _start, Vector& _end) : start_vector(_start), end_vector(_end) {
    int x = _end.getX() - _start.getX();
    int y = _end.getY() - _start.getY();
    int z = _end.getZ() - _start.getZ();
    size = (float)sqrt(pow(x,2) + pow(y,2) + pow(z,2));
}

Displacement::~Displacement() {

}
