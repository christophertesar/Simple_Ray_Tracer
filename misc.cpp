#include "misc.hpp"

void write_color(std::ofstream &file, color pixel_color){
    file << static_cast<int>(255.99 * pixel_color.get_x()) << ' '
         << static_cast<int>(255.99 * pixel_color.get_y()) << ' '
         << static_cast<int>(255.99 * pixel_color.get_z()) << '\n';
}

void initiate_write(std::ofstream& file,const int width,const int height){
    file << "P3\n" << width << ' ' << height << '\n' << "255\n";
}

vec3 random_in_unit_sphere(){
    while(true){
        auto p = random(-1,1);
        if(p.length_squared() >= 1) continue;
            return p;
    }   
}

color ray_color(ray &v, hittable &world, int depth){ //Child classes of hittable are passable.
    hit_record rec;

    if(depth <= 0)
        return color(0,0,0);

    if (world.hit(v, 0.001, infinity, rec)){
        ray scattered; 
        color attenuation;
        if(rec.mat_ptr->scatter(v,rec,attenuation,scattered)){   //Check if scattered vector is valid for particular material.
            return attenuation * ray_color(scattered,world,depth-1); //return 
        }
        return color(0,0,0);
    }

    vec3 unit_direction = unit_vector(v.get_direction());
    auto t = 0.5*(unit_direction.get_y() + 1.0);
    return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
}

void write_color_clamp(std::ofstream &file, color pixel_color, int samples_per_pixel){
    
    auto r = pixel_color.get_x();
    auto g = pixel_color.get_y();
    auto b = pixel_color.get_z();

    auto scale = 1.0 / samples_per_pixel;
    
    r = std::sqrt(scale*r);  //Square root for Gamma Correction of 2.
    g = std::sqrt(scale*g);
    b = std::sqrt(scale*b);

    file << static_cast<int>(256 * clamp(r, 0.0, 0.999)) << ' '
         << static_cast<int>(256 * clamp(g, 0.0, 0.999)) << ' '
         << static_cast<int>(256 * clamp(b, 0.0, 0.999)) << '\n';
}

double schlick(double cosine, double ref_idx){
    auto r0 = (1-ref_idx) / (1+ref_idx);
    r0 = r0*r0;
    return r0 + (1-r0)*std::pow((1 - cosine),5);
}