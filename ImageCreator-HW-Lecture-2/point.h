#ifndef POINT_H
#define POINT_H

#include "publics.h"
#include <fstream>

//! The class point makes my life easier & provides quicker access to any point in the matrix
struct Point{ 
    int x;
    int y;
    std::string value;
    Point( int x_, int y_ ): x(x_), y(y_) {};
    int const getX() const{ return x;}
    int const getY() const { return y;}
    void setX(int x_) { this->x = x_;}
    void setY(int y_) { this->y = y_;}
    void addX(int x_) { this->x += x_;} // || operator +
    void addY(int y_) { this->y += y_;} // || operator +
    std::string getValue() { return value;}
};

#endif