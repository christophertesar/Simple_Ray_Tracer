#include "hittable_list.hpp"

hittable_list::hittable_list(){

}

hittable_list::hittable_list(std::shared_ptr<hittable> object){
    object_list.push_back(object);
}

bool hittable_list::hit(const ray& r, double t_min, double t_max, hit_record& rec) const{
    bool hit_flag = false; //Hit nothing by default

    for (const auto &object : object_list){ //Traverse object list
        if (object ->hit(r,t_min, t_max, rec)){
            t_max = rec.t;
            hit_flag = true;
        }
    }

    return hit_flag;
}