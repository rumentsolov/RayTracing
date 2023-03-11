#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//? since the program works very quick, different random numbers generation is real nigthmare without the code below
int randInt(){ 
    int randNum ;
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    srand((time_t)ts.tv_nsec); //! using nano-seconds instead of seconds 
    randNum = rand()%1000;
    while(randNum >= maxColorComponent) randNum -= maxColorComponent; // this limits the random number generation , 250
    return randNum;
}

//? generates random numbers every time software aks for it
std::string getRandNum(){ 

    int firstInt = randInt();
    int secondInt  = randInt();
    int thirdInt  = randInt();

    std::string firstString = std::to_string(firstInt);
    while(firstString.size() < 3) firstString.insert(0,"0");

    std::string secondString = std::to_string(secondInt);
    while(secondString.size() < 3) secondString.insert(0,"0");

    std::string thirdString = std::to_string(thirdInt);
    while(thirdString.size() < 3) thirdString.insert(0,"0");

    std::string color = firstString + " " + secondString + " " + thirdString + "\t"; //
    return color;
}