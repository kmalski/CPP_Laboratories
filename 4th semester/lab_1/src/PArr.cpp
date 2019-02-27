#include "PArr.h"

PArr::PArr(int size) : _size(size) {
    _array = new WrapperPtr[size];
}

PArr::~PArr() {
    for (int i = 0; i < _size; i++) {
        delete _array[i];
    }
    delete[] _array;
}

int PArr::getSize() const {
    return _size;
}

PArr::WrapperPtr & PArr::operator[](int index) {
    return _array[index];
}

const PArr::WrapperPtr & PArr::operator[](int index) const {
    return _array[index];
}

PArr & PArr::operator=(const PArr& parr) {
    if(&parr == this)
        return *this;

    for (int i = 0; i < _size; i++) {
        delete _array[i];
    }
    delete[] _array;

    _size = parr.getSize();
    _array = new WrapperPtr[_size];
    for (int i = 0; i < _size; i++) {
        _array[i] = parr[i]->copy();
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, const PArr& parr) {
    for (int i = 0; i < parr.getSize(); i++) {
        parr[i]->print();
        out << " ";
    }
    return out;
}
