#ifndef CYCLICBUFFER_CPP
#define CYCLICBUFFER_CPP

#include "CyclicBuffer.h"
#include <stdexcept>


template <typename T>
CyclicBuffer<T>::CyclicBuffer(int capacity) :
    _capacity(capacity)
{
    _buffer = new T[capacity];
}


template <typename T>
CyclicBuffer<T>::CyclicBuffer(std::initializer_list<T> initValues)
{
    _capacity = initValues.size();
    _buffer = new T[_capacity];

    for(auto value: initValues)
        insert(value);
}


template <typename T>
CyclicBuffer<T>::~CyclicBuffer()
{
    if(_buffer != nullptr)
        delete [] _buffer;
}


template <typename T>
typename CyclicBuffer<T>::iterator CyclicBuffer<T>::begin()
{
    //return iterator(_readPos, *this);
    return iterator(0, *this);
}


template <typename T>
typename CyclicBuffer<T>::iterator CyclicBuffer<T>::end()
{
    //return iterator(_writePos, *this);
    return iterator(_capacity, *this);
}


template <typename T>
void CyclicBuffer<T>::insert(T value)
{
    bool moveReadPos = full();

    _buffer[_writePos++] = value;
    if(_writePos >= _capacity)
        _writePos = 0;

    _empty = false;

    if(moveReadPos)
        _readPos = _writePos;

    return;
}


template <typename T>
T CyclicBuffer<T>::get()
{
    bool moveWritePos = empty();
    int currentReadPos = _readPos++;

    if(_readPos >= _capacity)
        _readPos = 0;

    if(_readPos == _writePos)
        _empty = true;
    
    if(moveWritePos)
        _writePos = _readPos;

    return _buffer[currentReadPos];
}


template <typename T>
T &CyclicBuffer<T>::peek(int position)
{
    if(position < _capacity)
        return _buffer[position];
    
    //throw std::range_error();
    return _buffer[0];
}


template <typename T>
int CyclicBuffer<T>::capacity()
{
    return _capacity;
}


template <typename T>
int CyclicBuffer<T>::size()
{
    if(empty())
        return 0;
    
    int currentSize = capacity() + _writePos - _readPos;

    if(currentSize >= capacity())
        currentSize -= capacity();
    
    return currentSize;
}


template <typename T>
bool CyclicBuffer<T>::empty()
{
    return _empty;
}


template <typename T>
bool CyclicBuffer<T>::full()
{
    if(!_empty)
        return _readPos == _writePos;
    
    return false;
}

#endif
