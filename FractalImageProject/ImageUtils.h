#ifndef IMAGEUTILS_H
#define IMAGEUTILS_H

#include <cstdint>
#include <ostream>


namespace Bitmap
{

class ImagePoint
{
private:
    int _x;
    int _y;

public:
    ImagePoint() : _x(0), _y(0) {};
    ImagePoint(int x, int y) : _x(x), _y(y) {};
    ImagePoint(const ImagePoint &other) : _x(other._x), _y(other._y) {};

    ImagePoint &operator=(const ImagePoint &other)
    {
        _x = other._x;
        _y = other._y;
        return *this;
    };

    int x() {return _x;};
    int y() {return _y;};
    void setX(int x) {_x = x;};
    void setY(int y) {_y = y;};
};


class ImageRGBColor
{
private:
    uint8_t _red;
    uint8_t _green;
    uint8_t _blue;

public:
    ImageRGBColor() : _red(0), _green(0), _blue(0) {};
    ImageRGBColor(int red, int green, int blue) :
        _red(red), _green(green), _blue(blue) {};
    ImageRGBColor(const ImageRGBColor &other) :
        _red(other._red), _green(other._green), _blue(other._blue) {};

    ImageRGBColor &operator=(const ImageRGBColor &other)
    {
        _red = other._red;
        _green = other._green;
        _blue = other._blue;
        return *this;
    }

    uint8_t red() const {return _red;};
    uint8_t green() const {return _green;};
    uint8_t blue() const {return _blue;};
    void setRed  (uint8_t red) {_red = red;};
    void setGreen(uint8_t green) {_green = green;};
    void setBlue (uint8_t blue) {_blue = blue;};
};

}

std::ostream & operator<<(std::ostream &stream, const Bitmap::ImageRGBColor &obj);

#endif
