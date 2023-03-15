#pragma once
#ifndef PUBLICS_H
#define PUBLICS_H

//! Public values that my program uses to work with

#include <string>
#include <chrono>

#include "point.h"
#include "pixelColor.h"

using namespace std::chrono;

class Publics{
    public:
    int imageX;                                 // the size of the image by X axis
    int imageY;                                 // the size of the image by Y axis
    int squaresX;                               // the number of squares that user want to be drawn in X axis
    int squaresY;                               // the number of squares that user want to be drawn in Y axis
    int radius;                                 // the radius of the circle that user wants to be drawn
    const int maxColorComponent = 255;

    Publics(int imageX_, int imageY_):imageX(imageX_), imageY(imageY_) {

        PixelColor colorBlack(0,0,0);
        const std::string fileName = 
        "the_image.ppm";                         // the image name

        Point start(0,0);                        // starting point where the matrix draw functions starts
        Point end(0,0);                          // ending point where the matrix draw functions ends

        auto startTime = high_resolution_clock::now(); // starts the clock // netter here than inside main.cpp
    }

    void setSquares(const int &squaresX_,const int &squaresY_ ){ 
        this->squaresX = squaresX_;
        this->squaresY = squaresY_;
    }

    void setRadius(const int &radius_){ 
        this->radius = radius;
    }

   }

#endif