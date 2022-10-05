#include <iostream>
#include <string>
#include <typeinfo>


#define PRINT_SIZE(x) PrintSize<decltype(x)>()(x)


template <typename T>
struct PrintSize
{
public:
    virtual void operator()(T obj)
    {
        std::cout << "Size of the object is " << sizeof(obj) << " bytes" << std::endl;
        return;
    }
};


int main()
{
    int value = 2;
    
    PrintSize<decltype(value)> printSize;
    printSize(value);

    PrintSize<decltype(value)>()(value);


    const char testCText[] = "Hello World!";
    PrintSize<decltype(testCText)>()(testCText);

    std::string testCppText = "Hello World! Hello World! Hello World! Hello World! Hello World!";
    PrintSize<decltype(testCppText)>()(testCppText);

    PRINT_SIZE(testCppText);

    return 0;
}
