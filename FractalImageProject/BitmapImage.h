#ifndef BITMAPIMAGE_H
#define BITMAPIMAGE_H

#include "ImageUtils.h"
#include <string>


namespace Bitmap
{
class BitmapImage
{
private:
    int _width;
    int _height;
    ImageRGBColor **_image = nullptr;

public:
    BitmapImage(int width, int height);
    ~BitmapImage();
    
    void setPixel(ImagePoint point, ImageRGBColor color);
    bool write(std::string filename);

    int height();
    int width();
};

}
#endif
