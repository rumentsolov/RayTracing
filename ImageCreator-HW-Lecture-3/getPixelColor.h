#ifndef GET_PIXEL_COLOR_H
#define GET_PIXEL_COLOR_H

#include <cmath>
#include <iostream>
#include "CameraBuff.h"
#include "ray.h"
#include "coordinates.h"

PixelColor getPixelColor(Ray r, PixelColor colorP) {

    float x =  abs(getImageX()/2 - r.getX()) ;
    float y =  abs(getImageY()/2 - r.getY());
    float z =  r.getZ();

    if(x > 254) x = 255;
    if(x < 0) x = 255;

    if(y > 254) y = 255;
    if(y < 0) y = 255;

    if(z > 254) z = 255;
    if(z < 0) z = 255;

    //PixelColor retunCol = addY(colorP,y);
    PixelColor retunCol = addX(colorP,x) - addY(colorP,y);//  - addZ(colorP,z);

    return retunCol;
}


#endif //!GET_PIXEL_COLOR_H