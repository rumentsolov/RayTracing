#ifndef IMG_BUFF_H
#define IMG_BUFF_H

#include "pixelColor.h"
#include <fstream>

//? This is the image's pixel color holder

// ! the ImageBuff should be printed from left->right && top->bottom as the image is created in the screen
class ImageBuff { 
public:
    int imageX;                                 // the size of the image by X axis
    int imageY;                                 // the size of the image by Y axis
    std::string fileName ;
    PixelColor** str;
    ImageBuff( int imageX_,int imageY_ ,std::string fileName_ )
        :
        imageX(imageX_), 
        imageY(imageY_) , 
        fileName(fileName_),
        str( new PixelColor*[imageX])
    {
        
        for (int x = 0; x < imageX; x++) str[x] = new PixelColor[imageY]{PixelColor(0)}; //  Allocates memory for rows
        //
        //Camera camera;
    }
        void record();// the ostream record
        void setColor(int x, int y , PixelColor newColor) {
             str[x][y] = newColor;
        };

    ~ImageBuff() {
        for (int i = 0; i < imageX; i++) {
        delete[] str[i];
        }
        delete[] str;
    };
};

void ImageBuff::record(){ // transfers the ImageBuff to the ostream
    std::ofstream ppmFS(this->fileName, std::ios::out | std::ios::binary);

    ppmFS << "P3\n" << imageX << " " << imageY << "\n" << 255 << "\n";
    
    for (int y = 0; y < imageY; y++)
        for (int x = 0; x < imageX; x++) { {
            ppmFS<< str[x][y];
        }
    }
    ppmFS.close();
}

#endif //! IMG_BUFF_H