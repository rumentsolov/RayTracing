#ifndef VEC_H
#define VEC_H

#include "point.h"
#include <cmath>

class Vec : public Point{
    public:
        Point vertex;
        Vec() : vertex{0,0,0} {} 
        Vec(float x, float y, float z) : vertex{x, y, z} {}

        float length() {
            return sqrt(vertex.sqrtX() + vertex.sqrtY() + vertex.sqrtZ());
        }
    
    Vec operator-() const { return Vec(-vertex.getX(), -vertex.getY(), -vertex.getZ()); }
    
    Vec& operator+=(const Vec &other) {
            vertex.setX(other.vertex.getX()) ;
            vertex.setY(other.vertex.getY()) ;
            vertex.setZ(other.vertex.getZ()) ;
            return *this;
        }

    // to not write everywhere like ...vertex.setX()
    float const getX() const{ return vertex.x;}
    float const getY() const { return vertex.y;}
    float const getZ() const { return z;}

    void setX(float x_) { this->vertex.x = x_;}
    void setY(float y_) { this->vertex.y = y_;}
    void setZ(float y_) { this->vertex.y = y_;}

    void addX(float x_) { this->vertex.x += x_;}
    void addY(float y_) { this->vertex.y += y_;}
    void addZ(float z_) { this->vertex.z += z_;}

    void multiplicateX(float x_) { this->vertex.x *= x_;}
    void multiplicateY(float y_) { this->vertex.y *= y_;}
    void multiplicateZ(float z_) { this->vertex.z *= z_;}

    float sqrtX() { return x*x;}
    float sqrtY() { return y*y;}
    float sqrtZ() { return z*z;}
    
};

Vec operator+(const Point&first, const Vec&second){
    return Vec(
        first.getX() + second.getX(),
        first.getY() + second.getY(),
        first.getZ() + second.getZ() );
}

Vec operator+(const Vec&first, const Vec&second){
    return Vec(
        first.getX() + second.getX(),
        first.getY() + second.getY(),
        first.getZ() + second.getZ() );
}

Vec operator*(const Vec&first, const Vec&second){
    return Vec(
        first.getX() * second.getX(),
        first.getY() * second.getY(),
        first.getZ() * second.getZ() );
}

Vec operator*(float t,const Vec&first){
    return Vec(
        first.getX() * t,
        first.getY() * t,
        first.getZ() * t );
}

 Vec& operator/=(const float t) {
            return *this *= 1/t;
        }

Vec unit_vector(Vec vec) {
    return vec / vec.length();
}

#endif //!VEC_H

/*
        

       

        Vec& operator*=(const float t) {
            vertex.multiplicateX(t);
            vertex.multiplicateY(t);
            vertex.multiplicateZ(t);
            return *this;
        }

       
*/