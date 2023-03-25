#ifndef RAY_H
#define RAY_H

#include "vec.h"
#include <iostream>
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
        return r.dir.X();
        }

        int getY(const Ray &r){
        return r.dir.Y();
        }

        int getZ(const Ray &r){
        return r.dir.Z();
        }

        float getLength(const Ray &r){
            float x = r.dir.X() - r.orig.X();
            float y = r.dir.Y() - r.orig.Y();
            float z = r.dir.Z() - r.orig.Z();
            std::cout << "X:" << x << " Y:" << y << " Z:" << z << std::endl;
            return sqrt(x * x + y * y + z * z); 
        }
        
#endif //! RAY_H