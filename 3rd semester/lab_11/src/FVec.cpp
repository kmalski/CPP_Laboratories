#include <iostream>
#include "FVec.h"

using std::cout;
using std::endl;

FVec::FVec(const int size) : _size(size) {
    _vector = new int[_size];
    for (int i = 0 ; i < _size; i++) {
        _vector[i] = 0;
    }
}

FVec::FVec(const FVec& vec) : _size(vec._size) {
    _vector = new int[_size];
    for (int i = 0 ; i < _size; i++) {
        _vector[i] = vec._vector[i];
    }
}

FVec::~FVec() {
    delete[] _vector;
}

FVec& FVec::set(const int index, const int value) {
    _vector[index] = value;
    return *this;
}

void FVec::print(const char* str) const {
    cout << str;
    for (int i = 0 ; i < _size; i++) {
        cout << _vector[i] << " ";
    }
    cout << endl;
}

FVec FVec::operator+(const int value) const {
    FVec tmp = FVec(_size);
    for (int i = 0; i < _size; i++) {
        tmp.set(i, _vector[i] + value);
    }
    return tmp;
}


FVec FVec::operator+(const FVec& vec) const {
    FVec tmp = FVec(_size);
    for (int i = 0; i < _size; i++) {
        tmp.set(i, _vector[i] + this->_vector[i]);
    }
    return tmp;
}

FVec& FVec::operator=(const FVec& vec) {
    if(&vec == this) {
        return *this;
    }
    delete[] _vector;

    _size = vec._size;
    _vector = new int[_size];
    for (int i = 0 ; i < _size; i++) {
        this->set(i, vec._vector[i]);
    }
    return *this;
}
