#ifndef RENDER_H
#define RENDER_H

#include <cmath>

#include "CameraBuff.h"

//! Splits the m into squares/areas
//! Every square is filled with colors by m.draw() function

void Rendering( CameraBuff &m , int &squaresX , int &squaresY ){


    Point start(0,0,0);                              //! Starts from the left top corner // Z is always == 0 due to camera is 2D

    //! Starts from the left top corner
    int stepByX = m.imageX/squaresX;         // The step by X axis
    int stepByY = m.imageY/squaresY;         // The step by Y axis
    Point end(stepByX,stepByY,0);              // ending point where the draw functions ends

    //! Iteration true the squares in the image and calling draw() function for every square
    for( int y = 0; y < squaresY; y++ ){
            start.setX(0);
            end.setX(stepByX);

            for( int x = 0; x < squaresX; x++ ){
                        PixelColor color('0','0','0');
                        m.draw(start,end ,color);
                        start.addX(stepByX);
                        end.addX(stepByX);
            }
            start.addY(stepByY);
            end.addY(stepByY);
    }
}

#endif //!RENDER_H