#include "publics.h"
#include "matrix.h"
#include "getSquares.h"
#include <chrono>

using namespace std::chrono;

int main() {
    auto start = high_resolution_clock::now();
    iWidth = 1920;
    iHeight = 1080;
    squares = 207360;

    Matrix matrix;

    getSquares(matrix);

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