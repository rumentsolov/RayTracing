#ifndef MATRIX_H
#define MATRIX_H

#include "publics.h"
class Matrix{
    public:
    int rows;
    int cols;
    std::string value;

    Matrix(int rows_, int cols_, std::string value_) : rows(rows_), cols(cols_) {
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++){
                value = value_;
            }
        }
    
};

void operator<<(std::ostream &out, const Matrix &m) {

         for(int i = 0; i < m.rows; i++)
            for(int j = 0; j < m.cols; j++){
                out << m.value << ' ';
            }
        
}

#endif