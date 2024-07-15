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
        int image_height;           // Image height
        double pixel_samples_scale; // Color scale factor
        point3 center;              // Camera center
        point3 pixel00_loc;         // Location of first pixel (0,0)
        vec3 pixel_delta_u;         // Offset to pixel to the right 
        vec3 pixel_delta_v;         // Offset to pixel below
        vec3 u, v, w;               // Camera frame basis vectors (linalg?!)

        void initialize();

        Color ray_color(const ray& r, int depth, const hittable& world) const;
        
    public:
        double aspect_ratio = 1;            // Ratio of image width to height
        double vfov = 90;                   // Vertical view angle in degrees

        point3 look_from = point3(0,0,0);   // Point Camera "looks" from
        point3 look_at = point3(0,0,-1);    // Point Camera "looks" at
        vec3 view_up = vec3(0,1,0);         // Up direction relative to camera

        int image_width = 400;              // Camera default width
        int samples_per_pixel = 10;         // number of random samples for each pixel
        int max_depth = 10;                 // Maximum number of ray bounces

        void render(const hittable& world);

        ray get_ray(int i, int j) const;

        vec3 sample_square() const;
};


#endif