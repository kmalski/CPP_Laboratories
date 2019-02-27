#include <iostream>
#include "IntWrapper.h"

IntWrapper::IntWrapper(int value) : _value(value) {}

void IntWrapper::print() const {
    std::cout << _value;
}

Wrapper * IntWrapper::copy() const {
    return new IntWrapper(_value);
}

