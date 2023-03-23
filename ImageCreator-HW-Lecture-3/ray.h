#ifndef RAY_H
#define RAY_H

#include "vec.h"

class Ray {
    public:
        Vec orig;
        Vec dir;

        Ray(): orig(0,0,0), dir(0,0,0){}; 
        Ray(const Vec& origin, const Vec& direction)
            : orig(origin), dir(direction)
        {}

        Vec origin() const  { return orig; }
        Vec direction() const { return dir; }

        Vec at(float t) const {
            return orig + t*dir;
        }

        float getX(){
        return abs(dir.getX() - orig.getX());
        }

        float getY(){
        return abs(dir.getY()- orig.getY());
        }

        float getZ(){
        return dir.getZ()- orig.getZ();
        }

        
};



#endif //! RAY_H