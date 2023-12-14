//
// Created by eddi on 23. 12. 1.
//

#ifndef FIRST_PROBS_SPHERICALCOORDINATE_H
#define FIRST_PROBS_SPHERICALCOORDINATE_H

#include <tuple>

class SphericalCoordinate {
private:
    double radius; // r
    double azimuth; // Seta
    double elevation; // Py

public:
    SphericalCoordinate(double radius, double azimuth, double elevation);
    std::tuple<double, double, double> toCartesian() const; // 반지름, 고도 방위 값으로 x, y, z 로 convert 한다는 뜻
    void print() const;
};

#endif //FIRST_PROBS_SPHERICALCOORDINATE_H
