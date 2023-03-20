#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "pixelColor.h"

//? since the program works very quick, different random numbers generation is real nigthmare without the code below
int randInt(){ 
    int randNum ;
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    srand((time_t)ts.tv_nsec); //! using nano-seconds instead of seconds 
    randNum = rand()%255; 
    return randNum;
}

//? generates random numbers every time software aks for it
PixelColor getRandNum(){ 

    unsigned char first = randInt();
    unsigned char second  = randInt();
    unsigned char third  = randInt();

    PixelColor color(first,second,third);
    return color;
}