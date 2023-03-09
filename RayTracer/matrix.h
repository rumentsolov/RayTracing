#ifndef MATRIX_H
#define MATRIX_H

#include "publics.h"
#include "getRand.h"

class Matrix{

public:

    std::string** str;
    
    Matrix(){
        
        str = new std::string*[iWidth];

        for (int i = 0; i < iWidth; i++) {
            str[i] = new std::string[iHeight]; // Declare a memory block of size n
        }

        for (int i = 0; i < iWidth; i++) {
            for (int j = 0; j < iHeight; j++) {
                str[i][j] = "- - -  ";
            }
        }
    }

        void print(){
            for (int i = 0; i < iWidth; i++) {
                for (int j = 0; j < iHeight; j++) {
                    std::cout << str[i][j] << " ";
                }
            std::cout << std::endl;
            }
        }
        


        void change(int startHeight, int startWigth , int endHeight, int endWigth, std::string & put){
            for (int i = 0; i < iWidth; i++) {
                for (int j = 0; j < iHeight; j++) {

                if(i>=startHeight && j>=startWigth&&i<endHeight && j<endWigth)
                    str[i][j] = put;
                }
            std::cout << std::endl;
            }
        }
        

};

#endif