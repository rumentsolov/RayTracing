#ifndef VEC3_H
#define VEC3_H

#include "point.h"
#include <cmath>

class Vec : public Point{
    public:
    Point vertex;// A 3D vector consists of 3 coordinates : x,y,z
        Vec() : vertex{0,0,0} {} 
        Vec(int vec0, int vec1, int vec2) : vertex{vec0, vec1, vec2} {}

        float length() {
            return sqrt(vertex.sqrtX() + vertex.sqrtY() + vertex.sqrtZ());
        }
    
     Vec& operator+=(const Vec &other) {
            vertex.setX(other.vertex.getX()) ;
            vertex.setY(other.vertex.getY()) ;
            vertex.setZ(other.vertex.getZ()) ;
            return *this;
        }
};

Vec operator+(const Point&first, const Vec&second){
    return Vec(
        first.getX() + second.vertex.getX(),
        first.getY() + second.vertex.getY(),
        first.getZ() + second.vertex.getZ() );
}

Vec operator+(const Vec&first, const Vec&second){
    return Vec(
        first.vertex.getX() + second.vertex.getX(),
        first.vertex.getY() + second.vertex.getY(),
        first.vertex.getZ() + second.vertex.getZ() );
}

Vec operator*(const Vec&first, const Vec&second){
    return Vec(
        first.vertex.getX() * second.vertex.getX(),
        first.vertex.getY() * second.vertex.getY(),
        first.vertex.getZ() * second.vertex.getZ() );
}

Vec operator*(float t,const Vec&first){
    return Vec(
        first.vertex.getX() * t,
        first.vertex.getY() * t,
        first.vertex.getZ() * t );
}

#endif

/*
        Vec operator-() const { return Vec(-vertex.getX(), -vertex.getY(), -vertex.getZ()); }

       

        Vec& operator*=(const float t) {
            vertex.multiplicateX(t);
            vertex.multiplicateY(t);
            vertex.multiplicateZ(t);
            return *this;
        }

        Vec& operator/=(const float t) {
            return *this *= 1/t;
        }
*/