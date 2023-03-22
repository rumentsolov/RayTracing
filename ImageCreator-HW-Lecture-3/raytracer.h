#ifndef RAY_TRACER_H
#define RAY_TRACER_H

#include "point.h"
#include "ray.h"
#include "vec.h"
#include "pixelColor.h"

#include <iostream>

PixelColor ray_color(const ray& r) {

    Vec unit_direction = unit_vector(r.direction());

    float t = 0.5*(unit_direction.getY() + 1.0);

    //return (1.0-t)*PixelColor(1.0, 1.0, 1.0) + t*PixelColor(0.5, 0.7, 1.0);
}


int newMain() {

    // Image
    const auto aspect_ratio = 16.0 / 9.0;
    const int image_width = 400;
    const int image_height = static_cast<int>(image_width / aspect_ratio);

    // Camera

    auto viewport_height = 2.0;
    auto viewport_width = aspect_ratio * viewport_height;
    auto focal_length = 1.0;

    auto origin = Point(0, 0, 0);
    auto horizontal = Vec(viewport_width, 0, 0);
    auto vertical = Vec(0, viewport_height, 0);
    //auto lower_left_corner = origin - horizontal/2 - vertical/2 - Vec(0, 0, focal_length);

    // Render

    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int j = image_height-1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            auto u = double(i) / (image_width-1);
            auto v = double(j) / (image_height-1);
            //ray r(origin, lower_left_corner + u*horizontal + v*vertical - origin);
            //PixelColor pixel_color = ray_color(r);
            //write_color(std::cout, pixel_color);
        }
    }

    std::cerr << "\nDone.\n";
}

#endif //! RAY_TRACER_H