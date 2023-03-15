#pragma once

#ifndef MATRIX_H
#define MATRIX_H

#include "publics.h"

//? This is the image's pixel color holder

// ! the matrix should be printed from left->right && top->bottom as the image is created in the screen
class Matrix :public PixelColor{ 

public:
    PixelColor** str;
    // the constructor allocates heap memory and fills it with "black color"
    Matrix(){
        str = new PixelColor*[imageX]; // Allocates memory for columns

        for (int x = 0; x < imageX; x++)
            str[x] = new PixelColor[imageY]; //  Allocates memory for rows
        
        // Fills the matrix with black color
        for (int y = 0; y < imageY; y++){  
            for (int x = 0; x < imageX; x++) {
            str[x][y] = colorBlack;
            }
        }
    }
        void print();                      // only for easier debugging
        void draw(const PixelColor & put); // changes the colors of the matrix
        void record();                     // the ostream record
};

//! VS Code with G++ & linux get angry when I place the code bellow in matrix.cpp where should stands :(
    
void Matrix::draw(const PixelColor& put){ // colors all the pixels between std::string start(x,y) and std::string end(x,y)
            for (int y = start.getY(); y < end.getY(); y++) 
                for (int x = start.getX(); x < end.getX(); x++) 
                    str[x][y] = put;
}

void Matrix::record(){ // transfers the matrix to the ostream
    std::ofstream ppmFS(fileName, std::ios::out | std::ios::binary);
    ppmFS << "P3\n" << imageX << " " << imageY << "\n" << maxColorComponent << "\n";
    for (int y = 0; y < imageY; y++)
        for (int x = 0; x < imageX; x++) { {
            ppmFS<< str[x][y];
        }
    ppmFS << "\n";
    }
    ppmFS.close();
}

void Matrix::print(){
    for (int y = 0; y < imageY; y++){ 
        for (int x = 0; x < imageX; x++) {
            std::cout << str[x][y];
        }
    std::cout << std::endl;
    }
}

#endif