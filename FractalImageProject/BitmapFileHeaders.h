#ifndef BITMAPFILEHEADERS_H
#define BITMAPFILEHEADERS_H

#include <cstdint>
#include <ostream>


namespace Bitmap
{

#pragma pack(push, 2)
struct fileHeader
{
    char header[2]{'B', 'M'};
    int32_t fileSize;
    int32_t reserved{0};
    int32_t dataOffset;
};

struct fileInfoHeader
{
    int32_t headerSize{40};
    int32_t width;
    int32_t height;
    int16_t planes{1};
    int16_t bitsPerPixel{24};
    int32_t compression{0};
    int32_t dataSize{0};   // Should it be initialized to zero?
    int32_t horizontalResolution{2400}; // Pixels per inch probably?
    int32_t verticalResolution{2400};
    int32_t colors{0};
    int32_t importantColors{0};
};
#pragma pack(pop)

}


std::ostream & operator<<(std::ostream &stream, const Bitmap::fileHeader &obj);
std::ostream & operator<<(std::ostream &stream, const Bitmap::fileInfoHeader &obj);

#endif
