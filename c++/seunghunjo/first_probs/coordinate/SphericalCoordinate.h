//
// Created by eddi on 23. 12. 1.
//

#ifndef FIRST_PROBS_SPHERICALCOORDINATE_H
#define FIRST_PROBS_SPHERICALCOORDINATE_H

#include <tuple>

class SphericalCoordinate {
private:
    // 반경(반지름)
    double radius;
    // 고각(포를 쏘려할 때 각도)
    double azimuth;
    // 방위각(포를 쏘려할 때 방향 도)
    double elevation;

public:
    SphericalCoordinate(double radius, double azimuth, double elevation);
    std::tuple<double, double, double> toCartesian() const; // 좌표값 치환하
    void print() const;
};

#endif //FIRST_PROBS_SPHERICALCOORDINATE_H
