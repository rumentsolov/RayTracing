#ifndef IMG_BUFF_H
#define IMG_BUFF_H

#include "pixelColor.h"
#include "vec.h"
#include "ray.h"

#include <iostream>



float deg2rad(const float &deg)
{ return deg * M_PI / 180; }

//? This is the image's pixel color holder

// ! the CameraBuff should be printed from left->right && top->bottom as the image is created in the screen
class CameraBuff : public Vec , public PixelColor{ 

public:
    int imageX;                                 // the size of the image by X axis
    int imageY;                                 // the size of the image by Y axis
    float colorCoefficient;
    std::string fileName = "the_image.ppm";//the image name
    PixelColor** str;

    CameraBuff(int imageX_, int imageY_) : imageX(imageX_), imageY(imageY_) , str( new PixelColor*[imageX])
    {

    Vec origin(0,0,0);
    Vec focalVec(0,0,-500);
    Vec topLeftImageCornerVec(origin.X() - imageX/2,origin.Y() +imageY/2,focalVec.Z()); 
    //! Colors should change between 0 and 255 so we need that coefficient to split the color step true all the pixels
    colorCoefficient = 254.99999/(topLeftImageCornerVec.length() - focalVec.length());
    std::cout << "Color coefficient :" << colorCoefficient << std::endl; //! focalVec is the smalles vector always

    float originX = focalVec.X();
    float originY = focalVec.Y();
    float originZ = focalVec.Z();
    Vec a( 0, 175, -30 ); 
    Vec b( -175, -175, -30 );
    Vec c( 175, -175, -30 );

    float fov = 51.52;
    float scale = tan(deg2rad(fov * 0.5));
    float imageAspectRatio = imageX / (float)imageY;

    std::cout << "scale: " << scale << std::endl;

    std::cout << "AsepectRatio: " << imageAspectRatio << std::endl;

        for (int x = 0; x < imageX; x++) str[x] = new PixelColor[imageY]; //  Allocates memory for rows
        

        // Fills the CameraBuff with color according the vec length
        for (int y = 0; y < imageY; y++)
        {  
            for (int x = 0; x < imageX; x++) 
            {

            float X = (2 * (x + 0.5) / (float)imageX - 1) * imageAspectRatio * scale;
            float Y = (1 - 2 * (y + 0.5) / (float)imageY) * scale;
            
            //std::cout << X << " " << Y << std::endl;

            Vec dir(X, Y, focalVec.Z());
            //dir.normalize();
            float t, u, v;

             Vec vec(topLeftImageCornerVec.X() + x , topLeftImageCornerVec.Y() - y , topLeftImageCornerVec.Z()); // - y due to image y is backwards
            
            //vec.normalize();

            bool intersect = rayIntersectsTriangle(origin,vec ,a,b,c ,t, u, v);
            
            PixelColor color(
                    (originX - abs(vec.X()))*colorCoefficient , 
                    (originY - abs(vec.Y()))*colorCoefficient , 
                    abs(vec.Z())); 

                    str[x][y] = color;

            if(intersect) str[x][y] = PixelColor( 255 , 255 , 255);
            }
        }
    }
        void record();                     // the ostream record

    ~CameraBuff() {
        for (int i = 0; i < imageX; i++) {
        delete[] str[i];
        }
        delete[] str;
    };
};

//! VS Code with G++ & linux get angry when I place the code bellow in CameraBuff.cpp where should stands :(
    
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