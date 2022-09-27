#include <iostream>
#include "MyFileStream.cpp"
#include <string>


void readFile(MyFileStream &file)
{
    if(!file.is_open())
    {
        std::cout << "File " << file.name() << "is not opened..." << std::endl;
        return;
    }

    while(file)
    {
        std::string thisLine;
        std::getline(file, thisLine);
        std::cout << thisLine << std::endl;
    }
    file.seekg(file.beg);

    return;
}


void writeToFile(MyFileStream &file)
{
    if(!file.is_open())
    {
        std::cout << "File " << file.name() << "is not opened..." << std::endl;
        return;
    }

    //file.seekp(file.beg);
    file << "Say Hi to a new line" << std::endl;

    return;
}


int main()
{
    MyFileStream currentFile;
    std::string currentFileName = "testFile.txt";

    // Write/Append to file doesn't work when file is opened for reading
    currentFile.open(currentFileName, std::ios::in | std::ios::app);
    //currentFile.open(currentFileName, std::ios::app);

    //readFile(currentFile);
    writeToFile(currentFile);
    
    currentFile.close();

    return 0;
}

