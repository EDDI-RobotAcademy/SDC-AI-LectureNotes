//
// Created by eddi on 23. 12. 1.
//

#ifndef CLASS_TEST_SYSTEM_CHANGER_H
#define CLASS_TEST_SYSTEM_CHANGER_H

#include "../orthogonal/Orthogonal.h"
#include "../spherical/Spherical.h"
#include "../vector/Vector.h"

class System_changer {
public:
    System_changer();
    Spherical getSphericalFromOrthogonal(Orthogonal&);
    Orthogonal getOrthogonalFromSpherical(Spherical&);
    Vector getVectorFromOrthogonal(Orthogonal&);
    float getDegreeFromRadian(float _rad);
    float getRadianFromDegree(float _degree);
    ~System_changer();
};


#endif //CLASS_TEST_SYSTEM_CHANGER_H
