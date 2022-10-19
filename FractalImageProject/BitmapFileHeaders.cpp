#include "BitmapFileHeaders.h"


std::ostream & operator<<(std::ostream &stream, const Bitmap::fileHeader &obj)
{
    stream << obj.header;
    stream << obj.fileSize;
    stream << obj.reserved;
    stream << obj.dataOffset;
    
    return stream;
}


std::ostream & operator<<(std::ostream &stream, const Bitmap::fileInfoHeader &obj)
{
    stream << obj.headerSize;
    stream << obj.width;
    stream << obj.height;
    stream << obj.planes;
    stream << obj.bitsPerPixel;
    stream << obj.compression;
    stream << obj.dataSize;
    stream << obj.horizontalResolution;
    stream << obj.verticalResolution;
    stream << obj.colors;
    stream << obj.importantColors;
    
    return stream;
}
