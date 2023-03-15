#include "publics.h"

#include "matrix.cpp"

#include "matrix.h"
#include "clock.h"
#include "getSquares.h"
#include "drawCircle.h"

int main() {

    //! The algorithm generates ppm image filled with squares with different colors and a circle in the center of the image
    //! All user inputs are in image PIXELS

    // The size of the image by X axis
    int imageX = 1920; 

    // The size of the image by Y axis
    int imageY = 1080;

    Publics interface(imageX, imageY);

    // The number of squares that user want to be drawn by X and Y axes
    // The algorithm is good enough so every pixel can be colored randomly => imageY*imageX; 
    // ! ((imageX % squaresX == 0 ) && (imageY % squaresY == 0)) => if this is false, the biggest possible size will be used and the rest of the image will be black
    int squaresX = imageX/30; 
    int squaresY = imageY/30;

    interface.setSquares(squaresX,squaresY);

    // The radius of the circle that user wants to be drawn
    int radius = 300 ; 
    interface.setRadius(radius);
    

    ImgBuffer matrix; // Create a simple buffer in the heap to work with

    getSquares(matrix); // Fills the matrix fields with random colors by squares

    drawCircle(matrix); // Draws the circle with color in the center of the image

    matrix.record(); // Records the matrix to a ppm file
    //matrix.print(); // Also console print for debugging is avalable
    
    clockStop(); // to stop the clock and to print the time completion
    
	return 0;
}