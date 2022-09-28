#include "cityInfo.h"

#include <iostream>


CityInfo::CityInfo(std::string country, int population) : _country(country), _population(population)
{

}


/*
CityInfo::CityInfo(const CityInfo &other)
{
    std::cout << "Copying city with " << other._population << " people." << std::endl;
    _country = other._country;
    _population = other._population;
}
*/


std::string CityInfo::country(void)
{
    return _country;
}


int CityInfo::population(void)
{
    return _population;
}
