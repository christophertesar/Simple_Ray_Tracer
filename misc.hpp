#ifndef MISC_HPP
#define MISC_HPP

#include <iostream>
#include <cmath>
#include <memory>
#include <fstream>
#include <chrono>
#include <cassert>
#include "vec3.hpp"
#include "ray.hpp"

void write_color(std::ofstream&, color);
void initiate_write(std::ofstream&,const int width,const int height);
color ray_color(ray&);





#endif