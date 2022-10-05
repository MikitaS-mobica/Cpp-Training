#include <iostream>
#include <string>
#include <list>


bool isEisenhower(const std::string &author)
{
    return author == "Eisenhower";
}


auto searchForEisenhower(std::list<std::string> &library)
{
    std::string foundBook;

    for(auto &author: library)
    {
        std::cout << author << std::endl;
        if(isEisenhower(author))
        {
            foundBook = author;
            break;
        }
    }
    
    return isEisenhower(foundBook);
}


int main()
{
    std::list<std::string> library;

    library.push_back("Shakespeare");
    library.push_back("Hemingway");
    library.push_back("Eisenhower");
    library.push_back("Fiction: Marks");

    std::cout << (searchForEisenhower(library) ? "book found" : "no Eisenhower") << std::endl;

    return 0;
}
