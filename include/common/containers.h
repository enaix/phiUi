//
// Created by Flynn on 26.01.2024.
//

#ifndef PHIUI_CONTAINERS_H
#define PHIUI_CONTAINERS_H

#include "common/common.h"

#include <memory>
#include <cstdlib>

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
        void append(T& elem);

    protected:
        void _alloc();
        st _size;
        st _cap;
        st _reserve;
        T* _data;
    };

    template<class T>
    Array<T>::Array() : _size(0), _cap(0), _reserve(ARRAY_PREALLOC_SMALL), _data(nullptr)
    {

    }

    template<class T>
    Array<T>::Array(ui16 reserve) : _size(0), _cap(0), _reserve(reserve), _data(nullptr)
    {

    }

    template<class T>
    void Array<T>::_alloc()
    {
        // TODO implement container
        if (_size == 0)
        {
            _cap = sizeof(T) * _reserve;
            _data = reinterpret_cast<T*>(malloc(_cap)); // TODO change _reserve to _prealloc
            if (!_data)
            {
                // TODO add logger object that can print on screen
                abort();
            }
        }
        else
        {
            _cap = _size * _reserve;
            T* new_data = reinterpret_cast<T*>(realloc(_data, _cap));
            if (!new_data)
            {
                // Add logging
                free(_data);
                abort();
            }
        }
    }

    template<class T>
    Array<T>::~Array()
    {
        if (_data)
            free(_data);
    }

    template<class T>
    st Array<T>::size() const
    {
        return _size;
    }

    template<class T>
    void Array<T>::append(T& elem)
    {
        if (_size + 1 > _cap)
            _alloc();

        _size++;
        _data[_size] = elem; // TODO think about move semantics
    }

    template<class T>
    T& Array<T>::operator[](st i)
    {
        return _data[i];
    }

} // phi

#endif //PHIUI_CONTAINERS_H
