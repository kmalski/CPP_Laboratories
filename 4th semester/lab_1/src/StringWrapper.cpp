#include <iostream>
#include "StringWrapper.h"

StringWrapper::StringWrapper(std::string str) : _str(str) {}

void StringWrapper::print() const {
    std::cout << _str;
}

Wrapper * StringWrapper::copy() const {
    return new StringWrapper(_str);
}
