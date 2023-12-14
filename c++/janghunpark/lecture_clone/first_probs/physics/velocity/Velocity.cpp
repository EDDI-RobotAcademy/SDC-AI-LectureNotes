//
// Created by eddi on 23. 12. 1.
//

#include "Velocity.h"
#include <iostream>

Velocity::Velocity(double speed, double direction) : speed(speed), direction(direction) {}

std::string Velocity::getVelocityInfo() {
    return "속도: " + std::to_string(speed) + " m/s, 방향: " + std::to_string(direction) + " 도";
}

double Velocity::getSpeed() const {
    return speed;
}

double Velocity::getDirection() const {
    return direction;
}
