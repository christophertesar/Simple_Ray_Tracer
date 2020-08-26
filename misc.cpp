#include "misc.hpp"

void write_color(std::ofstream &file, color pixel_color){
    file << static_cast<int>(255.00 * pixel_color.get_x()) << ' '
         << static_cast<int>(255.00 * pixel_color.get_y()) << ' '
         << static_cast<int>(255.00 * pixel_color.get_z()) << '\n';
}

void initiate_write(std::ofstream& file,const int width,const int height){
    file << "P3\n" << width << ' ' << height << '\n' << "255\n";
}

color ray_color(ray &v){
    vec3 unit_direction = unit_vector(v.get_direction());
    auto t = 0.5*(unit_direction.get_y() + 1.0);
    return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
}