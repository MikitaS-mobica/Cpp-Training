#include "MyFileStream.h"


void MyFileStream::open (const char* filename, std::ios_base::openmode mode)
{
    _name = filename;
    std::fstream::open(filename, mode);

    return;
};


void MyFileStream::open (const std::string& filename, std::ios_base::openmode mode)
{
    _name = filename;
    std::fstream::open(filename, mode);

    return;
};


void MyFileStream::close()
{
    _name = "";
    std::fstream::close();

    return;
};


std::string MyFileStream::name()
{
    return _name;
};
