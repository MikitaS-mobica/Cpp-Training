#ifndef CYCLICBUFFER_H
#define CYCLICBUFFER_H

#include <initializer_list>


template <typename T>
class CyclicBuffer
{
private:
    int _capacity;
    int _readPos{0};
    int _writePos{0};
    bool _empty{true};
    T *_buffer;

public:
    class iterator;

    CyclicBuffer() = delete;    // Delete implicit empty constructor (yes, it was deleted by setting explicit constructors)
    CyclicBuffer(const CyclicBuffer &other) = default;  // Set default copy constructor
    CyclicBuffer(int capacity);
    CyclicBuffer(std::initializer_list<T> initValues);    
    ~CyclicBuffer();

    // Those iterators won't work when @_buffer is full
    // begin() and end() will point to the same value
    // Right now this is changed to position 0 for begin()
    // and position _capacity for end()
    
    // Returns iterator pointing to the current read position
    iterator begin();
    // Returns iterator pointing to the current write position
    iterator end();

    void insert(T value);
    T get();   // Automatically pops value
    T &peek(int position);   // Doesn't pop value
    
    int capacity();
    int size();
    
    bool empty();
    bool full();
};


template <typename T>
class CyclicBuffer<T>::iterator
{
private:
    int _position;
    CyclicBuffer &_parent;

public:
    iterator(int position, CyclicBuffer &parent);

    bool operator==(const iterator &other) const;
    bool operator!=(const iterator &other) const;
    iterator &operator++();
    iterator &operator++(int arg);  // Why is this even a thing?
    T &operator*();
};


#include "CyclicBuffer.cpp"
#include "CyclicBufferIterator.cpp"

#endif
