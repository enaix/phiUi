//
// Created by Flynn on 26.01.2024.
//

#ifndef PHIUI_CONTAINERS_H
#define PHIUI_CONTAINERS_H

#include "common/common.h"

namespace phi
{

    template<class T>
    class Array
    {
    public:
        Array();
        ~Array();
        st size() const;
        T& operator[](st i);

    protected:
        st _size;
        T* _data;
    };

} // phi

#endif //PHIUI_CONTAINERS_H
