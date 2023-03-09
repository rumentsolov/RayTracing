#include <stdio.h>
#include <stdlib.h>
#include <time.h>

bool isSecond;

int randInt(){
    
    int randNum ;

    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);

    /* using nano-seconds instead of seconds */
    srand((time_t)ts.tv_nsec);

    randNum = rand()%1000;

   while(randNum > 256) randNum -= 250;

    return randNum;
}

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


    std::string color = firstString + " " + secondString + " " + thirdString + "\t "; //&(std::to_string(randOm));

    std::cout << color << std::endl;

    return color;
}