//
// Created by eddi on 23. 12. 1.
//

#ifndef FIRST_PROBS_COORDINATE_H
#define FIRST_PROBS_COORDINATE_H

class Coordinate {
public:
    double x;
    double y;
    double z;

    Coordinate(double x, double y, double z);

    using RotationFunction = double (*)(double);
    // new없이 계속 사용 할 수 있때
    static double rotateX(double angle);
    static double rotateY(double angle);
    static double rotateZ(double angle);

    Coordinate rotate(double angleX, double angleY, double angleZ);
};

#endif //FIRST_PROBS_COORDINATE_H
