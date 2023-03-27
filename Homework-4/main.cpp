#include "cameraBuff.h"

int main() {
    /*
    Optimizaions I have to make:
    1) All object to be from type Vec ( Vertex || Point)
    2) Image Buff can be allocated in single Vec instead of 2D array
    3) PixelColor uses floats so size can be smaller ( unsigned char )
    4) To check for unused operator overloading function
    */
    CameraBuff buff(620,550 );
    buff.record();
    
	return 0;
}