//
// Created by Flynn on 26.01.2024.
//

#include "containers.h"

namespace phi
{
    template<class T>
    Array<T>::Array() : _size(0), _data(nullptr)
    {

    }

    template<class T>
    st Array<T>::size() const
    {
        return _size;
    }

    template<class T>
    T& Array<T>::operator[](st i)
    {
        return _data[i];
    }
} // phi