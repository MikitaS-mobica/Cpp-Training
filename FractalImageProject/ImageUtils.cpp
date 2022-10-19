#include "ImageUtils.h"


std::ostream & operator<<(std::ostream &stream, const Bitmap::ImageRGBColor &obj)
{
    stream << obj.red();
    stream << obj.green();
    stream << obj.blue();
    
    return stream;
}
