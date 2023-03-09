#ifndef PROGRESS_H
#define PROGRESS_H

#include <stdlib.h>
#include "publics.h"


void getProgr(){

    system("clear");

    counter++;

    std::cout << counter << " %"<<std::endl;
}

#endif //! PROGRESS_H