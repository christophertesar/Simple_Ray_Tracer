#include "vec3.hpp"

//Constructors
vec3::vec3(){
    x = 0;
    y = 0;
    z = 0;
}

vec3::vec3(double xn,double yn,double zn){
    x = xn;
    y = yn;
    z = zn;
}

//Overloaded operator functions

vec3 vec3::operator-() const{
    return vec3(-x,-y,-z);
}

vec3& vec3::operator+=(const vec3 &v){
    x += v.get_x();
    y += v.get_y();
    z += v.get_z();
    return *this;
}

vec3 vec3::operator*=(double n){
    x *= n;
    y *= n;
    z *= n;
    return *this;
}

vec3 vec3::operator/=(double n){
    return *this *= 1/n;
}

//General Vector Functions

double vec3::length(){
    return std::sqrt(length_squared());
}

double vec3::length_squared(){
    return x*x + y*y + z*z;
}

//Accessor and Mutator methods

double vec3::get_x() const{
    return x;
}

double vec3::get_y() const{
    return y;
}

double vec3::get_z() const{
    return z;
}

void vec3::set_comp(double xi, double yi, double zi){
    x = xi;
    y = yi;
    z = zi;
}