#include "cameraBuff.h"
#include "shapes.h"
#include "randoms.h"

int main() {
    
    //! Optimizaions I have to make:
    // 1) PixelColor to be unsigned char
    
    int imageX = 650; // the size of the image by X axis
    int imageY = 560; 

    int coef = 15; // since I dont normalize vectors I use this coefficient to change colors of raytraced pixels

    Vec origin(0);
    Vec focalVec(0,0,-100); // distance from origin to image

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


    const int size = 8;
    Triangle arrShapes [size] = {t1,t2,t3,t4,t5,t6,t7,t8} ;

    CameraBuff buff(imageX, imageY , origin, focalVec, arrShapes , size);
    buff.record(); 



	return 0;
}