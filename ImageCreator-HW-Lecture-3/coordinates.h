#ifndef COORDINATES_H
#define COORDINATES_H

#include "pixelColor.h"
#include "rendering.h"
#include "vec.h"

int getImageX() {
    // The size of the image by X axis
    const int imageX = 1600; 
    return imageX;
}

int getImageY() {
    // The size of the image by X axis
    const int imageY = 800; 
    return imageY;
}

PixelColor startingColor( 0 , 65 , 255);
float focal_length = 300.0;

Vec getOrigin() { 
    Vec origin(0,0,0);
    return origin;
    }

Vec getHorizontal(){
    Vec horizontal = Vec(getImageX()/2, 0, 0);
    return horizontal;
}

Vec getVertical(){
    Vec vertical = Vec(0, getImageY()/2, 0);
    return vertical;
}

Vec getLeftCornetr() {
Vec lower_left_corner = getOrigin() - getHorizontal() - getVertical() - Vec(0, 0, focal_length);
return lower_left_corner;
}



#endif //!COORDINATES_H
