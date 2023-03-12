#pragma once
#ifndef PUBLICS_H
#define PUBLICS_H

//! Public values that my program uses to work with

#include <string>
#include <chrono>

#include "point.h"

using namespace std::chrono;

int imageX;                                 // the size of the image by X axis
int imageY;                                 // the size of the image by Y axis
int squaresX;                               // the number of squares that user want to be drawn in X axis
int squaresY;                               // the number of squares that user want to be drawn in Y axis
int radius;                                 // the radius of the circle that user wants to be drawn

static const int maxColorComponent = 255;

std::string colorBlack = "000 000 000\t";

static const std::string fileName = 
"the_image.ppm";                            // the image name

Point start(0,0);                           // starting point where the matrix draw functions starts
Point end(0,0);                             // ending point where the matrix draw functions ends


auto startTime = high_resolution_clock::now(); // starts the clock // netter here than inside main.cpp

#endif