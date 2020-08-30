#include <iostream>
#include "misc.hpp"
#include "camera.hpp"
#include "ray.hpp"
#include "hittable_list.hpp"
#include "sphere.hpp"
#include "vec3.hpp"
#include "material.hpp"

int main(){

//Image Parameters

const double i_width = 1600; //Picture width and height
const double i_height = 900;
const double focal_length = 1.0;
const int samples_per_pixel = 100; //Anti-Aliasing samples
const int max_depth = 100;

const double aspect_ratio = (i_width)/(i_height);
const double viewport_height = 2.0;
const double viewport_width = aspect_ratio*viewport_height;



camera cam(viewport_width,viewport_height,focal_length); //Initialize camera object

std::ofstream file;
file.open("image.ppm");
assert(!file.fail());

initiate_write(file,i_width,i_height);

//Generate Objects
hittable_list world;

auto material_ground = std::make_shared<lambertian>(color(0.8,0.8,0.0));
auto material_left = std::make_shared<dielectric>(1.5);
auto material_center = std::make_shared<lambertian>(color(0,0.5,0.8));
auto material_right = std::make_shared<metal>(color(0.8,0.6,0.2),0.0);

world.object_list.push_back(std::make_shared<sphere>(point3( 0.0, -100.5, -1.0), 100.0, material_ground));
world.object_list.push_back(std::make_shared<sphere>(point3( 0.0,    0.0, -1.0),   0.5, material_center));
world.object_list.push_back(std::make_shared<sphere>(point3(-1.0,    0.0, -1.0),   0.5, material_left));
world.object_list.push_back(std::make_shared<sphere>(point3( 1.0,    0.0, -1.0),   0.5, material_right));

//Render Engine

std::cout << "Starting Render" << std::endl;

auto start = std::chrono::high_resolution_clock::now();

for (int j = i_height - 1; j >= 0; j--){  //Vertical Pixels; Top to bottom
    std::cerr << "\rLines Remaining: " << j << std::flush; //Number of lines left
    for(int i = 0; i < i_width; i++){ //Horizontal Pixels; Left to 
        color pixel_color(0,0,0);
        for(int s = 0; s < samples_per_pixel; s++){
            auto h = (double(i) + random_double())  / (i_width-1);
            auto v = (double(j) + random_double()) / (i_height-1);
            ray r = cam.get_ray(h,v);
            pixel_color += ray_color(r, world, max_depth);
        }
        write_color_clamp(file, pixel_color, samples_per_pixel);
    }
}

file.close();

//Timer

auto finish = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> elapsed = finish - start;
std::cout << "\nRender time: " << elapsed.count() << " s\n";

}