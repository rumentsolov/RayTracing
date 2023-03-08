#include "publics.h"
#include "files.h"
#include "matrix.h"

#include "generateCubes.h"


class Matrix{

    public:
    Matrix(){
        
        std::string** str = new std::string*[iWidth];

        for (int i = 0; i < iWidth; i++) {
            str[i] = new std::string[iHeight]; // Declare a memory block of size n
        }

        for (int i = 0; i < iWidth; i++) {
            for (int j = 0; j < iHeight; j++) {
                str[i][j] = "- - -  ";
            }
        }

        for (int i = 0; i < iWidth; i++) {
            for (int j = 0; j < iHeight; j++) {
                std::cout << str[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

};


int main() {

	openFile();

	//Matrix *ptr;
	//ptr = new Matrix(iWidth,iHeight,"- - -\t");
	//ppmFS << *ptr;

	
	closeFile();

	return 0;
}
