#include "sphere.hpp"

bool sphere::hit(const ray& r, interval ray_t, hit_record& rec) const {
    vec3 oc = center - r.origin();
    auto a = r.direction().length_squared();
    auto h = dot(r.direction(), oc);
    auto c = oc.length_squared() - radius*radius;

    auto discriminant = h*h - a*c;
    if (discriminant < 0) {
        return false;
    }

    auto sqrtd = sqrt(discriminant);

    // Find root in acceptable range
    auto root = (h - sqrtd) / a;
    if (!ray_t.surrounds(root)) { 
        root = (h + sqrtd) / a;
        if (!ray_t.surrounds(root)) {
            return false; 
        }
    }
    
    // Hit detected
    rec.t = root; // set hitrecord t to root
    rec.p = r.at(rec.t);  // set hitrecord point to ray(root)
    vec3 outward_normal = (rec.p - center) / radius; // calculate normal vector
    rec.set_face_normal(r, outward_normal);  // set hit record normal vector
    rec.mat = mat;

    return true; 
}