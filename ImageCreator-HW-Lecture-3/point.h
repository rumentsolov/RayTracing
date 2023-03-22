#ifndef POINT_H
#define POINT_H

class Point{
    float x;
    float y;
    float z;

    public:
    Point(): x(0), y(0) , z(0){}; 
    Point( float x_, float y_ , float z_ ): x(x_), y(y_), z(z_) {};

    float const getX() const{ return x;}
    float const getY() const { return y;}
    float const getZ() const { return z;}

    void setX(float x_) { this->x = x_;}
    void setY(float y_) { this->y = y_;}
    void setZ(float y_) { this->y = y_;}

    void addX(float x_) { this->x += x_;}
    void addY(float y_) { this->y += y_;}
    void addZ(float z_) { this->z += z_;}

    void multiplicateX(float x_) { this->x *= x_;}
    void multiplicateY(float y_) { this->y *= y_;}
    void multiplicateZ(float z_) { this->z *= z_;}

    float sqrtX() { return x*x;}
    float sqrtY() { return y*y;}
    float sqrtZ() { return z*z;}
};

#endif //! POINT_H