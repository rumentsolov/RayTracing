#ifndef MATRIX_H
#define MATRIX_H

#include "vec.h"

class Matrix { 

public:
Vec first;
Vec second;
Vec third;

    Matrix(){}
    Matrix(
        float a,
        float b,
        float c,
        float d,
        float e,
        float f,
        float g,
        float h,
        float i
    ){
        first  = Vec(a,b,c);
        second = Vec(d,e,f);
        third  = Vec(g,h,i);
    }


    //friend Matrix operator*(const Matrix & lhs, const Matrix & rhs);
    //friend Matrix operator*(const Vec & lhs, const Matrix & rhs);
};



#endif //! MATRIX_H