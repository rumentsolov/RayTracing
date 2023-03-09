#ifndef MATRIX_H
#define MATRIX_H

#include "publics.h"


class Matrix{

public:

    std::string** str;
    
    Matrix(){
         // iHeight // iWidth // i
        str = new std::string*[iHeight];

        for (int i = 0; i < iHeight; i++) {
            str[i] = new std::string[iWidth]; // Declare a memory block of size n
        }

        for (int i = 0; i < iHeight; i++) {
            for (int j = 0; j < iWidth; j++) {
                str[i][j] = "000 000 000  ";
                //str[i][j] = "--- --- --- ";
            }
        }
    }

        void print(){
            for (int i = 0; i < iHeight; i++) {
                for (int j = 0; j < iWidth; j++) {
                    std::cout << str[i][j];
                }
            std::cout << std::endl;
            }
        }
        


        void change(const int startHeight, const int startWigth , const int endHeight, const int endWigth, const std::string & put){
            for (int i = 0; i < iHeight; i++) {
                for (int j = 0; j < iWidth; j++) {

                if( 
                    i>=startHeight && 
                    j>=startWigth && 
                    i<endHeight && 
                    j<endWigth)

                    str[i][j] = put;
                }
            }
        }
        
         void record(){

            std::ofstream ppmFS(fileName, std::ios::out | std::ios::binary);

            ppmFS << "P3\n" << iWidth << " " << iHeight << "\n" << maxColorComponent << "\n";
            
            for (int i = 0; i < iHeight; i++) {
                for (int j = 0; j < iWidth; j++) {
                    ppmFS<< str[i][j];
                }
            ppmFS << "\n";
            }
            
            ppmFS.close();
        }
      
};

#endif