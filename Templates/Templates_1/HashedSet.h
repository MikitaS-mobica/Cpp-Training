#ifndef HASHEDSET_H
#define HASHEDSET_H

#include <map>

// This class can replace std::set for working with large objects, 
// which can require a lot of time to compare to each other.
// Thus, this class can be used to store and rapidly search
// long strings, other classes, etc.

// Downside of this approach: some objects can be considered equal
// when they are not. This can occur due to the restricted length
// of the hash value and bad hash calculation algorithm


template <typename T>
class HashedSet
{
private:
    std::map<unsigned long long, T> _obj;

public:
    // std::set member functions implementation
    void insert(T &newValue)
    {
        unsigned long long hash = 0;
        const char *objPointer = reinterpret_cast<char *>(&newValue);

        for(int i = 0; i < sizeof(T); i++)
        {
            hash << 1;
            hash += *objPointer;
            objPointer++;
        }

        _obj[hash] = newValue;
        
        return;
    }

    // Implement other std::set member functions here
};

#endif
