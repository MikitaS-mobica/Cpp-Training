#ifndef FRACTALIMAGE_H
#define FRACTALIMAGE_H

#include "BitmapImage.h"
#include <string>


class FractalImage
{
private:
    static void calculateImage(Bitmap::BitmapImage &image);

public:
    static void createImage(int width, int height, std::string name);
};

#endif
