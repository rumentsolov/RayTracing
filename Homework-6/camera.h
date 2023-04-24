#include "vec.h"

class Camera {
public:
Vec origin;
Vec imgResolution;
Vec forwardVec; // distance from origin to image
Vec topLeftImageCornerVec; 

Camera() : origin(0), forwardVec(0){}

Camera(Vec origin_, Vec forwardVec_ , Vec imgResolution_ ) : 
origin(origin_), 
forwardVec(forwardVec_) , 
imgResolution(imgResolution_),
topLeftImageCornerVec(origin.x - imgResolution.x/2,origin.y +imgResolution.y/2,forwardVec.z)
{

}

void cameraTruck(){};
void cameraPiedestal(){};



    /*
public :
    void truck(const Vec & moveDir) { // moving camer left || right direction
    const Vec moveDirInWorldSpace = moveDir * rotationMatrix;
    position += moveDirInWorldSpace;
    }

    void pan(const float degs){
        const float rads = degs * (pi/180.f);
        const Matrix rotateAround{
            cosf(rads), 0.f , sinf(rads),
            0.f, 1.f, 0.f,
            sinf(rads), 0.f, cosf(rads),
        };
        rotationMatrix = rotationMatrix * rotateAroundY; // we are saving the original direction and multiply it => Ray direction = Ray direction * Camera Rotation matrix
    }

    private:
    // Each row holds the direction of the rotate unit of the camera local coordinate system
    Matrix RotationMatrix;
    Vec position;*/
};
