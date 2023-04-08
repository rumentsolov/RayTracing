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

    Triangle t(
    Vec(-1.75, -1.75, -3),
    Vec( 1.75, -1.75, -3),
    Vec( 0, 1.75, -3)
    );
    
    Triangle arrShapes [1] = {} ;

    CameraBuff buff(imageX, imageY , origin, focalVec, t);
    buff.record(); 



	return 0;
}