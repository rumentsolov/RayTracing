#ifndef RAY_H
#define RAY_H

#include "vec.h"
#include <iostream>
struct Ray {
        Vec orig;
        Vec dir;

        Ray(): orig(0,0,0), dir(0,0,0){}; 
        Ray(const Vec& orig_, const Vec& dir_)
            : orig(orig_), dir(dir_)
        {}

        Vec origin() const  { return orig; }
        Vec direction() const { return dir; }
};

    float getLength(const Ray &r){
        float x = r.dir.x - r.orig.x;
        float y = r.dir.y - r.orig.y;
        float z = r.dir.z - r.orig.z;
        return sqrt(x * x + y * y + z * z); 
    }
        
#endif //! RAY_H