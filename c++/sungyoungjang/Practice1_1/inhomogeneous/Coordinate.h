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
    // using = typedef
    using RotationFunction = double (*)(double);
    // static 을 사용하면 new 없이 사용 가다
    static double rotateX(double angle);
    static double rotateY(double angle);
    static double rotateZ(double angle);

    Coordinate rotate(double angleX, double angleY, double angleZ);
};

#endif //FIRST_PROBS_COORDINATE_H
