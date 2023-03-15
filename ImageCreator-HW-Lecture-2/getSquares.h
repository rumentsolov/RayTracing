#pragma once
#include "publics.h"

#include "matrix.h"
#include "randoms.h"
#include <cmath>
#include "point.h"

//! Splits the matrix into squares/areas
//! Every square is filled with colors by Matrix.draw() function

void getSquares( Matrix &matrix){

    //! Starts from the left top corner
    int stepByX = imageX/squaresX;         // The step by X axis
    int stepByY = imageY/squaresY;         // The step by Y axis

    //! Starts from the left top corner
    start.setX(0);  
    start.setY(0);  

    //! The end of the first Matrix.draw() function is just the step itself
    end.setX(stepByX);
    end.setY(stepByY);

    PixelColor color;

    //! Iteration true the squares in the image and calling draw() function for every square
    for( int y = 0; y < squaresY; y++ ){
            start.setX(0);
            end.setX(stepByX);
            for( int x = 0; x < squaresX; x++ ){
                        color = getRandNum();
                        matrix.draw(color);
                        start.addX(stepByX);
                        end.addX(stepByX);
            }
            start.addY(stepByY);
            end.addY(stepByY);
    }
}