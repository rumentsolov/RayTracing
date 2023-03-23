#ifndef RENDER_H
#define RENDER_H

#include <cmath>
#include <iostream>
#include "ray.h"
#include "getPixelColor.h"
#include "coordinates.h"

PixelColor RenderPixel( int &X , int &Y ){ 

//std::cout << X << " " << Y << " " << -focal_length << std::endl;

Vec vec(X, Y, 0);

Ray ray(getOrigin(),vec);

PixelColor color = getPixelColor(ray,startingColor) ;

    return color;
}

#endif //!RENDER_H