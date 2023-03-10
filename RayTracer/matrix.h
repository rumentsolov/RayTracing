#ifndef MATRIX_H
#define MATRIX_H

#include "publics.h"

class Matrix{

public:
    std::string** str;
    
    Matrix(){
        str = new std::string*[imageX]; // Allocates memory for coluns

        for (int x = 0; x < imageX; x++)
            str[x] = new std::string[imageY]; //  Allocates memory for rows

        for (int y = 0; y < imageY; y++){
            for (int x = 0; x < imageX; x++) {
            //str[x][y] = "--- ";
            str[x][y] = "000 000 000  ";
            //str[x][y] = "--- --- --- ";
            }
        }
    }


        void print(){
            for (int y = 0; y < imageY; y++){
                for (int x = 0; x < imageX; x++) {
                    std::cout << str[x][y];
                }
            std::cout << std::endl;
            }

    
        }

        void draw(const std::string & put){
                    for (int y = start.getY(); y < end.getY(); y++) 
                        for (int x = start.getX(); x < end.getX(); x++) 
                            str[x][y] = put;
        }

         void drawC(const std::string & put){
            for (int y = 0; y < imageY; y++)
                for (int x = 0; x < imageX; x++) {
                    if(start.getX() < x < end.getX() && 
                    start.getY() < y < end.getY())
                    str[x][y] = put;
            }
        }
        
        void record(){

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
      
};

#endif