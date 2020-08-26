#include "ray.hpp"

point3 ray::get_origin() const{
    return origin;
}

vec3 ray::get_direction() const{
    return direction;
}

point3 ray::at(double t) const {
    return origin + direction*t;
}