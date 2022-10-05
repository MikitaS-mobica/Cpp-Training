#include "CyclicBuffer.h"
#include <iostream>
#include <string>


// Probably some memory allocation issues occur here
// Everything is ok if buffers are defined static 
// As just one or both of them are not static - weird behaviour happens


int main() {
    CyclicBuffer<int> newBuffer(3);

    newBuffer.insert(1);
    newBuffer.insert(2);
    newBuffer.insert(3);
    newBuffer.insert(4);
    newBuffer.insert(5);
    newBuffer.insert(6);

    for(auto bufferElement: newBuffer)
        std::cout << "Element: " << bufferElement << std::endl;

    struct
    {
        int value = 7;
        std::string text;
    } newStruct{.text = "Hi!"};
    std::cout << newStruct.text << std::endl;


    CyclicBuffer<std::string> strBuffer{"one", "two", "three"};

    for(auto bufferElement: strBuffer)
        std::cout << "Element: " << bufferElement << std::endl;

    return 0;
}
