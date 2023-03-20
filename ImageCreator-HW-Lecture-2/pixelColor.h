#ifndef PIXELCOLOR_H
#define PIXELCOLOR_H

#include <fstream>

class PixelColor {
public:
unsigned char first;
unsigned char second;
unsigned char third;
PixelColor():first(0), second(0), third(0) {}
PixelColor(unsigned char first_ ,unsigned char second_ , unsigned char third_) : first(first_), second(second_), third(third_) {}
~PixelColor() {}

  void operator=(const PixelColor& other){
        this->first = other.first;
        this->second = other.second;
        this->third = other.third;
    }

};

    void operator<<(std::ostream &ppmFS , PixelColor &x){
        ppmFS << (int)x.first <<" "<< (int)x.second<<" " << (int)x.third;
    }
#endif