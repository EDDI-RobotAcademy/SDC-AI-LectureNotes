//
// Created by eddi on 23. 12. 1.
//

#ifndef FIRST_PROBS_VELOCITY_H
#define FIRST_PROBS_VELOCITY_H

#include <string>

class Velocity {
private:
    double speed;
    double direction;

public:
    Velocity(double speed, double direction);

    std::string getVelocityInfo();

    double getSpeed() const;
    double getDirection() const;
};

#endif //FIRST_PROBS_VELOCITY_H
