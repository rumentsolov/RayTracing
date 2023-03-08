#include "publics.h"
#include "files.h"
#include "matrix.h"
#include "generateCubes.h"

int main() {
	
	int totalCubes = 9;

	openFile();

	Matrix *ptr;

	ptr = new Matrix(iWidth,iHeight,"0 0 0\t");

	generateCubes(*ptr);

	ppmFS << *ptr;

	
	closeFile();

    delete ptr;

	return 0;
}
