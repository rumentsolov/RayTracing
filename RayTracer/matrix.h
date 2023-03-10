#pragma once

#ifndef MATRIX_H
#define MATRIX_H

#include "publics.h"

class Matrix{

public:
    std::string** str;
    
    Matrix(){
        str = new std::string*[imageX]; // Allocates memory for columns

        for (int x = 0; x < imageX; x++)
            str[x] = new std::string[imageY]; //  Allocates memory for rows

        for (int y = 0; y < imageY; y++){
            for (int x = 0; x < imageX; x++) {
            str[x][y] = "000 000 000  ";
            }
        }
    }

    public:
        void print();

        void draw(const std::string & put);
        
        void record();
};

// Since I am using VS Code for linux m compiler get angre when I place the bellow in matrix.cpp where should stands :(
    
void Matrix::print(){
    for (int y = 0; y < imageY; y++){ // since i use backward matrix I start iteration from Y
        for (int x = 0; x < imageX; x++) {
            std::cout << str[x][y];
        }
    std::cout << std::endl;
    }
}

void Matrix::draw(const std::string & put){ // colors all the pixels between Point start and Point end
            for (int y = start.getY(); y < end.getY(); y++) 
                for (int x = start.getX(); x < end.getX(); x++) 
                    str[x][y] = put;
}

void Matrix::record(){ // transfers the information to the file
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

#endif