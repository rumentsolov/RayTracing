#include <random>
#include <string>
#include <time.h>

#include "publics.h"

std::string getRand(){

     srand(time(0));
    int first = rand() % ((maxColorComponent - 0) + 1) ;

    int second = rand() % ((maxColorComponent - 0) + 1) ;

    int third = rand() % ((maxColorComponent - 0) + 1) ;

    std::string color = std::to_string(first) + " " + std::to_string(second) + " " + std::to_string(third) + "\t" ;

    return color;
}

