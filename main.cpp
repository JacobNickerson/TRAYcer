#include "rtweekend.h"
#include "camera.hpp"
#include "hittable_list.hpp"
#include "sphere.hpp"

int main() {
    // World
    hittable_list world;

    auto material_ground = make_shared<Lambertian>(Color(0.8, 0.8, 0.0));
    auto material_center = make_shared<Lambertian>(Color(0.1, 0.2, 0.5));
    auto material_left   = make_shared<Dielectric>(1.5);
    auto material_bubble = make_shared<Dielectric>(1.0 / 1.5);
    auto material_right  = make_shared<Metal>(Color(0.8, 0.6, 0.2), 1.0);

    world.add(make_shared<sphere>(point3( 0.0, -100.5, -1.0), 100.0, material_ground));
    world.add(make_shared<sphere>(point3( 0.0,    0.0, -2.5),   0.5, material_center));
    world.add(make_shared<sphere>(point3(-1.0,    0.0, -1.0),   0.5, material_left));
    world.add(make_shared<sphere>(point3( 1.5,    0.0, -2.0),   0.5, material_right));
    world.add(make_shared<sphere>(point3(-1.0, 0.0, -1.0), 0.4, material_bubble));

    // Camera
    Camera cam;
    cam.aspect_ratio = 16.0/9.0;
    cam.image_width = 1440;
    cam.max_depth = 50;
    
    // Rendering
    cam.render(world);
}