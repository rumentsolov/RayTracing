#ifndef SURFACE_BUFF_H
#define SURFACE_BUFF_H

#include "object.h"
#include "pixelColor.h"
#include "vec.h"
#include "ray.h"

//? This is the image's pixel color holder

// ! the SurfaceBuff should hold the x y z coordinates, the color
class SurfaceBuff : public Object { 

public:

	int arrSize; // the size of the 3D array of points in space that we want to be considered for creation of object

    PixelColor inputCol;

    Object *points;

    Object*** buff;

    Object first , second ,third ;

    SurfaceBuff(){}
    SurfaceBuff(
        int arrSize_, // I need sufaces
        Object first_ , 
        Object second_ , 
        Object third_) 
        : 
        points(new Object[arrSize_]), // allocates memory for arrSize objects 
        first(first_) , 
        second(second_),
        third(third_)
    {
        /*
        // Allocate memory blocks of size x i.e., no of 2D Arrays
        buff = new Object**[x];

        for (int i = 0; i < x; i++) {

            // Allocate memory blocks for rows of each 2D array
            buff[i] = new Object*[y];

            for (int j = 0; j < y; j++) {

                // Allocate memory blocks for columns of each 2D array
                buff[i][j] = new Object[z];
            }
        }

        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                for (int k = 0; k < z; k++) {

                    // Assign values to the memory blocks created
                    //buff[i][j][k] = ++count;
                }
            }
        }
        */
    }
    /*
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

    ~SurfaceBuff() {
     for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            delete[] buff[i][j];
        }
        delete[] buff[i];
    }
    delete[] buff;
    }
    */
};


#endif //! SURFACE_BUFF_H