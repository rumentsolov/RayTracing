#ifndef GET_PIXEL_COLOR_H
#define GET_PIXEL_COLOR_H

#include <cmath>
#include <iostream>
#include "CameraBuff.h"
#include "ray.h"


PixelColor getPixelColor(Ray r, PixelColor colorP) {

    float x = r.getX();
    float y = r.getY();
    float z = r.getZ();

    //PixelColor retunCol = addY(colorP,y);

    PixelColor retunCol = addX(colorP,x) + addY(colorP,y) + addZ(colorP,z);

    return retunCol;
    // abs((int)(r.direction().getX()))*
    // abs((int)(r.direction().getY()))
}


#endif //!GET_PIXEL_COLOR_H