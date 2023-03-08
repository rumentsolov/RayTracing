#include "publics.h"

int main() {
	
	ppmFS << "P3\n";
	ppmFS << imageWidth << " " << imageHeight << "\n";
	ppmFS << maxColorComponent << "\n";

	for (int rowIdx = 0; rowIdx < imageHeight; ++rowIdx) {
		for (int colIdx = 0; colIdx < imageWidth; ++colIdx) {
			ppmFS << "0 0 255\t";
		}
		ppmFS << "\n";
	}

	ppmFS.close();

	return 0;
}
