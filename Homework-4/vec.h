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

    float const X() const{ return x;}
    float const Y() const { return y;}
    float const Z() const { return z;}

    void setX(float x_) { this->x = x_;}
    void setY(float y_) { this->y = y_;}
    void setZ(float y_) { this->y = y_;}

    void addX(float x_) { this->x += x_;}
    void addY(float y_) { this->y += y_;}
    void addZ(float z_) { this->z += z_;}

    float powX() { return x*x;}
    float powY() { return y*y;}
    float powZ() { return z*z;}


        float length() {
            return sqrt(powX() + powY() + powZ());
        }
    
        Vec operator-() const { return Vec(-X(), -Y(), -Z()); }
        
        Vec& operator+=(const Vec &other) {
            setX(other.X()) ;
            setY(other.Y()) ;
            setZ(other.Z()) ;
            return *this;
        }

        Vec& operator*(float scalar){
        setX(X()*scalar) ;
        setY(Y()*scalar) ;
        setZ(Z()*scalar) ;
        return *this;
        }


        Vec& operator/=(const float t) {
        return *this * (1/t);
        }

        Vec& operator = (Vec B) {
        setX(B.X()),
        setY(B.Y()),
        setZ(B.Z());
        return *this;
        }

        Vec cross(const Vec& B) const {
            return Vec{
                Y() * B.Z() - Z() *B.Y() ,
                Z() * B.X() + X() *B.Z() ,
                X() * B.Y() + Y() *B.X()
            };
        }
};

Vec operator+(const Vec&A, const Vec&B){
        return Vec(
        A.X() + B.X(),
        A.Y() + B.Y(),
        A.Z() + B.Z() );
}

Vec operator-(const Vec&A, const Vec&B){
    return Vec(
        A.X() - B.X(),
        A.Y() - B.Y(),
        A.Z() - B.Z() );
}

Vec operator*(const Vec&A, const Vec&B){
    return Vec(

        A.X() * B.X(),
        A.Y() * B.Y(),
        A.Z() * B.Z() 

        );
}

Vec operator/(Vec&A,float t){
    return Vec(
        A.X() * (1/t),
        A.Y() * (1/t),
        A.Z() * (1/t) );
}



#endif //!VEC_H
