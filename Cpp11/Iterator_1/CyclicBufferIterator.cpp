#ifndef CYCLICBUFFERITERATOR_CPP
#define CYCLICBUFFERITERATOR_CPP

#include "CyclicBuffer.h"


template <typename T>
CyclicBuffer<T>::iterator::iterator(int position, typename CyclicBuffer<T>::CyclicBuffer &parent) :
    _position(position),
    _parent(parent)
{
}


template <typename T>
bool CyclicBuffer<T>::iterator::operator==(const iterator &other) const
{
    return _position == other._position;
}


template <typename T>
bool CyclicBuffer<T>::iterator::operator!=(const iterator &other) const
{
    return _position != other._position;
}


template <typename T>
typename CyclicBuffer<T>::iterator & CyclicBuffer<T>::iterator::operator++()
{
    _position++;
    /*
    if(_position >= _parent.capacity())
        _position = 0;
    */

    return *this;
}


template <typename T>
typename CyclicBuffer<T>::iterator & CyclicBuffer<T>::iterator::operator++(int arg)
{
    return operator++();
}


template <typename T>
T & CyclicBuffer<T>::iterator::operator*()
{
    return _parent.peek(_position);
}

#endif
