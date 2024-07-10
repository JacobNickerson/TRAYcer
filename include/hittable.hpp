#ifndef HITTABLE_H
#define HITTABLE_H

#include "vec3.hpp"
#include "interval.hpp"
#include "ray.hpp"

class Material;

class hit_record {
    public:
        point3 p;
        vec3 normal;
        shared_ptr<Material> mat;
        double t;
        bool front_face;

        void set_face_normal(const ray& r, const vec3& outward_normal); // outward_normal is assumed to have UNIT LENGTH
};

class hittable {
    public:
        virtual ~hittable() = default;

        virtual bool hit(const ray&r, interval ray_t, hit_record& rec) const = 0;
};

#endif