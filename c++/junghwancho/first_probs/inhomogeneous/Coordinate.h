//
// Created by eddi on 23. 12. 1.
//

#ifndef FIRST_PROBS_COORDINATE_H
#define FIRST_PROBS_COORDINATE_H

class Coordinate {
public:
    // get을 만들기 귀찮아서;; 이러면 안된다 ㅋㅋ private에 넣자
    double x;
    double y;
    double z;

    // new를 사용하지 않아도 되도록 하는 기능 Coordinate
    Coordinate(double x, double y, double z);

    // using = typdef, RotationFunction은 double을 return, double을 parameter로 받음
    using RotationFunction = double (*)(double);

    static double rotateX(double angle);
    static double rotateY(double angle);
    static double rotateZ(double angle);

    Coordinate rotate(double angleX, double angleY, double angleZ);
};

#endif //FIRST_PROBS_COORDINATE_H
