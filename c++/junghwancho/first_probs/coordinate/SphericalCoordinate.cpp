//
// Created by eddi on 23. 12. 1.
//

#include "SphericalCoordinate.h"
#include <cmath>
#include <iostream>

// **** 쫌 중요하다.
SphericalCoordinate::SphericalCoordinate(double radius, double azimuth, double elevation)
        : radius(radius), azimuth(azimuth), elevation(elevation) {}

// 아래 공식은 좀 알자(외우자)
std::tuple<double, double, double> SphericalCoordinate::toCartesian() const {
    double x = radius * sin(elevation) * cos(azimuth);
    double y = radius * sin(elevation) * sin(azimuth);
    double z = radius * cos(elevation);
    return std::make_tuple(x, y, z);
}

void SphericalCoordinate::print() const {
    std::cout << "Radius: " << radius << ", azimuth: " << azimuth << ", elevation: " << elevation << std::endl;
}
