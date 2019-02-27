#pragma once

#include <iostream>
#include "Wrapper.h"

class StringWrapper : public Wrapper {
public:
    StringWrapper(std::string str);
    void print() const;
    Wrapper * copy() const;

private:
    std::string _str;
};