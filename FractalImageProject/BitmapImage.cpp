#include "BitmapImage.h"

#include "BitmapFileHeaders.h"
#include <fstream>


using namespace Bitmap;


BitmapImage::BitmapImage(int width, int height) :
    _width(width),
    _height(height)
{    
    _image = new ImageRGBColor *[width];
    for(int i = 0; i < width; i++)
        _image[i] = new ImageRGBColor[height];
}


BitmapImage::~BitmapImage()
{
    if(_image == nullptr)
        return;

    for(int i = 0; i < _width; i++)
    {
        if(_image[i] != nullptr)
            delete [] _image[i];
    }
    delete [] _image;
}


void BitmapImage::setPixel(ImagePoint point, ImageRGBColor color)
{
    if(point.x() >= _width)
        return;
    if(point.y() >= _height)
        return;

    _image[point.x()][point.y()] = color;

    return;
}


bool BitmapImage::write(std::string filename)
{
    struct Bitmap::fileHeader newImageHeader = 
    {
        .fileSize = sizeof(Bitmap::fileHeader) + sizeof(Bitmap::fileInfoHeader) +
            (_width * _height * sizeof(Bitmap::ImageRGBColor)),
        .dataOffset = sizeof(Bitmap::fileHeader) + sizeof(Bitmap::fileInfoHeader)
    };
    struct Bitmap::fileInfoHeader newImageInfoHeader = 
    {
        .width = _width,
        .height = _height
    };

    std::fstream imgOut(filename, std::ios::out | std::ios::binary);
    if(!imgOut.is_open())
        return false;

    imgOut.write((const char *)&newImageHeader, sizeof(newImageHeader));
    imgOut.write((const char *)&newImageInfoHeader, sizeof(newImageInfoHeader));
    for(int j = 0; j < _height; j++)
    {
        for(int i = 0; i < _width; i++)
            imgOut << _image[i][j];
    }

    imgOut.close();
    return true;
}


int BitmapImage::height()
{
    return _height;
}


int BitmapImage::width()
{
    return _width;
}
