#include "publics.h"
#include "matrix.h"
#include "randoms.h"
#include <cmath>


void getSquares( Matrix &matrix){

    int boxesInAxis = sqrt(squares);

    int startX = 0;
    int movementX = iWidth/boxesInAxis;
    int endX = movementX;

    int startY = 0;
    int movementY = iHeight/boxesInAxis;
    int endY = movementY;
    


    std::string color;

    for( int j = 0; j < boxesInAxis; j++ ){
            startX =0;
            endX = movementX;

            for( int i = 0; i < boxesInAxis; i++ ){

                        color = getRandNum();
                        matrix.change(startY , startX , endY , endX, color);

                        startX += movementX;
                        endX += movementX;
            }

             startY += movementY;
             endY += movementY;  
    }
}