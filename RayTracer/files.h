#include "publics.h"

std::ofstream ppmFS("the_image.ppm", std::ios::out | std::ios::binary);

void openFile() {

	ppmFS << "P3\n";
	ppmFS << iWidth << " " << iHeight << "\n";
	ppmFS << maxColorComponent << "\n";

}

void closeFile() {

	ppmFS.close();
}