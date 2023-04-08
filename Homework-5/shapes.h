#ifndef SHAPES_H
#define SHAPES_H

#include "vec.h"
#include "ray.h"

//struct Shapes {

    struct Circle {
        Vec orig;
        float radius;
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

            Triangle(): A(0,0,0), B(0,0,0), C(0,0,0){}; 
            Triangle(const Vec& A_, const Vec& B_, const Vec& C_)
                : A(A_), B(B_), C(C_){}

            Vec v0(const Vec& P) const  { return ( P - A ); }
            Vec v1(const Vec& P) const  { return ( P - B ); }
            Vec v2(const Vec& P) const  { return ( P - C ); }

    };

//};


        
#endif //! SHAPES_H