#include <random>
#include <string>
#include <time.h>

#include "publics.h"


std::string gen_random(const int len) {
    srand((unsigned)time(NULL));

    static const char alphanum[] =
        "0123456789" ;
        //"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        //"abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    
    return tmp_s;
}

std::string getRand(){

    std::string first = gen_random(1); //&(std::to_string(randOm));

    std::string second = gen_random(1);

    std::string third = gen_random(1);


    std::string color = first + " " + second + " " + third + "\t" ;

    return color;
}

