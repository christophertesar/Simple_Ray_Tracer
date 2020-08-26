#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "misc.hpp"
#include "ray.hpp"
#include "vec3.hpp"
#include "hittable.hpp"

class sphere : public hittable{
    public:
        sphere();
        sphere(point3, double);

        virtual bool hit(const ray&, double tmin, double tmax, hit_record&) const override;

    private:
        point3 center;
        double radius;



};

#endif