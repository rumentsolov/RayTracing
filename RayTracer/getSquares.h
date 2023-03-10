#pragma once
#include "publics.h"

#include "matrix.h"
#include "randoms.h"
#include <cmath>
#include "point.h"

void getSquares( Matrix &matrix){

    int boxesInAxis = sqrt(squares);

    int movementX = imageX/boxesInAxis;
    int movementY = imageY/boxesInAxis;

    start.setX(0);
    start.setY(0);

    end.setX(movementX);
    end.setY(movementY);

    std::string color;

    for( int j = 0; j < boxesInAxis; j++ ){
            start.setX(0);
            end.setX(movementX);
            for( int i = 0; i < boxesInAxis; i++ ){
                        color = getRandNum();
                        matrix.draw(color);
                        start.addX(movementX);
                        end.addX(movementX);
            }
            start.addY(movementY);
            end.addY(movementY);
    }
}