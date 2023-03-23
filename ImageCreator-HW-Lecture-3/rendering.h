#ifndef RENDER_H
#define RENDER_H

#include <cmath>
#include <iostream>
#include "ray.h"
#include "getPixelColor.h"
#include "coordinates.h"

PixelColor RenderPixel( int &X , int &Y ){ 

float v = float(Y) / getImageX();
float u = float(X) / getImageY();


//Vec vec = lower_left_corner + u*horizontal + v*vertical - origin;
Vec vec =  getLeftCornetr() + u*getHorizontal() + v*getVertical() - getOrigin();

//std::cout << vec << std::endl;

Ray ray(getOrigin(),vec);

PixelColor color = getPixelColor(ray,startingColor) ;
//std::cout << color << " ";
//m.draw(start,end ,color);
    return color;
}

#endif //!RENDER_H