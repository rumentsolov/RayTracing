#include "publics.h"
#include <fstream>
#include <iostream>


#include "matrix.cpp"
#include "matrix.h"
#include "getSquares.h"
#include "drawCircle.h"

#include <chrono>

using namespace std::chrono;

int main() {
    auto start = high_resolution_clock::now(); // I measure the time for completion of the program with the idea to optimise it

    imageX = 1920; // < than 100k
    imageY = 1080; // < than 100k
    squares = 16 ;//imageY*imageX; // every pixel can be colored randomly /

    radius = 200;

    Matrix matrix; // I create a simple matrix to work with

    getSquares(matrix); // Fills the matrix fields with the colors

    drawCircle(matrix); // draws the circle with colors

    matrix.record(); // records the matrix to a ppm file
    //matrix.print();



    // Below are some measurements info :
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout.setf(std::ios::fixed);
    std::cout.precision(3);
    std::cout << "Completed for : "
         << duration.count()*0.000001 << " seconds" << std::endl;
	return 0;
}