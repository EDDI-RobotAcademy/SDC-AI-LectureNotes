//
// Created by eddi on 23. 12. 1.
//

#include "Displacement.h"
#include <iostream>

Displacement::Displacement(double distance, double direction) : distance(distance), direction(direction) {}

std::string Displacement::getDisplacementInfo() {
    return "변위: " + std::to_string(distance) + " m, 방향: " + std::to_string(direction) + " 도";
}

Velocity Displacement::calculateVelocity(const Displacement& initialDisplacement, const Displacement& finalDisplacement, float time) {
    // 초기 변위와 최종 변위의 차이를 이용하여 미분을 통한 속도 계산
    float velocity = (finalDisplacement.distance - initialDisplacement.distance) / time;

    return Velocity(velocity, finalDisplacement.direction);
}
