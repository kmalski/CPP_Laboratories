#pragma once

#include <iostream>
#include "Wrapper.h"

class PArr {
public:
    typedef Wrapper* WrapperPtr;

    PArr(int size);
    ~PArr();
    int getSize() const;
    WrapperPtr & operator[](int index);
    const WrapperPtr & operator[](int index) const;
    PArr & operator=(const PArr& parr);

private:
    WrapperPtr *_array;
    int _size;
};

std::ostream& operator<<(std::ostream& out, const PArr& parr);
