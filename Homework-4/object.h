#ifndef OBJECT_H
#define OBJECT_H

#include "pixelColor.h"
#include "vec.h"
#include "ray.h"

#include <iostream>

//? This is the image's pixel color holder

// ! the Object should hold the x y z coordinates, the color
class Object : public Vec , public PixelColor{ 

public:
    int x;                                 // the size of the obj by X axis
    int y;                                 // the size of the obj by Y axis
    int z;                                 // the size of the obj by Z axis

    PixelColor inputCol;

    int count;

    int*** a;

    Object(int x_, int y_, int z_, PixelColor &inputCol_) : x(x_), y(y_) , z(z_), inputCol(inputCol_)
    {
        count = 0;

        // Allocate memory blocks of size x i.e., no of 2D Arrays
        a = new int**[x];

        for (int i = 0; i < x; i++) {

            // Allocate memory blocks for rows of each 2D array
            a[i] = new int*[y];

            for (int j = 0; j < y; j++) {

                // Allocate memory blocks for columns of each 2D array
                a[i][j] = new int[z];
            }
        }

        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                for (int k = 0; k < z; k++) {

                    // Assign values to the memory blocks created
                    a[i][j][k] = ++count;
                }
            }
        }

    }

    void traverse3Darr(){
    for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                for (int k = 0; k < z; k++) {
                    //cout << a[i][j][k] << " ";
                }
                //cout << endl;
            }
           // cout << endl;
        }
    }

    ~Object() {
     for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            delete[] a[i][j];
        }
        delete[] a[i];
    }
    delete[] a;
};


#endif //! OBJECT_H