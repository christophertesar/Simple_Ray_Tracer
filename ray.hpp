#ifndef RAY_HPP
#define RAY_HPP

#include "vec3.hpp"

class ray{
    public:
        ray();
        ray(point3 orig, vec3 dir) : origin(orig), direction(dir){}

        point3 get_origin() const;
        vec3 get_direction() const;

        point3 at(double t) const;

    private:
        point3 origin;
        vec3 direction;

};

#endif