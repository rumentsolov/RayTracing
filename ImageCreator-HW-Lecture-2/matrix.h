#pragma once

#ifndef ImgBuffer_H
#define ImgBuffer_H

#include "publics.h"

//? This is the image's pixel color holder

// ! the ImgBuffer should be printed from left->right && top->bottom as the image is created in the screen
class ImgBuffer :public PixelColor{ 

public:
    PixelColor** str;
    // the constructor allocates heap memory and fills it with "black color"
    ImgBuffer(){
        str = new PixelColor*[interface.imageX]; // Allocates memory for columns

        for (int x = 0; x < imageX; x++)
            str[x] = new PixelColor[imageY]; //  Allocates memory for rows
        
        // Fills the ImgBuffer with black color
        for (int y = 0; y < imageY; y++){  
            for (int x = 0; x < imageX; x++) {
            str[x][y] = colorBlack;
            }
        }
    }
        void print();                      // only for easier debugging
        void draw(const PixelColor & put); // changes the colors of the ImgBuffer
        void record();                     // the ostream record
    
    ~ImgBuffer() {
        for (int i = 0; i < imageX; i++) {
        delete[] str[i];
        }
        delete[] str;
    };
};

//! VS Code with G++ & linux get angry when I place the code bellow in ImgBuffer.cpp where should stands :(
    
void ImgBuffer::draw(const PixelColor& put){ // colors all the pixels between std::string start(x,y) and std::string end(x,y)
            for (int y = start.getY(); y < end.getY(); y++) 
                for (int x = start.getX(); x < end.getX(); x++) 
                    str[x][y] = put;
}

void ImgBuffer::record(){ // transfers the ImgBuffer to the ostream
    std::ofstream ppmFS(fileName, std::ios::out | std::ios::binary);
    ppmFS << "P3\n" << interface.imageX << " " << imageY << "\n" << maxColorComponent << "\n";
    for (int y = 0; y < imageY; y++)
        for (int x = 0; x < imageX; x++) { {
            ppmFS<< str[x][y];
        }
    ppmFS << "\n";
    }
    ppmFS.close();
}

void ImgBuffer::print(){
    for (int y = 0; y < imageY; y++){ 
        for (int x = 0; x < imageX; x++) {
            std::cout << str[x][y];
        }
    std::cout << std::endl;
    }
}

#endif