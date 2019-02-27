#include <iostream>
#include "FloatWrapper.h"

FloatWrapper::FloatWrapper(float value) : _value(value) {}

void FloatWrapper::print() const {
    std::cout << _value;
}

Wrapper * FloatWrapper::copy() const {
    return new FloatWrapper(_value);
}

