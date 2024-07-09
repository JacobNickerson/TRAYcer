#include "rtweekend.h"
#include "camera.h"
#include "hittable.h"
#include "hittable_list.h"
#include "material.h"
#include "sphere.h"


int main() {
    // World
    hittable_list world;

    auto material_ground = make_shared<Lambertian>(color(0.8, 0.8, 0.0));
    auto material_center = make_shared<Metal>(color(0.99, 0.0, 0.99));
    auto material_left   = make_shared<Metal>(color(0.4, 0.0, 0.7));
    auto material_right  = make_shared<Metal>(color(0.5, 0.3, 0.2));

    world.add(make_shared<sphere>(point3( 0.0, -100.5, -1.0), 100.0, material_ground));
    world.add(make_shared<sphere>(point3( 0.0,    0.0, -2.5),   0.5, material_center));
    world.add(make_shared<sphere>(point3(-1.0,    0.0, -1.0),   0.5, material_left));
    world.add(make_shared<sphere>(point3( 1.5,    0.0, -1.0),   0.5, material_right));

    // Camera
    camera cam;
    cam.aspect_ratio = 16.0/9.0;
    cam.image_width = 1440;
    cam.max_depth = 50;
    
    // Rendering
    cam.render(world);
}