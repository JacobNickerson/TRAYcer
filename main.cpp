#include "rtweekend.h"
#include "camera.h"
#include "hittable.h"
#include "hittable_list.h"
#include "sphere.h"


int main() {
    // World
    hittable_list world;
    world.add(make_shared<sphere>(point3(0,0,-5), 2));
    world.add(make_shared<sphere>(point3(-1,0,-2), 0.5));
    world.add(make_shared<sphere>(point3(1,0,-2), 0.5));

    // Camera
    camera cam;
    cam.aspect_ratio = 16.0/9.0;
    cam.image_width = 1920;
    
    // Rendering
    cam.render(world);
}