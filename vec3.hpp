#ifndef VEC3_HPP
#define VEC3_HPP

#include <cmath>
#include <iostream>
#include <fstream>
#include <random>


class vec3{
    public:
        vec3();
        vec3(double,double,double);

        vec3 operator-() const;

        vec3& operator+=(const vec3 &v);

        vec3 operator*=(double n);

        vec3 operator/=(double n);

        //Accessor and Mutator Functions
        double get_x() const;
        double get_y() const;
        double get_z() const;

        void set_comp(double,double,double);

        //Vector Operations
        double length();
        double length_squared();

        //Inline operator overloaded functions

        friend inline std::ostream& operator<<(std::ostream &out, const vec3 &v) {
            return out << v.x << ' ' << v.y << ' ' << v.z;
        }

        friend inline vec3 operator+(const vec3 &u, const vec3 &v) {
            return vec3(u.x + v.x, u.y + v.y, u.z + v.z);
        }

        friend inline vec3 operator-(const vec3 &u, const vec3 &v) {
            return vec3(u.x - v.x, u.y - v.y, u.z - v.z);
        }

        friend inline vec3 operator*(const vec3 &u, const vec3 &v) {
            return vec3(u.x * v.x, u.y * v.y, u.z * v.z);
        }

        friend inline vec3 operator*(double t, const vec3 &v) {
            return vec3(t*v.x, t*v.y, t*v.z);
        }

        friend inline vec3 operator*(const vec3 &v, double t) {
            return t * v;
        }

        friend inline vec3 operator/(vec3 v, double t) {
            return (1/t) * v;
        }

        friend inline double dot(const vec3 &u, const vec3 &v) {
            return u.x * v.x
                + u.y * v.y
                + u.z * v.z;
        }

        friend inline vec3 cross(const vec3 &u, const vec3 &v) {
            return vec3(u.y * v.z - u.z * v.y,
                        u.z * v.x - u.x * v.z,
                        u.x * v.y - u.y * v.x);
        }

        friend inline vec3 unit_vector(vec3 v) {
            return v / v.length();
        }
        

        //Vector Operations

        friend inline double dot(const vec3 &u, const vec3 &v);

        friend inline vec3 cross(const vec3 &u, const vec3 &v);

        friend inline vec3 unit_vector(vec3 v);


    private:
        double x,y,z; //3D coodinates

};

const double pivec = 3.1415926535897932385;

inline double random_double(){
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

inline double random_double(double min, double max){
    return min + (max-min)*random_double();
}

inline vec3 random(){
    return vec3(random_double(), random_double(), random_double());
}    

inline vec3 random(double min, double max){
    return vec3(random_double(min,max), random_double(min,max), random_double(min,max));
}

vec3 random_unit_vector();

vec3 reflect(vec3&, vec3&);

vec3 refract(vec3&, vec3&, double);


using point3 = vec3;
using color = vec3;

#endif