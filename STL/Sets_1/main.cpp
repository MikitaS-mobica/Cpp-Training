#include <iostream>
#include <set>


int main()
{
    std::set<int> testSet;

    testSet.insert(12);
    testSet.insert(1);
    testSet.insert(2);
    testSet.insert(120);
    testSet.insert(8);
    testSet.insert(8);

    if(testSet.find(8) != testSet.end())
        std::cout << "Element 8 found" << std::endl;

    for(auto it = testSet.begin(); it != testSet.end(); it++)
        std::cout << *it << std::endl;

    return 0;
}
