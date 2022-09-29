#include <iostream>
#include "CityInfo.cpp"


int main()
{
    CityInfo testCity("Bydgoszcz");
    CityInfo testCity2("Szczeczin");

    std::cout << testCity << std::endl;

    CityInfo newTestCity;

    newTestCity = testCity;
    if(newTestCity == testCity)
        std::cout << "Cities are equal" << std::endl;
    else
        std::cout << "Cities are not equal" << std::endl;

    if(newTestCity == testCity2)
        std::cout << "Cities are equal" << std::endl;
    else
        std::cout << "Cities are not equal" << std::endl;

    return 0;
}
