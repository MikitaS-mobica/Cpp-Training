#include <iostream>
#include <memory>


#define ARRAY_SIZE  2


class Announcer
{
public:
    Announcer()
    {
        std::cout << "Announcer created!" << std::endl;
    };

    ~Announcer()
    {
        std::cout << "Announcer destroyed!" << std::endl;
    };
};


Announcer *createArray(int arraySize)
{
    std::unique_ptr<Announcer[]> testArr(new Announcer[arraySize]);

    return testArr.release();
}


std::unique_ptr<Announcer[]> createUniquePtr(int arraySize)
{
    // std::make_unique() is considered to be safer and more readable way
    auto testArr = std::make_unique<Announcer[]>(arraySize);

    return testArr;
}


int main()
{
    std::cout << "Program started!" << std::endl;
    std::unique_ptr<Announcer[]> newArray(createArray(ARRAY_SIZE));
    std::cout << "Array created!" << std::endl;

    auto test = std::move(newArray);
    std::cout << "Array moved!" << std::endl;
    newArray.reset();
    std::cout << "@newArray resetted!" << std::endl;

    newArray = createUniquePtr(ARRAY_SIZE);

    return 0;
}
