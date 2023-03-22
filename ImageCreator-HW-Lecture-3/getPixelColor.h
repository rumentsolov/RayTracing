#ifndef GET_PIXEL_COLOR_H
#define GET_PIXEL_COLOR_H

#include <cmath>
#include <iostream>
#include "CameraBuff.h"
#include "ray.h"


PixelColor getPixelColor(const Ray& r, PixelColor colorP) {
    Vec unit_direction = unit_vector(r.direction());
    
    int x = abs(r.direction().getX());
    int y = abs(r.direction().getY());
    if(x > 255) x = 255;
    if(y > 255) y = 255;
    //std::cout << x << " " <<x<< std::endl;
    return colorP*y*x;
    // abs((int)(r.direction().getX()))*
    // abs((int)(r.direction().getY()))
}


#endif //!GET_PIXEL_COLOR_H