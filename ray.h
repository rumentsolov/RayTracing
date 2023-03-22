#ifndef RAY_H
#define RAY_H

#include "vec.h"

class ray {
    public:
    Point orig;
    Vec dir;

        ray() {}
        ray(const Point& origin, const Vec& direction)
            : orig(origin), dir(direction)
        {}

        Point origin() const  { return orig; }
        Vec direction() const { return dir; }

        Point at(float t) const {
            return orig + t*dir;
        }
};

#endif