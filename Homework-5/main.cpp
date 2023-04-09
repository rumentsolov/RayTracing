#include "cameraBuff.h"
#include "shapes.h"

int main() {
    
    //! Optimizaions I have to make:
    // 1) All object to be from type Vec ( Vertex || Point)
    // 2) Image Buff can be allocated in single Vec instead of 2D array
    // 3) PixelColor uses floats so size can be smaller ( unsigned char )
    // 4) To check for unused operator overloading function
    // 5) Ternary operator are quicker than if!!!
    
    int imageX = 650; // the size of the image by X axis
    int imageY = 560; 

    int coef = 15; // since I dont normalize vectors I use this coefficient to change colors of raytraced pixels

    Vec origin(0);
    Vec focalVec(0,0,-100); // distance from origin to image

    Triangle t1(
    Vec(1.75, -0.75, -3),
    Vec( 4.75, -0.75, -3),
    Vec( 3.5, 1.75, -3),
    PixelColor(0,255,155)
    );

    Triangle t2(
    Vec(-2.75, 0, -3),
    Vec( -1.75, 0, -3),
    Vec( -1.5, 2, -3),
    PixelColor(0,90,155)
    );
    
    int size = 2;
    Triangle arrShapes [2] = {t1, t2} ;

    CameraBuff buff(imageX, imageY , origin, focalVec, arrShapes , size);
    buff.record(); 



	return 0;
}