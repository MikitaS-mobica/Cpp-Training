#include <algorithm>
#include <array>
#include <iostream>
#include <vector>


void fillNumberSequence(std::vector<int> &sequence)
{
    static int numbers[] = 
    {
        1, 5, 8, 2, 9, 3, 45, 3, 97, 6, 47, 9, 1, 2
    };
    
    for(int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++)
        sequence.push_back(numbers[i]);
    
    return;
}


int main()
{
    std::vector<int> numberSequence;

    fillNumberSequence(numberSequence);
    std::sort(numberSequence.begin(), numberSequence.end());

    for(std::vector<int>::iterator it = numberSequence.begin(); it != numberSequence.end(); it++)
    {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;

    return 0;
}

