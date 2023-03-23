#ifndef PIXELCOLOR_H
#define PIXELCOLOR_H

#include <fstream>

class PixelColor {
public:
    float first;
    float  second;
    float  third;
    PixelColor():first(0), second(0), third(0) {}
    PixelColor(float  first_ ,float  second_ , float  third_) : first(first_), second(second_), third(third_) {}
    ~PixelColor() {}

    void operator=(const PixelColor& other){
            this->first = other.first;
            this->second = other.second;
            this->third = other.third;
        }

};

    std::ostream & operator<<(std::ostream &ppmFS , PixelColor &x){
       return ppmFS << abs((int)x.first) <<" "<< abs((int)x.second)<<" " << abs((int)x.third);
    }

    PixelColor operator+(const PixelColor&first, const PixelColor&second){
    return PixelColor(
        first.first + second.first,
        first.second + second.second,
        first.third + second.third );
    }
    
    PixelColor addX(const PixelColor&some,float  t){
    return PixelColor(
    some.first - t,
    some.second ,
    some.third);
    }

    PixelColor addY(const PixelColor&some,float  t){
    return PixelColor(
    some.first,
    some.second - t,
    some.third);
    }

    PixelColor addZ(const PixelColor&some,float  t){
    return PixelColor(
    some.first,
    some.second,
    some.third+ t);
    }
    
#endif //! PIXELCOLOR_H