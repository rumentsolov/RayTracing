#ifndef RAY_CHECK_H
#define RAY_CHECK_H

#include <cmath>
#include "vec.h"
#include "ray.h"
#include "shapes.h"

constexpr float kEpsilon = 1e-8;

bool rayIntersectionCheck(
    const Ray &raySent, // it has Vec origin and Vec direction as own properties
    const Triangle &t )
{
        Vec vec = raySent.direction(); // for easier access
        Vec orig = raySent.origin();

        Vec normalVec = vec.crossProduct(t.AC); // this is the triangle's normal

        //! Step 1: Comparing triangle's normal with direction
        float det = t.AB.dotProduct(normalVec);
        // if the direction is negative the triangle is backfacing

        if (det < kEpsilon || fabs(det) < kEpsilon) return false; // if the direction is negative || close to 0, the ray misses the triangle

        float invDet = 1 / det;

        Vec tvec = orig - t.A;
        Vec qvec = tvec.crossProduct(t.AB);

        float i, j, k;

        i = t.AC.dotProduct(qvec) * invDet; // distance from origin to intersection point

        j = tvec.dotProduct(normalVec) * invDet;
        if (j < 0 || j > 1) return false;
        
        k = vec.dotProduct(qvec) * invDet;
        if (k < 0 || j + k > 1) return false;
        
        //! Step 2: finding P => the point where the ray intersects the plane
        
        // check if ray and plane are parallel ?
        float NdotRayDirection = t.normalV.dotProduct(vec);

        if (fabs(NdotRayDirection) < kEpsilon) // almost 0
            return false; // they are parallel => no intersection

        float d = -t.normalV.dotProduct(t.A); // the distance from the origin to the plane (if we trace a line from the origin to the plane, parallel to the plane's normal)
        
        i = -(t.normalV.dotProduct(orig) + d) / NdotRayDirection;
        
        // check if the triangle is in behind the ray
        if (i < 0) return false; // the triangle is behind => no intersection
    
        Vec P = orig + i * vec; // intersection point

        //! Step 3: inside-outside test => checks if P Inside or Outside my Triangle
        Vec Q; // vector perpendicular to triangle's plane

        Q = t.e0.crossProduct(t.v0(P));

        if (t.normalV.dotProduct(Q) < 0) return false; // P is on the right side

        Q = t.e1.crossProduct(t.v1(P));

        if ((j = t.normalV.dotProduct(Q)) < 0)  return false; // P is on the right side
    
        Q = t.e2.crossProduct(t.v2(P));

        if ((k = t.normalV.dotProduct(Q)) < 0) return false; // P is on the right side;

        return true; // means this ray hits the triangle
}


#endif //!RAY_CHECK_H