#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//? since the program works very quick, different random numbers generation is real nigthmare without the code below
int randInt(){ 
    int randNum ;
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    srand((time_t)ts.tv_nsec); //! using nano-seconds instead of seconds 
    randNum = rand()%maxColorComponent; 
    return randNum;
}

//? generates random numbers every time software aks for it
std::string getRandNum(){ 

    int firstInt = randInt();
    int secondInt  = randInt();
    int thirdInt  = randInt();

    std::string color = std::to_string(firstInt) + " " + std::to_string(secondInt) + " " + std::to_string(thirdInt) + "\t"; //
    return color;
}