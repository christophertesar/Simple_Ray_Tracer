#ifndef CAMERA_HPP
#define CAMERA_HPP  

#include "vec3.hpp"
#include "misc.hpp"
#include "ray.hpp"

class camera{
    public:
        camera();
        camera(double width,double height,double focal_length);

        ray get_ray(double, double);

    private:
        point3 origin;
        point3 bottom_left_corner;
        vec3 horizontal;
        vec3 vertical;
};

#endif
