#ifndef SCENE_H
#define SCENE_H
#include "vec.h"
#include "shapes.h"
#include "randoms.h"
#include "pixelColor.h"


//Triangle ( &Scene( Triangle (&arr)[5] ) )[5];

Triangle *Scene() {

    const int size = 8;

    Triangle hw1(
        Vec(-1.75, -1.75, -3),
        Vec( 1.75, -1.75, -3),
        Vec( 0, 1.75, -3),
        PixelColor(getRandNum())
    );

    Triangle t1(
    Vec(0, 0, -3),
    Vec( 2, 2, -3),
    Vec( 0, 7, -3),
    PixelColor(getRandNum())
    );

    Triangle t2(
        Vec(0, 7, -3),
        Vec( -2, 2, -3),
        Vec( 0, 0, -3),
        PixelColor(getRandNum())
    );

    Triangle t3(
    Vec(0, 0, -3),
    Vec( -2, -2, -3),
    Vec( 0, -7, -3),
    PixelColor(getRandNum())
    );
    

    Triangle t4(
        Vec(0, -7, -3),
        Vec( 2, -2, -3),
        Vec( 0, 0, -3),
        PixelColor(getRandNum())
    );

     Triangle t5(
        Vec(0, 0, -3),
        Vec( 2, -2, -3),
        Vec( 7, 0, -3),
        PixelColor(getRandNum())
    );

     Triangle t6(
        Vec(7, 0, -3),
        Vec( 2, 2, -3),
        Vec( 0, 0, -3),
        PixelColor(getRandNum())
    );

     Triangle t7(
        Vec(0, 0, -3),
        Vec( -2, 2, -3),
        Vec( -7, 0, -3),
        PixelColor(getRandNum())
    );

     Triangle t8(
        Vec(-7, 0, -3),
        Vec( -2, -2, -3),
        Vec( 0, 0, -3),
        PixelColor(getRandNum())
    );



    Triangle *arrShapes  = new Triangle[size]{t1,t2,t3,t4,t5,t6,t7,t8} ;

    return arrShapes ;
}


#endif //! SCENE_H