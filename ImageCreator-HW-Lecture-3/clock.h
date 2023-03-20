#ifndef CLOCK_H
#define CLOCK_H

#include <iostream>
#include <chrono>

using namespace std::chrono;

//! To measure the time completion  of the program
void clockStop(high_resolution_clock::time_point &startTime) {
    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    std::cout.setf(std::ios::fixed);
    std::cout.precision(3);
    std::cout << "Completed in: "
         << duration.count()*0.000001 << " seconds" << std::endl;
}

#endif