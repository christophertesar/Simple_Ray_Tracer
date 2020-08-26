#include "hittable_list.hpp"

hittable_list::hittable_list(){

}

hittable_list::hittable_list(std::shared_ptr<hittable> object){

}

bool hittable_list::hit(const ray& r, double t_min, double t_max, hit_record& rec) const{

}