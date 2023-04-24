#ifndef CAMERA_H
#define CAMERA_H
#include "vec.h"
#include "shapes.h"

class Camera {
public:
int imageX;                                 // the size of the image by X axis
int imageY;                                 // the size of the image by Y axis
Vec origin;
Vec forwardVec; // distance from origin to image
Vec topLeftImageCornerVec; 
Triangle (&arrShapes)[];
int size;

Camera(
    Vec origin_, 
    Vec forwardVec_ , 
    int imageX_,
    int imageY_ , 
    Triangle (&arrShapes_)[],
    int size_ )
    : 
    origin(origin_), 
    forwardVec(forwardVec_) , 
    imageX(imageX_), 
    imageY(imageY_) , 
    topLeftImageCornerVec(origin.x - imageX/2,origin.y +imageY/2,forwardVec.z),
    arrShapes(arrShapes_) , 
    size(size_)
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

/*
void Render(PixelColor** ptr, Camera &camera,int &size,Triangle (&arrShapes)[]){
        
  
}
*/
#endif //! CAMERA_H