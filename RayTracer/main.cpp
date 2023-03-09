#include "publics.h"
#include "files.h"
#include "matrix.h"

#include "generateCubes.h"


int main() {

    Matrix matrix;


    std::string changed = "9 9 9  ";

    matrix.change(1 , 1 , 4 , 4, changed);

    matrix.print();

	openFile();

	//Matrix *ptr;
	//ptr = new Matrix(iWidth,iHeight,"- - -\t");
	//ppmFS << *ptr;

	
	closeFile();

	return 0;
}
