#include <algorithm>
#include <iostream>
#include "MyFileStream.cpp"
#include <utility>
#include <string>
#include <vector>


typedef std::pair<std::string, int> city_t;


city_t readCityPopulation(MyFileStream &file)
{
    city_t newCity;

    std::getline(file, newCity.first, ':');
    file >> newCity.second;

    file >> std::ws;

    return newCity;
}


void readFile(MyFileStream &file, std::vector<city_t> &cities)
{
    if(!file.is_open())
    {
        std::cout << "File " << file.name() << "is not opened..." << std::endl;
        return;
    }

    std::string thisLine;

    while(file.good())
    {
        std::getline(file, thisLine, ':');

        if(!file.good())
            continue;

        if(thisLine == std::string("Population"))
            cities.push_back(readCityPopulation(file));
    }

    return;
}


void printCity(city_t &city)
{
    std::cout << city.first << " population is " << city.second << std::endl;
    
    return;
}


int main()
{
    MyFileStream currentFile;
    std::string currentFileName = "testFile.txt";
    std::vector<city_t> cities;

    currentFile.open(currentFileName, std::ios::in);

    readFile(currentFile, cities);
    for_each(cities.begin(), cities.end(), printCity);
    
    currentFile.close();

    return 0;
}

