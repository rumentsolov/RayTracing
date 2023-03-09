#include "publics.h"
#include "matrix.h"
#include "getSquares.h"


int main() {

    iWidth = 1920;
    iHeight = 1080;
    squares = 32;


    Matrix matrix;

    getSquares(matrix);


    matrix.record();
    //matrix.print();

	return 0;
}
