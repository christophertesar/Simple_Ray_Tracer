#include "camera.hpp"

camera::camera(){
    origin = point3(0.0, 0.0, 0.0);
    horizontal = vec3(160.0, 0.0, 0.0);
    vertical = vec3(0.0 , 90.0, 0.0);
    bottom_left_corner = -horizontal/2 - vertical/2 - vec3(0.0, 0.0, 1.0) + origin;
}

camera::camera(int width,int height,double focal_length){
    
    origin = point3(0.0, 0.0, 0.0);
    horizontal = vec3(static_cast<double>(width), 0.0, 0.0);
    vertical = vec3(0.0 ,static_cast<double>(height), 0.0);
    bottom_left_corner = -horizontal/2 - vertical/2 - vec3(0.0, 0.0, focal_length) + origin;
    
}

ray camera::get_ray(double h, double v){
    return ray(origin, bottom_left_corner + v*vertical + h*horizontal - origin);
}