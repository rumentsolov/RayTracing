#ifndef VEC_H
#define VEC_H

#include <cmath>

class Vec {

    float x;
    float y;
    float z;

    public:
    Vec(): x(0.0), y(0.0) , z(0.0){}; 
    Vec( float x_, float y_ , float z_ ): x(x_), y(y_), z(z_) {};

    float const getX() const{ return x;}
    float const getY() const { return y;}
    float const getZ() const { return z;}

    void setX(float x_) { this->x = x_;}
    void setY(float y_) { this->y = y_;}
    void setZ(float y_) { this->y = y_;}

    void addX(float x_) { this->x += x_;}
    void addY(float y_) { this->y += y_;}
    void addZ(float z_) { this->z += z_;}

    float sqrtX() { return x*x;}
    float sqrtY() { return y*y;}
    float sqrtZ() { return z*z;}


        float length() {
            return sqrt(sqrtX() + sqrtY() + sqrtZ());
        }
    
        Vec operator-() const { return Vec(-getX(), -getY(), -getZ()); }
        
        Vec& operator+=(const Vec &other) {
            setX(other.getX()) ;
            setY(other.getY()) ;
            setZ(other.getZ()) ;
            return *this;
        }

        Vec& operator*(float t){
        setX(getX()*t) ;
        setY(getY()*t) ;
        setZ(getZ()*t) ;
        return *this;
        }


        Vec& operator/=(const float t) {
        return *this * (1/t);
        }

        Vec& operator = (Vec second) {
        setX(second.getX()),
        setY(second.getY()),
        setZ(second.getZ());
        return *this;
        }

};

Vec operator+(const Vec&first, const Vec&second){
    return Vec(
        first.getX() + second.getX(),
        first.getY() + second.getY(),
        first.getZ() + second.getZ() );
}

Vec operator-(const Vec&first, const Vec&second){
    return Vec(
        first.getX() - second.getX(),
        first.getY() - second.getY(),
        first.getZ() - second.getZ() );
}

Vec operator*(const Vec&first, const Vec&second){
    return Vec(
        first.getX() * second.getX(),
        first.getY() * second.getY(),
        first.getZ() * second.getZ() );
}

Vec operator*(float t,const Vec&someVec){
    return Vec(
        someVec.getX() * t,
        someVec.getY() * t,
        someVec.getZ() * t );
}

Vec operator/(Vec&someVec,float t){
    return Vec(
        someVec.getX() * (1/t),
        someVec.getY() * (1/t),
        someVec.getZ() * (1/t) );
}



#endif //!VEC_H
