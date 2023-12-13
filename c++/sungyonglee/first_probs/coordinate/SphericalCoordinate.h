//
// Created by eddi on 23. 12. 1.
//

#ifndef FIRST_PROBS_SPHERICALCOORDINATE_H
#define FIRST_PROBS_SPHERICALCOORDINATE_H

#include <tuple>

class SphericalCoordinate {
private:
    double radius;
    double azimuth;         // 고도
    double elevation;       // 방위각

public:
    SphericalCoordinate(double radius, double azimuth, double elevation);
    std::tuple<double, double, double> toCartesian() const;     // toCartesian x,y,z 좌표값을 생성
    void print() const;
};

#endif //FIRST_PROBS_SPHERICALCOORDINATE_H
