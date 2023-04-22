#ifndef IMG_BUFF_H
#define IMG_BUFF_H

#include "pixelColor.h"
#include "vec.h"
#include "ray.h"
#include "rayCheck.h"

#include <iostream>

//? This is the image's pixel color holder

// ! the CameraBuff should be printed from left->right && top->bottom as the image is created in the screen
class CameraBuff { 
/*


*/
public:
    int imageX;                                 // the size of the image by X axis
    int imageY;                                 // the size of the image by Y axis
    float colorCoefficient;
    Vec origin;
    Vec focalVec; // distance from origin to image
    std::string fileName = "homework-5.ppm";//the image name
    PixelColor** str;
    Triangle (&arrShapes)[];
    int size;

    CameraBuff(
        int imageX_, 
        int imageY_  , 
        Vec origin_ , 
        Vec focalVec_ , 
        Triangle (&arrShapes_)[],
        int size_ )
        :
        imageX(imageX_), 
        imageY(imageY_) , 
        origin(origin_) , 
        focalVec(focalVec_) , 
        arrShapes(arrShapes_) , 
        size(size_),
        str( new PixelColor*[imageX])
    {

    Vec topLeftImageCornerVec(origin.x - imageX/2,origin.y +imageY/2,focalVec.z); 
    bool mty; // tpo use ternary isntead of If else or debug assert
    float originX = focalVec.x;
    float originY = focalVec.y;
    float originZ = focalVec.z;

        for (int x = 0; x < imageX; x++) str[x] = new PixelColor[imageY]; //  Allocates memory for rows
        
        // Fills the CameraBuff with color according the vec length
        for (int y = 0; y < imageY; y++)
        {  
                for (int x = 0; x < imageX; x++) 
                {
                    Vec vec(
                    topLeftImageCornerVec.x + x +0.5, 
                    topLeftImageCornerVec.y - y -0.5 , 
                    topLeftImageCornerVec.z
                    ); // - y due to image y is backwards on real Y axis
                    Ray raySent(origin, vec);
                    str[x][y] = PixelColor(0);
                    for(int e = 0; e < size;e++){
                        //vec.normalize(); // No need to normalize it  
                        (rayIntersectionCheck(raySent ,arrShapes[e] ) == true )? 
                        str[x][y] = arrShapes[e].tColor : 
                        mty = false; // ternary is qiucker check than if
                        //str[x][y] = PixelColor(0);
                    }
                }
        }
    }
        void record();// the ostream record

    ~CameraBuff() {
        for (int i = 0; i < imageX; i++) {
        delete[] str[i];
        }
        delete[] str;
    };
};

void CameraBuff::record(){ // transfers the CameraBuff to the ostream
    std::ofstream ppmFS(this->fileName, std::ios::out | std::ios::binary);

    ppmFS << "P3\n" << imageX << " " << imageY << "\n" << 255 << "\n";
    
    for (int y = 0; y < imageY; y++)
        for (int x = 0; x < imageX; x++) { {
            ppmFS<< str[x][y];
        }
    ppmFS << "\n";
    }
    ppmFS.close();
}

#endif //! IMG_BUFF_H