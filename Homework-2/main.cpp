#include "imgBuff.h"
#include "drawSquares.h"
#include "drawCircle.h"

int main() {
     //! The algorithm generates ppm image filled with squares with different colors and a circle in the center of the image
    //! All user inputs are in image PIXELS

    // The size of the image by X axis
    int imageX = 920; 

    // The size of the image by Y axis
    int imageY = 680;

    ImgBuff buff(imageX, imageY);

    // The number of squares that user want to be drawn by X and Y axes
    // The algorithm is good enough so every pixel can be colored randomly => imageY*imageX; 
    // ! ((imageX % squaresX == 0 ) && (imageY % squaresY == 0)) => if this is false, the biggest possible size will be used and the rest of the image will be black
    int squaresX = imageX/30; 
    int squaresY = imageY/30;

    // The radius of the circle that user wants to be drawn
    int radius = 150 ; 

    drawSquares(buff, squaresX , squaresY ); // Fills the image buffer fields with random colors by squares

    drawCircle(buff , radius ); // Draws the circle with color in the center of the image

    buff.record(); // Records the image buffer to a ppm file

	return 0;
}