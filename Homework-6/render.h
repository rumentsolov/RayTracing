#ifndef RENDER_H
#define RENDER_H

#include "vec.h"
#include "ray.h"
#include "camera.h"
#include "scene.h"
#include "imageBuff.h"
#include "rayCheck.h"

void renderImage(int imageX,int imageY , Triangle arrShapes[], ImageBuff &buff) {
    const int size = 8;
    Vec origin(0);
    Vec forwardVec(0,0,-100); // distance from origin to image

    Camera camera (origin, forwardVec);
    Vec topLeftImageCornerVec(origin.x - imageX/2,origin.y +imageY/2,forwardVec.z);

    //Triangle (&arrShapes)[];
    //int size;

        bool mty; // tpo use ternary isntead of If else or debug assert
        // Fills the ImageBuff with color according the vec length
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
                    for(int e = 0; e < size;e++){
                        //vec.normalize(); // No need to normalize it  
                        if(rayIntersectionCheck(raySent ,arrShapes[e] ) == true ) 
                        buff.setColor( x ,y ,arrShapes[e].tColor) ; 
                        mty = false; // ternary is qiucker check than if
                    }
                }
        }

}

#endif //! RENDER_H