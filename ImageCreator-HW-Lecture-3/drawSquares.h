#ifndef DRAW_SQUARES_H
#define DRAW_SQUARES_H

#include <cmath>

#include "CameraBuff.h"
#include "randoms.h"
#include "point.h"

//! Splits the m into squares/areas
//! Every square is filled with colors by m.draw() function

void drawSquares( CameraBuff &m , int &squaresX , int &squaresY ){

    Point start(0,0);                              //! Starts from the left top corner

    //! Starts from the left top corner
    int stepByX = m.imageX/squaresX;         // The step by X axis
    int stepByY = m.imageY/squaresY;         // The step by Y axis

    Point end(stepByX,stepByY);              // ending point where the draw functions ends

    //! Iteration true the squares in the image and calling draw() function for every square
    for( int y = 0; y < squaresY; y++ ){
            start.setX(0);
            end.setX(stepByX);

            for( int x = 0; x < squaresX; x++ ){
                        PixelColor color = getRandNum();
                        m.draw(start,end ,color);
                        start.addX(stepByX);
                        end.addX(stepByX);
            }
            start.addY(stepByY);
            end.addY(stepByY);
    }
}

#endif