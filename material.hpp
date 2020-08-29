#ifndef MATERIAL_HPP
#define MATERIAL_HPP


#include "ray.hpp"
#include "vec3.hpp"
#include "misc.hpp"

struct hit_record;

class material{
    public:
        //Produce a scattered ray, and how much it is attenuated.
        virtual bool scatter(ray& r_in, hit_record& rec, color& attenuation, ray& scattered) = 0;

};

class lambertian : public material{
    public:
        lambertian(color a) : albedo(a){}
        
        virtual bool scatter(ray& r_in, hit_record& rec, color& attenuation, ray& scattered) override{
            vec3 scatter_direction = rec.normal + random_unit_vector(); //Random unit vector from tip of normal vector.
            scattered = ray(rec.p, scatter_direction); //Created scattered vector with starting point of hit point.
            attenuation = albedo;
            return true;
        }

    public:
        color albedo; //How much light is being absorbed without being reflected.

};

class metal : public material{
    public:
        metal(color a) : albedo(a){}
        
        virtual bool scatter(ray& r_in, hit_record& rec, color& attenuation, ray& scattered) override{
            vec3 unit_vec = unit_vector(r_in.get_direction());
            vec3 reflected = reflect(unit_vec, rec.normal); //get reflected vector
            scattered = ray(rec.p, reflected); //get a ray with a starting point of hitpoint
            attenuation = albedo;              
            return (dot(scattered.get_direction(), rec.normal) > 0); //Check if reflected ray is in the same direction of the normal
        }   //Otherwise, ray is reflected into object and not outwards.

    private:
        color albedo;


};

#endif