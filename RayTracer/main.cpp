#include "publics.h"
#include "matrix.h"
#include "getSquares.h"
#include "drawCircle.h"
#include <chrono>

using namespace std::chrono;

int main() {
    auto start = high_resolution_clock::now();

    imageX = 900;
    imageY = 900;
    squares = 16 ;//imageY*imageX;

    radius = 200;

    Matrix matrix;

    getSquares(matrix);

    drawCircle(matrix);

    matrix.record();
    //matrix.print();

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout.setf(std::ios::fixed);
    std::cout.precision(3);
     std::cout << "Completed for : "
         << duration.count()*0.000001 << " seconds" << std::endl;
	return 0;
}