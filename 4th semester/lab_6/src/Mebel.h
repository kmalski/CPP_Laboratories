#pragma once

#include <iostream>

class Mebel {
public:
    Mebel(const int width, const int height, const int length);
    Mebel() = default;
    virtual ~Mebel();
    virtual void print() const;

protected:
    int _width;
    int _height;
    int _length;
};

std::ostream& operator<<(std::ostream& out, const Mebel& mebel);