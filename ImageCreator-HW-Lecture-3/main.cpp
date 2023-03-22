#include "CameraBuff.h"
#include "rendering.h"

int main() {

    //! The algorithm generates ppm image filled with squares with different colors and a circle in the center of the image
    //! All user inputs are in image PIXELS

    // The size of the image by X axis
    int imageX = 600; 

    // The size of the image by Y axis
    int imageY = 300;

    CameraBuff buff(imageX, imageY);

    // The radius of the circle that user wants to be drawn
    int radius = 300 ; 

    Rendering(buff, imageX , imageY ); // Fills the image buffer fields with random colors by squares

    buff.record(); // Records the image buffer to a ppm file

	return 0;
}