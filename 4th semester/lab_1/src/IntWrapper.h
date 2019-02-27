#pragma once

#include "Wrapper.h"

class IntWrapper : public Wrapper {
public:
    IntWrapper(int _value);
    void print() const;
    Wrapper * copy() const;

private:
    int _value;
};