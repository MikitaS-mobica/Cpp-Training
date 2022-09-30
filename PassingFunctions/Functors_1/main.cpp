#include <iostream>


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
    PrintSize<int> printSize;

    printSize(2);

    return 0;
}
