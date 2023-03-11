#pragma once
#ifndef PUBLICS_H
#define PUBLICS_H

//! Public values that my program uses to work with

#include <string>
#include "point.h"

int imageX;                                 // the size of the image by X axis
int imageY;                                 // the size of the image by Y axis
int squaresX;                               // the number of squares that user want to be drawn in X axis
int squaresY;                               // the number of squares that user want to be drawn in Y axis
int radius;                                 // the radius of the circle that user wants to be drawn

static const int maxColorComponent = 255;

std::string zeros = "000";
std::string colorBlack = zeros + " " + zeros + " " + zeros + "\t";

static const std::string fileName = 
"the_image.ppm";                            // the image name

Point start(0,0);                           // starting point where the matrix draw functions starts
Point end(0,0);                             // ending point where the matrix draw functions ends

#endif