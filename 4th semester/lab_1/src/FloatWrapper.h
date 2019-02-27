#pragma once

#include "Wrapper.h"

class FloatWrapper : public Wrapper {
public:
    FloatWrapper(float value);
    void print() const;
    Wrapper * copy() const;

private:
    float _value;
};