#ifndef POINT_H
#define POINT_H

#include "publics.h"
#include <fstream>


struct Point{
    int x;
    int y;
    std::string value;
    Point( int x_, int y_ ): x(x_), y(y_) {};
    int const getX() const{ return x;}
    int const getY() const { return y;}
    void setX(int x_) { this->x = x_;}
    void setY(int y_) { this->y = y_;}
    void addX(int x_) { this->x += x_;}
    void addY(int y_) { this->y += y_;}
    std::string getValue() { return value;}

};

std::ostream & operator << (std::ostream & ostr, const Point & f) {
	return ostr << f.getX() << " " << f.getY();
}

/**/
bool operator < (const Point & a, const Point & b) {
	return a.getX()< b.getX();
}

#endif