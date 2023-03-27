#ifndef VEC_H
#define VEC_H

#include <cmath>

 constexpr float kEpsilon = 1e-8;

class Vec {
public:
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

        Vec operator * (const Vec &v) const
        { return Vec(x * v.x, y * v.y, z * v.z); }

        //const int& operator [] (uint8_t i) const { return (&x)[i]; }

        //int& operator [] (uint8_t i) { return (&x)[i]; }

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




        Vec cross(const Vec& B) const ;

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


Vec Vec::cross(const Vec& v) const {
            return Vec{
               y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x
            };
        }

float Vec::dotProduct(const Vec& v) const {
    return (x * v.x + y * v.y + z * v.z);
}

bool rayTriangleIntersect(
    const Vec &orig, 
    const Vec &vec,
    const Vec &A,
    const Vec &B, 
    const Vec &C,
    float &t, 
    float &u, 
    float &v
    )
    {

        Vec AB = B - A;
        Vec AC = C - A;
        Vec pvec = vec.cross(AC);
        float det = AB.dotProduct(pvec);

        // if the determinant is negative the triangle is backfacing

        // if the determinant is close to 0, the ray misses the triangle
        if (det < kEpsilon) return false;

        // ray and triangle are parallel if det is close to 0
        if (fabs(det) < kEpsilon) return false;

        float invDet = 1 / det;

        Vec tvec = orig - A;
        u = tvec.dotProduct(pvec) * invDet;
        if (u < 0 || u > 1) return false;

        Vec qvec = tvec.cross(AB);
        v = vec.dotProduct(qvec) * invDet;
        if (v < 0 || u + v > 1) return false;
        
        t = AC.dotProduct(qvec) * invDet;

        Vec N = AB.cross(AC); // N
        float denom = N.dotProduct(N);
        
        // Step 1: finding P
        
        // check if ray and plane are parallel ?
        float NdotRayDirection = N.dotProduct(vec);

        if (fabs(NdotRayDirection) < kEpsilon) // almost 0
            return false; // they are parallel so they don't intersect ! 

        // compute d parameter using equation 2
        float d = -N.dotProduct(A);
        
        // compute t (equation 3)
        t = -(N.dotProduct(orig) + d) / NdotRayDirection;
        
        // check if the triangle is in behind the ray
        if (t < 0) return false; // the triangle is behind
    
        // compute the intersection point using equation 1
        Vec P = orig + t * vec;
    
        // Step 2: inside-outside test
        Vec Q; // vector perpendicular to triangle's plane
    
        // edge 0
        Vec edge0 = B - A; 
        Vec vp0 = P - A;
        Q = edge0.cross(vp0);
        if (N.dotProduct(Q) < 0) return false; // P is on the right side
    
        // edge 1
        Vec edge1 = C - B; 
        Vec vp1 = P - B;
        Q = edge1.cross(vp1);
        if ((u = N.dotProduct(Q)) < 0)  return false; // P is on the right side
    
        // edge 2
        Vec edge2 = A - C; 
        Vec vp2 = P - C;
        Q = edge2.cross(vp2);
        if ((v = N.dotProduct(Q)) < 0) return false; // P is on the right side;

        u /= denom;
        v /= denom;
        
        return true; // this ray hits the triangle
    }


#endif //!VEC_H
