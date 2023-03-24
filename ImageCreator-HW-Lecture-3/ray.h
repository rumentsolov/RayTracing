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

        float getX(){
        return abs(dir.getX());
        }

        float getY(){
        return abs(dir.getY() );
        }

        float getZ(){
        return abs(dir.getZ() );
        }

        
};



#endif //! RAY_H