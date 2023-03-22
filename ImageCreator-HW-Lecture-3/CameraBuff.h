#ifndef IMG_BUFF_H
#define IMG_BUFF_H

#include "pixelColor.h"
#include "rendering.h"
#include "vec.h"
#include "coordinates.h"

#include <iostream>

//? This is the image's pixel color holder

// ! the CameraBuff should be printed from left->right && top->bottom as the image is created in the screen
class CameraBuff :public PixelColor { 

public:
    int imageX;                                 // the size of the image by X axis
    int imageY;                                 // the size of the image by Y axis
    
    std::string fileName = "the_image.ppm";//the image name

    PixelColor** str;
    // the constructor allocates heap memory and fills it with "black color"

    CameraBuff(int imageX_, int imageY_) : imageX(imageX_), imageY(imageY_)
    {
        str = new PixelColor*[imageX]; // Allocates memory for columns

        for (int x = 0; x < imageX; x++)
            str[x] = new PixelColor[imageY]; //  Allocates memory for rows
        
        // Fills the CameraBuff with black color
        for (int y = 0; y < imageY; y++){  
            for (int x = 0; x < imageX; x++) {
            str[x][y] = RenderPixel(x,y);
            }
        }
    }
        void print();                      // only for easier debugging
        void draw(const Vec &start, 
        const Vec & end, 
        const PixelColor& put);            // changes the colors of the CameraBuff
        void record();                     // the ostream record

    ~CameraBuff() {
        for (int i = 0; i < imageX; i++) {
        delete[] str[i];
        }
        delete[] str;
    };
};

//! VS Code with G++ & linux get angry when I place the code bellow in CameraBuff.cpp where should stands :(
    
void CameraBuff::draw(const Vec &start, const Vec & end, const PixelColor& put){ // colors all the pixels between std::string start(x,y) and std::string end(x,y)
            for (int y = start.getY(); y < end.getY(); y++) 
                for (int x = start.getX(); x < end.getX(); x++) 
                    str[x][y] = put;
}

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

void CameraBuff::print(){
    for (int y = 0; y < imageY; y++){ 
        for (int x = 0; x < imageX; x++) {
            std::cout << str[x][y];
        }
    std::cout << std::endl;
    }
}

#endif //! IMG_BUFF_H