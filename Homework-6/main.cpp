#include "cameraBuff.h"
#include "shapes.h"
#include "randoms.h"

#include <chrono>

using namespace std::chrono;

int main() {
    
    auto start = high_resolution_clock::now(); // I measure the time for completion of the program with the idea to optimise it

    //! Optimizaions I have to make:
    // 1) Calculate triangle normals in Triangle class
    
     std::string fileName = "homework-6.ppm";
    Vec resolution(1000,1000,0);
    Vec origin(0);
    Vec focalVec(0,0,-100); // distance from origin to image

    Triangle hw1(
        Vec(-1.75, -1.75, -3),
        Vec( 1.75, -1.75, -3),
        Vec( 0, 1.75, -3),
        PixelColor(getRandNum())
    );

    Triangle t1(
    Vec(0, 0, -3),
    Vec( 2, 2, -3),
    Vec( 0, 7, -3),
    PixelColor(getRandNum())
    );

    Triangle t2(
        Vec(0, 7, -3),
        Vec( -2, 2, -3),
        Vec( 0, 0, -3),
        PixelColor(getRandNum())
    );

    Triangle t3(
    Vec(0, 0, -3),
    Vec( -2, -2, -3),
    Vec( 0, -7, -3),
    PixelColor(getRandNum())
    );
    

    Triangle t4(
        Vec(0, -7, -3),
        Vec( 2, -2, -3),
        Vec( 0, 0, -3),
        PixelColor(getRandNum())
    );

     Triangle t5(
        Vec(0, 0, -3),
        Vec( 2, -2, -3),
        Vec( 7, 0, -3),
        PixelColor(getRandNum())
    );

     Triangle t6(
        Vec(7, 0, -3),
        Vec( 2, 2, -3),
        Vec( 0, 0, -3),
        PixelColor(getRandNum())
    );

     Triangle t7(
        Vec(0, 0, -3),
        Vec( -2, 2, -3),
        Vec( -7, 0, -3),
        PixelColor(getRandNum())
    );

     Triangle t8(
        Vec(-7, 0, -3),
        Vec( -2, -2, -3),
        Vec( 0, 0, -3),
        PixelColor(getRandNum())
    );

    const int size = 8;
    Triangle arrShapes [size] = {t1,t2,t3,t4,t5,t6,t7,t8} ;

    Camera camera1( origin, focalVec , resolution);

    CameraBuff buff(fileName, camera1, arrShapes , size);
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