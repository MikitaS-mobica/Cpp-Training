#ifndef CITYINFO_H
#define CITYINFO_H

#include <string>


class CityInfo
{
private:
    std::string _country;
    int _population;

public:
    CityInfo(std::string country = "", int population = 0);

    //CityInfo(const CityInfo &other);

    std::string country(void);
    int population(void);
};

#endif
