#include "color.h"
#include "ray.h"
#include "vec3.h"

#include <iostream>


double hit_sphere(const point3& center, double radius, const ray& r) {  // returns a double, if > 0 then double is used for surface normals
    vec3 oc = center - r.origin();
    auto a = r.direction().length_squared();
    auto h = dot(r.direction(), oc);
    auto c = oc.length_squared() - radius*radius;
    auto discriminant = h*h - a*c;

    if (discriminant < 0) {  // imaginary roots -> no intersection
        return -1;
    } else {
        return (h - sqrt(discriminant)) / a;
    }
}

color ray_color(const ray& r) {
    auto t = hit_sphere(point3(0,0,-1), 0.5, r);
    if (t > 0) {
        vec3 normal = unit_vector(r.at(t) - vec3(0,0,-1));
        return 0.5*color(normal.x()+1, normal.y()+1, normal.z()+1);
    }

    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5*(unit_direction.y() + 1.0);
    // linear interpolation takes form (1-a) * startvalue + a*endvalue
    // this is a linear scale for color where in this case 0 = white, 1 = blue, 0.5 = blend
    return (1.0 - a) * color(1,1,1) + a*color(0.5,0.7,1);
}

int main() {

    // Image
    auto aspect_ratio = 16.0 / 9.0;
    int image_width = 2160;
    int image_height = std::max(int(image_width / aspect_ratio),1);  // image height must be at least 1

    // Camera
    auto focal_length = 1.0;
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (double(image_width) / image_height);
    auto camera_center = point3(0, 0, 0);

    // Viewport Edge Vectors
    auto viewport_u = vec3(viewport_width, 0, 0);   // vector starts top left and goes L->R
    auto viewport_v = vec3(0, -viewport_height, 0); // vector starts top left and goes top to bottom

    // Distance Between Pixels
    auto pixel_delta_u = viewport_u / image_width;
    auto pixel_delta_v = viewport_v / image_height;

    // Starting Pixel (top left)
    auto viewport_upper_left = camera_center
                               - vec3(0, 0, focal_length)
                               - viewport_u / 2
                               - viewport_v / 2;
    auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    // Rendering

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        std::clog << "\rScanlines remaining: " << (image_height-j) << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) {
            auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            auto ray_direction = pixel_center - camera_center;
            ray r(camera_center, ray_direction);

            color pixel_color = ray_color(r);
            write_color(std::cout, pixel_color);
        }
    }

    std::clog << "\rDone.                   \n";
}