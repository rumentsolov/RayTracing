#ifndef IMG_BUFF_H
#define IMG_BUFF_H

#include "pixelColor.h"
#include "vec.h"
#include "ray.h"
#include "rayCheck.h"
#include "camera.h"

#include <iostream>

//? This is the image's pixel color holder

// ! the CameraBuff should be printed from left->right && top->bottom as the image is created in the screen
class CameraBuff { 

public:
    Camera camera;
    std::string fileName;//the image name
    PixelColor** ptr;
    Triangle (&arrShapes)[];
    int size;

    CameraBuff(
        std::string fileName_,
        Camera camera_,
        Triangle (&arrShapes_)[],
        int size_ )
        :
        fileName(fileName_),
        camera(camera_) , 
        arrShapes(arrShapes_) , 
        size(size_),
        ptr( new PixelColor*[(int)camera.imgResolution.x])
    {
 
    bool mty; // tpo use ternary isntead of If else or debug assert
        for (int x = 0; x < camera.imgResolution.x; x++) ptr[x] = new PixelColor[(int)camera.imgResolution.y]{PixelColor(0)}; //  Allocates memory for rows
        
        // Fills the CameraBuff with color according the vec length
        for (int y = 0; y < camera.imgResolution.y; y++)
        {  
                for (int x = 0; x < camera.imgResolution.x; x++) 
                {
                    Vec vec(
                    camera.topLeftImageCornerVec.x + x +0.5, 
                    camera.topLeftImageCornerVec.y - y -0.5 , 
                    camera.topLeftImageCornerVec.z
                    ); // - y due to image y is backwards on real Y axis
                    Ray raySent(camera.origin, vec);
                    for(int e = 0; e < size;e++){
                        //vec.normalize(); // No need to normalize it  
                        (rayIntersectionCheck(raySent ,arrShapes[e] ) == true )? 
                        ptr[x][y] = arrShapes[e].tColor : 
                        mty = false; // ternary is qiucker check than if
                    }
                }
        }
    }
        void record();// the ostream record

    ~CameraBuff() {
        for (int i = 0; i < camera.imgResolution.x; i++) {
        delete[] ptr[i];
        }
        delete[] ptr;
    };
};

void CameraBuff::record(){ // transfers the CameraBuff to the ostream
    std::ofstream ppmFS(this->fileName, std::ios::out | std::ios::binary);

    ppmFS << "P3\n" << camera.imgResolution.x << " " << camera.imgResolution.y << "\n" << 255 << "\n";
    
    for (int y = 0; y < camera.imgResolution.y; y++)
        for (int x = 0; x < camera.imgResolution.x; x++) { {
            ppmFS<< ptr[x][y];
        }
    }
    ppmFS.close();
}

#endif //! IMG_BUFF_H