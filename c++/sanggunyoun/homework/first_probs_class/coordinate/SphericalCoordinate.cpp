//
// Created by eddi on 23. 12. 1.
//

#include "SphericalCoordinate.h"
#include <cmath>
#include <iostream>
// 복붙공식 근데 우린 레이더를 봐야 하기때문에 알아야한다.
SphericalCoordinate::SphericalCoordinate(double radius, double azimuth, double elevation)
        : radius(radius), azimuth(azimuth), elevation(elevation) {}


std::tuple<double, double, double> SphericalCoordinate::toCartesian() const {
    double x = radius * sin(elevation) * cos(azimuth);
    double y = radius * sin(elevation) * sin(azimuth);
    double z = radius * cos(elevation);
    return std::make_tuple(x, y, z);
}

void SphericalCoordinate::print() const {
    std::cout << "Radius: " << radius << ", azimuth: " << azimuth << ", elevation: " << elevation << std::endl;
}
