#ifndef PIXELCOLOR_H
#define PIXELCOLOR_H

#include <fstream>

struct PixelColor {
    unsigned char first;
    unsigned char second;
    unsigned char third;
    PixelColor():first(0), second(0), third(0) {}
    PixelColor(unsigned char  first_ ) : first(first_), second(first_), third(first_) {}
    PixelColor(unsigned char  first_ ,unsigned char  second_ , unsigned char  third_) : first(first_), second(second_), third(third_) {}
    //~PixelColor() {}

    PixelColor &operator=(const PixelColor other){
        this->first = other.first;
        this->second = other.second;
        this->third = other.third;
        return *this;
    }
};

    std::ostream & operator<<(std::ostream &ppmFS , const PixelColor &x){
    return ppmFS << (int)x.first <<" "<< (int)x.second<<" " << (int)x.third<< "\n";
    }

     //! For shading
    PixelColor operator+(const PixelColor&first, const PixelColor&second){
    return PixelColor(
        first.first - second.first,
        first.second - second.second,
        first.third - second.third );
    }


    PixelColor X(const PixelColor&some,int x){
    return PixelColor(
    some.first + x,
    some.second ,
    some.third);
    }

    PixelColor Y(const PixelColor&some,int y){
    return PixelColor(
    some.first,
    some.second + y,
    some.third);
    }

    PixelColor Z(const PixelColor&some,int z){
    return PixelColor(
    some.first,
    some.second,
    some.third + z);
    }
    
#endif //! PIXELCOLOR_H