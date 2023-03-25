#ifndef OBJECT_H
#define OBJECT_H

#include "pixelColor.h"
#include "vec.h"
#include "ray.h"

#include <iostream>

//? I set that every object point in space have coordinates and color
// maybe color is not for all objects but only for external objects

class Object : public Vec , public PixelColor{ 

public:
    
    Vec Coordinates;
    PixelColor inputCol;

    Object() {}
    Object(Vec Coordinates_, PixelColor inputCol_) : Coordinates(Coordinates_),inputCol(inputCol_)
    {

    }

};



#endif //! OBJECT_H