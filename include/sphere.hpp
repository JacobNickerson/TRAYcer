#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.hpp"
#include "rtweekend.h"
#include "vec3.hpp"

class sphere : public hittable {
    public:
        sphere(const point3& center, double radius, shared_ptr<Material> mat) : center(center), radius(fmax(0, radius)), mat(mat) {
        }

        bool hit(const ray& r, interval ray_t, hit_record& rec) const override; 

    private:
        point3 center;
        double radius;
        shared_ptr<Material> mat;
};

#endif