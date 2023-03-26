#ifndef VEC_H
#define VEC_H

#include <cmath>

constexpr float kEpsilon = 1e-8;

class Vec {

    float x;
    float y;
    float z;

    public:
    Vec(): x(0.0), y(0.0) , z(0.0){}; 
    Vec( float XX): x(XX), y(XX) , z(XX){}; 
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


        Vec operator-() const { return Vec(-X(), -Y(), -Z()); }
        
        Vec& operator+=(const Vec &other) {
            setX(other.X()) ;
            setY(other.Y()) ;
            setZ(other.Z()) ;
            return *this;
        }

        Vec& operator = (const Vec &B) {
        setX(B.X()),
        setY(B.Y()),
        setZ(B.Z());
        return *this;
        }

        Vec cross(const Vec& B) const ;

        float dotProduct(const Vec& B) const;

        bool rayIntersectsTriangle(
        const Vec &orig, 
        const Vec &vec,
        const Vec &A,
        const Vec &B,
        const Vec &C,
        float &t, 
        float &u, 
        float &v);

        float norm() const
        { return x * x + y * y + z * z; }

        Vec& normalize()
        {
            float n = norm();
            if (n > 0) {
                float factor = 1 / sqrt(n);
                x *= factor, y *= factor, z *= factor;
            }
            
            return *this;
        }

        float length() {
            return sqrt(norm());
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

Vec operator*(const Vec&A, float scalar){
    return Vec(
        A.X() * scalar,
        A.Y() * scalar,
        A.Z() * scalar 
        );
}

Vec operator/(Vec&A,float t){
    return Vec(
        A.X() * (1/t),
        A.Y() * (1/t),
        A.Z() * (1/t) );
}


Vec Vec::cross(const Vec& B) const {
            return Vec{
                Y() * B.Z() - Z() *B.Y() ,
                Z() * B.X() - X() *B.Z() ,
                X() * B.Y() - Y() *B.X()
            };
        }

float Vec::dotProduct(const Vec& B) const {
    return (X() * B.X() + Y() * B.Y() + Z() * B.Z());
}

bool rayTriangleIntersect(
    const Vec &orig, const Vec &dir,
    const Vec &v0, const Vec &v1, const Vec &v2,
    float &t, float &u, float &v)
{



    return true;
}


#endif //!VEC_H
