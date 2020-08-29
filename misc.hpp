#ifndef MISC_HPP
#define MISC_HPP

#include <iostream>
#include <cmath>
#include <memory>
#include <fstream>
#include <chrono>
#include <cassert>
#include <limits>
#include <cstdlib>
#include <random>

#include "ray.hpp"
#include "vec3.hpp"
#include "hittable.hpp"
#include "material.hpp"

//Const

const double infinity = std::numeric_limits<double>::max();
const double pi = 3.1415926535897932385;

//Functions

vec3 random_in_unit_sphere();

void write_color(std::ofstream&, color);

void initiate_write(std::ofstream&,const int width,const int height);

color ray_color(ray&, hittable&, int);

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}
/*
inline double random_double(){
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

inline double random_double(double min, double max){
    return min + (max-min)*random_double();
}
*/
inline double clamp(double x, double min, double max){
    if(x < min){
        return min;
    }
    if(x > max){
        return max;
    }
    return x;
}

void write_color_clamp(std::ofstream&, color, int);



#endif