#include "CameraBuff.h"
#include "rendering.h"


int main() {


    // The size of the image by X axis
    int imageX = 1000; 

    // The size of the image by Y axis
    int imageY = 500;

    CameraBuff buff(imageX, imageY);


    Rendering(buff, imageX , imageY ); // Fills the image buffer fields with random colors by squares


    buff.record(); // Records the image buffer to a ppm file

	return 0;
}