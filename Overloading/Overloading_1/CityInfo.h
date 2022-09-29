#ifndef TESTCLASS_H
#define TESTCLASS_H

#include <ostream>
#include <string>


class CityInfo
{
private:
    std::string _name;
    int _population;

public:
    CityInfo(std::string name = "", int population = 0);

    // Copy constructor
    CityInfo(const CityInfo &other);

    // Assignment operator overloading
    CityInfo &operator=(const CityInfo &other);

    // Equality check operator overloading
    bool operator==(const CityInfo &other) const;

    // Bitshift operator overloading - print object details in the ostream
    // "friend" means this function can use private members of this class
    friend std::ostream &operator<<(std::ostream &stream, const CityInfo &object);
};

#endif
