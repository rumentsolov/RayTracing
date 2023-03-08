#include "publics.h"
#include "matrix.h"
#include "getRand.h"

void generateCubes(Matrix &m){

std::string color = getRand();

    for(int i = 0; i < m.rows; i++)
            for(int j = 0; j < m.cols; j++){
                m.value = color;;
            }

}