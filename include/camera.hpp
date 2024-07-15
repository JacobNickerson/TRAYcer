#ifndef CAMERA_H
#define CAMERA_H

#include "rtweekend.h"
#include "material.hpp"
#include "vec3.hpp"
#include "color.hpp"
#include "ray.hpp"
#include "hittable.hpp"
#include "color_functions.hpp"

class Camera {
    private:
        int image_height;
        double pixel_samples_scale;
        point3 center;
        point3 pixel00_loc;
        vec3 pixel_delta_u;
        vec3 pixel_delta_v;

        void initialize();

        Color ray_color(const ray& r, int depth, const hittable& world) const;
        
    public:
        double aspect_ratio = 1;
        int image_width = 400;
        int samples_per_pixel = 10; // number of random samples for each pixel
        int max_depth = 10;

        void render(const hittable& world);

        ray get_ray(int i, int j) const;

        vec3 sample_square() const;
};


#endif