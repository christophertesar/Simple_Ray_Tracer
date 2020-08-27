#ifndef HITTABLE_LIST_HPP
#define HITTBALE_LIST_HPP

#include "hittable.hpp"
#include "misc.hpp"
#include <memory>
#include <vector>


class hittable_list : public hittable{
    public:
        hittable_list();
        hittable_list(std::shared_ptr<hittable>);

        virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const override;


    public:

        std::vector<std::shared_ptr<hittable>> object_list;
        
    private:
        
};


#endif