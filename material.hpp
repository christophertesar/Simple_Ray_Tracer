#ifndef MATERIAL_HPP
#define MATERIAL_HPP


#include "ray.hpp"
#include "vec3.hpp"
#include "misc.hpp"

struct hit_record;

double schlick(double cosine, double ref_idx);

class material{
    public:
        //Produce a scattered ray, and how much it is attenuated.
        virtual bool scatter(ray& r_in, hit_record& rec, color& attenuation, ray& scattered) = 0;

};

//Materials

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
        metal(color a, double f) : albedo(a), fuzz(f < 1 ? f : 1){}
        
        virtual bool scatter(ray& r_in, hit_record& rec, color& attenuation, ray& scattered) override{
            vec3 unit_vec = unit_vector(r_in.get_direction());
            vec3 reflected = reflect(unit_vec, rec.normal); //get reflected vector
            scattered = ray(rec.p, reflected + fuzz*random_unit_vector()); //get a ray with a starting point of hitpoint
            attenuation = albedo;              
            return (dot(scattered.get_direction(), rec.normal) > 0); //Check if reflected ray is in the same direction of the normal with random scattering.
        }   //Otherwise, ray is reflected into object and not outwards.

    private:
        color albedo;
        double fuzz;

};

class dielectric : public material{
    public:
        dielectric(double ri) : ref_idx(ri) {}

        virtual bool scatter(ray& r_in, hit_record& rec, color& attenuation, ray& scattered) override {
            attenuation = color(1.0, 1.0, 1.0);
            double etai_over_etat = rec.front_face ? (1.0 / ref_idx) : ref_idx;

            vec3 unit_direction = unit_vector(r_in.get_direction());
            double cos_theta = fmin(dot(-unit_direction, rec.normal), 1.0);
            double sin_theta = sqrt(1.0 - cos_theta*cos_theta);
            if (etai_over_etat * sin_theta > 1.0 ) {
                vec3 reflected = reflect(unit_direction, rec.normal);
                scattered = ray(rec.p, reflected);
                return true;
            }
            
            double reflect_prob = schlick(cos_theta, etai_over_etat);
            if (random_double() < reflect_prob)
            {
                vec3 reflected = reflect(unit_direction, rec.normal);
                scattered = ray(rec.p, reflected);
                return true;
            }
            
            vec3 refracted = refract(unit_direction, rec.normal, etai_over_etat);
            scattered = ray(rec.p, refracted);
            return true;
        }

        double ref_idx;
};


#endif