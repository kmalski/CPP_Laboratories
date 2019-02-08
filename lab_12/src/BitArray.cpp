#include <iostream>
#include "BitArray.h"

BitArray::BitArray(int size, bool state) {
    _size = size;
    int length = size / 8;
    if(length * 8 < size) {
        length++;
    }
    _bits = new unsigned char[length];
    for(int i = 0; i < _size; i++) {
        (*this)[i] = state;
    }
}

BitArray::~BitArray() {
    delete[] _bits;
}

Bit BitArray::operator[](int index) {
    int positionInArray = index / 8;
    int bitPosition = index % 8;
    return Bit(bitPosition, _bits + positionInArray);
}

const Bit BitArray::operator[](int index) const {
    int positionInArray = index / 8;
    int bitPosition = index % 8;
    return Bit(bitPosition, _bits + positionInArray);
}

void BitArray::print() const {
    for(int i = _size - 1; i >= 0; i--){
    std::cout<<(*this)[i];
        if(i % 8 == 0){
            std::cout<<" <-" << i << " ";
        }
    }
}