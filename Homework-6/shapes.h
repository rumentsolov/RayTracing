#ifndef SHAPES_H
#define SHAPES_H

#include "vec.h"
#include "ray.h"
#include "pixelColor.h"

//struct Shapes {

    struct Circle {
        Vec orig;
        float radius;
        PixelColor str;
        Circle(): orig(0,0,0), radius(0){}; 
        Circle(const Vec& orig_, const float& radius_)
            : orig(orig_), radius(radius_) {}
        Vec origin() const { return orig; }
        //float radius() const { return radius; }
    };
    struct Triangle {
            Vec A , B , C ;
            // calculating the vectors bellow every time when rayIntersectionCheck is called us slowing the algorithm
            Vec AB = B - A;
            Vec AC = C - A;
            Vec e0 = B - A;
            Vec e1 = C - B;
            Vec e2 = A - C;
            PixelColor tColor;
            Vec normal = AB.crossProduct(AC); // this is the triangle's normal

            Triangle(): A(0,0,0), B(0,0,0), C(0,0,0) , tColor(255){}; 
            Triangle(const Vec& A_, const Vec& B_, const Vec& C_ , const PixelColor &tColor_)
                : A(A_), B(B_), C(C_) , tColor(tColor_){}

            Vec v0(const Vec& P) const  { return ( P - A ); }
            Vec v1(const Vec& P) const  { return ( P - B ); }
            Vec v2(const Vec& P) const  { return ( P - C ); }

    };

//}; Vec normalVec = vec.crossProduct(t.AC); // this is the triangle's normal


        
#endif //! SHAPES_H