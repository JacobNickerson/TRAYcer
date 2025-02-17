#include "camera.hpp"

void Camera::initialize() {
    image_height = std::max(int(image_width / aspect_ratio),1);  // image height must be at least 1
    center = look_from;
    pixel_samples_scale = 1.0 / samples_per_pixel;

    // Viewport Dimensions
    auto theta = degrees_to_radians(vfov);
    auto h = tan(theta/2);
    auto viewport_height = 2 * h * focus_dist;
    auto viewport_width = viewport_height * (double(image_width) / image_height);

    // Calculate u,v,w basis vectors
    w = unit_vector(look_from - look_at);
    u = unit_vector(cross(view_up, w));
    v = cross(w, u);

    // Viewport Edge Vectors
    auto viewport_u = viewport_width * u;   // vector starts top left and goes L->R
    auto viewport_v = viewport_height * -v; // vector starts top left and goes top to bottom

    // Distance Between Pixels
    pixel_delta_u = viewport_u / image_width;
    pixel_delta_v = viewport_v / image_height;

    // Starting Pixel (top left)
    auto viewport_upper_left = center - (focus_dist * w) - viewport_u/2 - viewport_v/2;
    pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    // Calculate defocus disk basis vectors
    auto defocus_radius = focus_dist * tan(degrees_to_radians(defocus_angle / 2));
    defocus_disk_u = u * defocus_radius;
    defocus_disk_v = v * defocus_radius;
}

Color Camera::ray_color(const ray& r, int depth, const hittable& world) const {
    if (depth <= 0) { // prevent recursion from exceeding stack
        return Color(0,0,0);
    }
    hit_record rec;
    if (world.hit(r, interval(0.001, infinity), rec)) {  // we use 0.001 to avoid errors introduced by floating point rounding
        ray scattered;
        Color attenuation;
        if (rec.mat->scatter(r, rec, attenuation, scattered)) {
            return attenuation * ray_color(scattered, depth-1, world);
        }
        return Color(0,0,0);
    }

    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5*(unit_direction.y() + 1.0);
    // linear interpolation takes form (1-a) * startvalue + a*endvalue
    // this is a linear scale for color where in this case 0 = white, 1 = blue, 0.5 = blend
    return (1.0 - a) * Color(1,1,1) + a*Color(0.5,0.7,1);
}

void Camera::render(const hittable& world) {
    initialize();

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        std::clog << "\rScanlines remaining: " << (image_height-j) << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) {
            Color pixel_color(0,0,0);
            for (int sample = 0; sample < samples_per_pixel; sample++) {
                ray r = get_ray(i, j);
                pixel_color += ray_color(r, max_depth, world);
            }
            write_color(std::cout, pixel_samples_scale * pixel_color);
        }
    }
    std::clog << "\rDone.                   \n";
}

ray Camera::get_ray(int i, int j) const {
    auto offset = sample_square();
    auto pixel_sample = pixel00_loc
                        + ((i + offset.x()) * pixel_delta_u)
                        + ((j + offset.y()) * pixel_delta_v);
    point3 ray_origin;
    if (defocus_angle <= 0) {
        ray_origin = center;
    } else {
        ray_origin = defocus_disk_sample();
    }
    auto ray_direction = pixel_sample - ray_origin;

    return ray(ray_origin, ray_direction);                 
}

vec3 Camera::sample_square() const {
    return vec3(random_double() - 0.5, random_double() - 0.5, 0);
}

point3 Camera::defocus_disk_sample() const {
    auto p = random_in_unit_disk();
    return center + (p[0] * defocus_disk_u) + (p[1] * defocus_disk_v);
}