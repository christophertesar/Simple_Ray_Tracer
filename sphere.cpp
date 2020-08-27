#include "sphere.hpp"

sphere::sphere(){

}

sphere::sphere(point3 cen, double rad) : radius(rad), center(cen){

}

bool sphere::hit(const ray& r, double tmin, double tmax, hit_record& rec) const{
    //Compute discriminant to determine intersection of sphere with ray.
    auto origin_to_center = r.get_origin() - center;
    auto a = dot(r.get_direction(),r.get_direction());
    auto b = 2*dot(r.get_direction(),origin_to_center);
    auto c = dot(origin_to_center,origin_to_center) - radius*radius;
    
    double discriminant = b*b - 4*a*c; //Negative num means 0 intersections, 0 means one and positive numbers means 2 hit points.
    //Disregard tangental hit points.
    if (discriminant > 0){
        auto root = std::sqrt(discriminant);
        auto quad = (-b - root)/(2*a);
            if (quad > tmin && quad < tmax){ //Solution is between tmin and tmax
                rec.t = quad;           //record length t
                rec.p = r.at(quad);     //record point of intersection
                vec3 outward_normal = (rec.p - center) / radius;
                rec.set_face_normal(r, outward_normal); //record unit normal vector with normal always facing outwards.
                return true; //Sphere hit
            }

            quad = (-b + root) / (2*a);
            if (quad < tmax && quad > tmin) {
                rec.t = quad;
                rec.p = r.at(quad);
                vec3 outward_normal = (rec.p - center) / radius;
                rec.set_face_normal(r, outward_normal);
                return true; //Sphere hit opposite side
        }
    }
    return false; //No ray intersected with sphere.
}