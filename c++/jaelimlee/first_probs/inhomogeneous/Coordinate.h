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

    //using = typedef라고 생각하면 됨.
    using RotationFunction = double (*)(double);

    // x,y,z에 대한 회전 함수
    // static -> 메모리 상에 상주함. 즉 상시 사용 가능
    static double rotateX(double angle);
    static double rotateY(double angle);
    static double rotateZ(double angle);

    Coordinate rotate(double angleX, double angleY, double angleZ);
};

#endif //FIRST_PROBS_COORDINATE_H
