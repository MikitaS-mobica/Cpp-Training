#include <cstdint>
#include <iostream>
#include "FractalImage.h"


static const int IMG_WIDTH = 1920;
static const int IMG_HEIGHT = 1080;




int main()
{
    std::cout << "Fractal Image creation started..." << std::endl;
    FractalImage::createImage(IMG_WIDTH, IMG_HEIGHT, "FractalImage.bmp");

    std::cout << "Fractal Image creation finished." << std::endl;
    return 0;
}
