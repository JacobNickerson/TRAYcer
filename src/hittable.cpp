#include "hittable.hpp"

void hit_record::set_face_normal(const ray& r, const vec3& outward_normal) {
    front_face = dot(r.direction(), outward_normal) < 0;
    if (front_face) {
        normal = outward_normal;
    } else {
        normal = -outward_normal;
    }
}

