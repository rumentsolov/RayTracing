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
};

        int getX(const Ray &r){
        return r.dir.getX();
        }

        int getY(const Ray &r){
        return r.dir.getY();
        }

        int getZ(const Ray &r){
        return r.dir.getZ();
        }
        
#endif //! RAY_H