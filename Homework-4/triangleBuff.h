#ifndef TRIANGLE_BUFF_H
#define TRIANGLE_BUFF_H

#include "object.h"
#include "pixelColor.h"
#include "vec.h"
#include "ray.h"

//? This is the image's pixel color holder

// ! the SurfaceBuff should hold the x y z coordinates, the color
class SurfaceBuff : public Object { 

public:

	int arrSize; // the size of the 3D array of points in space that we want to be considered for creation of object

    PixelColor inputCol;

    Object* buff;

    Vec A , B ,C ;

    SurfaceBuff(){}
    SurfaceBuff(
        Vec A , 
        Vec B_ , 
        Vec C_,
        PixelColor inputCol_) 
        : 
        A(A) , 
        B(B_),
        C(C_),
        inputCol(inputCol_)
        {
            //! triangle sides are represented as rays => start of the side is origin , end of the side is the direction
            Ray A1(A,B);
            Ray B1(B,C);
            Ray C1(C,A);

            //! Since a single block of memory is needed , int is better for calculating sides
            float a = getLength(A1);
            float b = getLength(B1);
            float c = getLength(C1);

            std::cout.setf(std::ios::fixed);
            std::cout.precision(13);

            std::cout << a << " " << b << " " << c << std::endl;

            float P = a + b + c;
            int S = sqrt((P*(P-a)*(P-b)*(P-c))); // heronova teorema

            std::cout << S  << std::endl;

            buff = new Object[S];

            Vec N = A.cross(B); // the resultant vector

            //! Calculating the Objects inside the triangle



        }

};


#endif //! TRIANGLE_BUFF_H