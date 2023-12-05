//
// Created by eddi on 23. 12. 1.
//

#include "Coordinate.h"

#include <cmath>

// 그냥 복붙해 => 회전행렬을 사용하려 할

Coordinate::Coordinate(double x, double y, double z) : x(x), y(y), z(z) {}

double Coordinate::rotateX(double angle) {
    return angle;
}

double Coordinate::rotateY(double angle) {
    return angle;
}

double Coordinate::rotateZ(double angle) {
    return angle;
}

Coordinate Coordinate::rotate(double angleX, double angleY, double angleZ) {
    Coordinate rotatedPoint(*this);

    RotationFunction rotationFunctions[] = {rotateX, rotateY, rotateZ};

    double angles[] = {angleX, angleY, angleZ};

    for (int i = 0; i < 3; ++i) {
        double rotatedAngle = rotationFunctions[i](angles[i]);

        double tempX = rotatedPoint.x * cos(rotatedAngle) - rotatedPoint.y * sin(rotatedAngle);
        rotatedPoint.y = rotatedPoint.x * sin(rotatedAngle) + rotatedPoint.y * cos(rotatedAngle);
        rotatedPoint.x = tempX;
    }

    return rotatedPoint;
}