#include <fstream>
#include <string>


class MyFileStream : public std::fstream
{
private:
    std::string _name = "";

public:
    // Overloaded std::fstream::open
    void open (const char* filename, std::ios_base::openmode mode = std::ios_base::in | std::ios_base::out);
    
    // Overloaded std::fstream::open
    void open (const std::string& filename, std::ios_base::openmode mode = std::ios_base::in | std::ios_base::out);
    
    // Overloaded std::fstream::close
    void close();

    // Returns current file name
    std::string name();
};
