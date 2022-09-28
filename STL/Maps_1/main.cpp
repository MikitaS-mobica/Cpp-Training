#include "CityInfo.cpp"
#include <iostream>
#include <map>
#include <string>
#include <utility>


void printCities(std::map<std::string, CityInfo> &cities)
{
    std::cout << "List naigrozneiszych miast." << std::endl;
    //for(std::map<std::string, CityInfo>::iterator it = cities.begin(); it != cities.end(); it++)
    for(auto it = cities.begin(); it != cities.end(); it++)
    {
        std::cout << it->first << ": ";
        std::cout << "country is " << it->second.country();
        std::cout << ", ";
        std::cout << "population is " << it->second.population();
        std::cout << std::endl;
    }

    return;
}


int main()
{
    CityInfo bydgoszczInfo("Polska", 15);
    CityInfo szczeczinInfo("Polska", 15000);
    CityInfo bialystokInfo("Polska?");

    std::map<std::string, CityInfo> cities;

    cities.insert(std::make_pair("Gdansk", CityInfo("Definitely Polska", 404)));
    cities.insert(std::make_pair("Bydgoszcz", bydgoszczInfo));
    cities["Szczeczin"] = szczeczinInfo;
    cities.insert(std::make_pair("Bialystok", bialystokInfo));
    cities["Zakopane"] = CityInfo("Polska", 92000);

    CityInfo gdanskInfo = cities["Gdansk"];

    printCities(cities);

    return 0;
}

