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

    PixelColor & operator*(unsigned char t){
            first *= t;
            second *= t;
            third *= t;
    return *this;
    }


};

    std::ostream & operator<<(std::ostream &ppmFS , PixelColor &x){
       return ppmFS << (int)x.first <<" "<< (int)x.second<<" " << (int)x.third;
    }

    PixelColor operator*(unsigned char t, const PixelColor&some){
    return PixelColor(
        t * some.first,
        t * some.second,
        t * some.third );
    }

    PixelColor operator/(const PixelColor&some,int t){
    return PixelColor(
        some.first/t,
        some.second/t,
        some.third/t );
    }

    PixelColor operator+(const PixelColor&first, const PixelColor&second){
    return PixelColor(
        first.first + second.first,
        first.second + second.second,
        first.third + second.third );
    }
    
    PixelColor addX(const PixelColor&some,int t){
    return PixelColor(
    some.first+ t,
    some.second ,
    some.third);
    }

    PixelColor addY(const PixelColor&some,int t){
    return PixelColor(
    some.first,
    some.second + t,
    some.third);
    }

    PixelColor addZ(const PixelColor&some,int t){
    return PixelColor(
    some.first,
    some.second,
    some.third+ t);
    }
    
#endif //! PIXELCOLOR_H