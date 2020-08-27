#include <iostream>
#include "misc.hpp"
#include "camera.hpp"
#include "ray.hpp"
#include "hittable_list.hpp"
#include "sphere.hpp"

int main(){

//Image Parameters

const double i_width = 1600; //Picture width and height
const double i_height = 900;
const double focal_length = 1.0;

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
world.object_list.push_back(std::make_shared<sphere>(point3(0,0,-1), 0.5));
world.object_list.push_back(std::make_shared<sphere>(point3(0,-100.5,-1), 100));

//Render Engine

auto start = std::chrono::high_resolution_clock::now();

for (int j = i_height - 1; j >= 0; j--){  //Vertical Pixels; Top to bottom
    std::cerr << "\rLines Remaining: " << j << std::flush; //Number of lines left
    for(int i = 0; i < i_width; i++){ //Horizontal Pixels; Left to right
        auto h = double(i) / (i_width-1);
        auto v = double(j) / (i_height-1);
        ray r =  cam.get_ray(h,v);
        color pixel_color = ray_color(r, world);
         
        write_color(file, pixel_color);
    }

}

file.close();

//Timer

auto finish = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> elapsed = finish - start;
std::cout << "\nRender time: " << elapsed.count() << " s\n";

}