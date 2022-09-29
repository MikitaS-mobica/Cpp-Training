#include "CityInfo.h"

#include <iostream>


CityInfo::CityInfo(std::string name, int population) :
    _name(name),
    _population(population)
{
}


CityInfo::CityInfo(const CityInfo &other)
{
    _name = other._name;
    _population = other._population;

    std::cout << "Copy constructor" << std::endl;
}


CityInfo & CityInfo::operator=(const CityInfo &other)
{
    _name = other._name;
    _population = other._population;

    std::cout << "Assignment operator" << std::endl;

    return *this;
}


bool CityInfo::operator==(const CityInfo &other) const
{
    if(_name != other._name)
        return false;
    if(_population != other._population)
        return false;
    return true;
}


std::ostream &operator<<(std::ostream &stream, const CityInfo &object)
{
    stream << object._name << ": " << object._population;

    return stream;
}
