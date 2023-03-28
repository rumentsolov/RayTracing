#ifndef VEC_H
#define VEC_H

#include <cmath>

struct Vec {
    float x;
    float y;
    float z;

    Vec(): x(0.0), y(0.0) , z(0.0){}; 
    Vec( float XX): x(XX), y(XX) , z(XX){}; 
    Vec( float x_, float y_ , float z_ ): x(x_), y(y_), z(z_) {};

        Vec operator + (const Vec &v) const
        { return Vec(x + v.x, y + v.y, z + v.z); }

        Vec operator - (const Vec &v) const
        { return Vec(x - v.x, y - v.y, z - v.z); }

        Vec operator - () const
        { return Vec(-x, -y, -z); }

        Vec operator * (const float &r) const
        { return Vec(x * r, y * r, z * r); }

        Vec& operator /= (const float &r)
        { x /= r, y /= r, z /= r; return *this; }

        Vec& operator *= (const float &r)
        { x *= r, y *= r, z *= r; return *this; }

        Vec& operator+=(const Vec &other) {
            this->x += other.x ;
            this->y += other.y ;
            this->y += other.z ;
            return *this;
        }

        Vec& operator = (const Vec &other) {
        this->x = other.x ;
        this->y = other.y ;
        this->y = other.z ;
        return *this;
        }

        Vec crossProduct(const Vec& B) const ;

        float dotProduct(const Vec& B) const;

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

Vec operator*(const Vec&A, const Vec&B){
    return Vec(
        A.x * B.x,
        A.y * B.y,
        A.z * B.z 
        );
}

Vec operator*(const Vec&A, float scalar){
    return Vec(
        A.x * scalar,
        A.y * scalar,
        A.z * scalar 
        );
}

Vec operator/(Vec&A,float t){
    return Vec(
        A.x * (1/t),
        A.y * (1/t),
        A.z * (1/t) );
}

Vec Vec::crossProduct(const Vec& v) const {
            return Vec{
               y * v.z - z * v.y, 
               z * v.x - x * v.z, 
               x * v.y - y * v.x
            };
}

float Vec::dotProduct(const Vec& v) const {
    return (x * v.x + y * v.y + z * v.z);
}

std::ostream & operator<<(std::ostream &ppmFS , const Vec &v) {
return ppmFS << v.x <<" "<< v.y<<" " << v.z ;
}

#endif //!VEC_H