#ifndef COORDINATES_H
#define COORDINATES_H

#include "pixelColor.h"
#include "rendering.h"
#include "vec.h"

int getImageX() {
    // The size of the image by X axis
    const int imageX = 1200; 
    return imageX;
}

int getImageY() {
    // The size of the image by X axis
    const int imageY = getImageX()/2; 
    return imageY;
}

PixelColor startingColor( 0 , 0 , 0);

float focal_length = getImageX()/2;

Vec getOrigin() { 
    Vec origin(0,getImageY()/2,0);
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
