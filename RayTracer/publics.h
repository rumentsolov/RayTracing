#ifndef PUBLICS_H
#define PUBLICS_H

#include <fstream>
#include <iostream>
#include "point.h"

int imageX;
int imageY;
int squares;

int startX;
int startY;
int endX;
int endY;

int radius;

int counter=0;
int squaresCreated = 0;

static const int maxColorComponent = 255;

static const int totalCubes = 9;

static const std::string fileName = "the_image.ppm";

Point start(startX ,startY);
Point end(endX,endY);

#endif