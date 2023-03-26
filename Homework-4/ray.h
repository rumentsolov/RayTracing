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
        return r.dir.x;
        }

        int getY(const Ray &r){
        return r.dir.y;
        }

        int getZ(const Ray &r){
        return r.dir.z;
        }

        float getLength(const Ray &r){
            float x = r.dir.x - r.orig.x;
            float y = r.dir.y - r.orig.y;
            float z = r.dir.z - r.orig.z;
            std::cout << "X:" << x << " Y:" << y << " Z:" << z << std::endl;
            return sqrt(x * x + y * y + z * z); 
        }
        
#endif //! RAY_H