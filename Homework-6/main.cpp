#include "imageBuff.h"
#include "scene.h"
#include "render.h"
#include <chrono>

using namespace std::chrono;

int main() {
    
    auto start = high_resolution_clock::now(); // I measure the time for completion of the program with the idea to optimise it

    //! Optimizaions I have to make:
    // 1) Calculate triangle normals in Triangle class
    
    int imageX = 1000; // the size of the image by X axis
    int imageY = 1000; 
    std::string fileName = "homework-6.ppm";//the image name

    Triangle * arr = Scene();
    ImageBuff buff(imageX, imageY , fileName);
    renderImage(imageX, imageY, arr , buff );

    buff.record(); 

    // Below are some measurements info :
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout.setf(std::ios::fixed);
    std::cout.precision(3);
    std::cout << "Completed in: "
        << duration.count()*0.000001 << " seconds" << std::endl;

	return 0;
}