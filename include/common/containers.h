//
// Created by Flynn on 26.01.2024.
//

#ifndef PHIUI_CONTAINERS_H
#define PHIUI_CONTAINERS_H

#include "common/common.h"

#include <memory>

namespace phi
{

    enum class ArrayFlags : Flag
    {
        LargeArray = 0b1
    };

    template<class T>
    class Array
    {
    public:
        Array();
        Array(ui16 reserve);
        ~Array();
        st size() const;
        T& operator[](st i);

    protected:
        void _alloc();
        st _size;
        st _reserve;
        T* _data;
    };

    template<class T>
    Array<T>::Array() : _size(0), _reserve(ARRAY_PREALLOC_SMALL), _data(nullptr)
    {

    }

    template<class T>
    Array<T>::Array(ui16 reserve) : _size(0), _reserve(reserve), _data(nullptr)
    {

    }

    template<class T>
    void Array<T>::_alloc()
    {
        // TODO implement container
    }

    template<class T>
    Array<T>::~Array()
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

#endif //PHIUI_CONTAINERS_H
