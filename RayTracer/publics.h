#pragma once
#ifndef PUBLICS_H
#define PUBLICS_H

#include <string>
#include "point.h"

int imageX;
int imageY;
int squares;


int radius;

int counter=0;
int squaresCreated = 0;

static const int maxColorComponent = 255;

static const int totalCubes = 9;

static const std::string fileName = "the_image.ppm";

Point start(0,0);
Point end(0,0);

#endif