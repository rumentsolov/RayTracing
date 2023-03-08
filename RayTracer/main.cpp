#include "publics.h"
#include "files.h"
#include "matrix.h"

int main() {
	

	Matrix *ptr;

	std::string sum = "0 255 255\t";

	ptr = new Matrix(iWidth,iHeight,sum);

	openFile();

	ppmFS << *ptr;
	
	closeFile();

    delete ptr;

	return 0;
}
