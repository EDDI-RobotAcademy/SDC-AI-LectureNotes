//
// Created by eddi on 23. 12. 1.
//

#ifndef FIRST_PROBS_DISPLACEMENT_H
#define FIRST_PROBS_DISPLACEMENT_H

#include <string>
#include "../velocity/Velocity.h"

class Displacement {
private:
    double distance;
    double direction;

public:
    Displacement(double distance, double direction);

    std::string getDisplacementInfo();

    static Velocity calculateVelocity(const Displacement& initialDisplacement, const Displacement& finalDisplacement, float time);
};

#endif //FIRST_PROBS_DISPLACEMENT_H
