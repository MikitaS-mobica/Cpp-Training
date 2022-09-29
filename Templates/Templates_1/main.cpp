#include "HashedSet.h"
#include <iostream>
#include <string>


template <typename T>
void print(T obj)
{
    std::cout << obj << std::endl;

    return;
}

template <typename T>
T divide(T first, T second)
{
    return first / second;
}


int main()
{
    HashedSet<std::string> newSet;
    std::string newString;

    newString = "Hello";
    newSet.insert(newString);

    newString = "world";
    newSet.insert(newString);
    

    print(5 / 2);
    print<>(5 / 2);
    print<int>(5 / 2);
    print<double>(5 / 2);

    print(divide(5, 2));
    print(divide<int>(5, 2));
    print(divide<double>(5, 2));
    print<int>(divide<double>(5, 2));

    return 0;
}
