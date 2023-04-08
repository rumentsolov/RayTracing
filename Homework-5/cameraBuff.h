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

public:
    int imageX;                                 // the size of the image by X axis
    int imageY;                                 // the size of the image by Y axis
    float colorCoefficient;
    std::string fileName = "homework-4.ppm";//the image name
    PixelColor** str;

    CameraBuff(int imageX_, int imageY_) : imageX(imageX_), imageY(imageY_) , str( new PixelColor*[imageX])
    {

    Vec origin(0);
    Vec focalVec(0,0,-200); // distance from origin to image
    Vec topLeftImageCornerVec(origin.x - imageX/2,origin.y +imageY/2,focalVec.z); 

    float originX = focalVec.x;
    float originY = focalVec.y;
    float originZ = focalVec.z;

    int coef = 10;

    Triangle t(
    Vec(-imageX/coef, -imageX/coef, -imageX/coef),
    Vec( imageX/coef, -imageX/coef, -imageX/coef),
    Vec( 0,  imageX/coef, -imageX/coef));

    //! Colors should change between 0 and 255 so we need that coefficient to split the color step true all the pixels
    //colorCoefficient = 254.99999/(topLeftImageCornerVec.length() - focalVec.length()); // case whole image
    colorCoefficient = 254.99999/(t.AB.length());

        for (int x = 0; x < imageX; x++) str[x] = new PixelColor[imageY]; //  Allocates memory for rows

        // Fills the CameraBuff with color according the vec length
        for (int y = 0; y < imageY; y++)
        {  
                for (int x = 0; x < imageX; x++) 
                {
                Vec vec(topLeftImageCornerVec.x + x +0.5, topLeftImageCornerVec.y - y -0.5 , topLeftImageCornerVec.z); // - y due to image y is backwards on real Y axis
                Ray raySent(origin, vec);
                PixelColor color(
                        (originX - abs(vec.x))*colorCoefficient , 
                        (originY - abs(vec.y))*colorCoefficient , 
                        abs(vec.z)); 
                //vec.normalize(); // No need to normalize it
                bool intersect = rayIntersectionCheck(raySent ,t );
                str[x][y] = PixelColor(0);
                intersect == true ? str[x][y] = color : PixelColor(255) ;
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