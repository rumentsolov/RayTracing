#include <fstream>

std::ofstream ppmFS("crt_output_image.ppm", std::ios::out | std::ios::binary);

static const int imageWidth = 1920;
static const int imageHeight = 1080;

static const int maxColorComponent = 255;