#ifndef GET_PIXEL_COLOR_H
#define GET_PIXEL_COLOR_H

#include <cmath>
#include <iostream>
#include "CameraBuff.h"
#include "ray.h"
#include "coordinates.h"

PixelColor getPixelColor(Ray r, PixelColor colorP) {

    float x =  r.getX();
    float y =  r.getY();
    //float z = r.getZ()/index;

    //if(y > 254) y = 255;
    //if(y < 0) y = 255;

    //PixelColor retunCol = addY(colorP,y);
    PixelColor retunCol = addX(colorP,x) + addY(colorP,y) ;// + addZ(colorP,z);

    return retunCol;
}


#endif //!GET_PIXEL_COLOR_H