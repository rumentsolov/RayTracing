#include "matrix.cpp"

#include "publics.h"
#include "matrix.h"
#include "getSquares.h"
#include "drawCircle.h"

int main() {

    imageX = 1920; // < than 100k
    imageY = 1080; // < than 100k
    squares = 16 ;//imageY*imageX; // every pixel can be colored randomly /

    radius = 200;

    Matrix matrix; // I create a simple matrix to work with

    getSquares(matrix); // Fills the matrix fields with the colors

    drawCircle(matrix); // draws the circle with colors

    matrix.record(); // records the matrix to a ppm file
    //matrix.print();

	return 0;
}