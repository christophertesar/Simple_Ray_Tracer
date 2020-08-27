#ifndef MISC_HPP
#define MISC_HPP

#include <iostream>
#include <cmath>
#include <memory>
#include <fstream>
#include <chrono>
#include <cassert>
#include <limits>
#include "vec3.hpp"
#include "ray.hpp"
#include "hittable.hpp"

//Const

const double infinity = std::numeric_limits<double>::max();
const double pi = 3.1415926535897932385;

//Functions

void write_color(std::ofstream&, color);

void initiate_write(std::ofstream&,const int width,const int height);

color ray_color(ray&, hittable&);

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

#endif