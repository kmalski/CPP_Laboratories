#include <iostream>
#include <string>
#include "Rozdzielczosc.h"

Rozdzielczosc::Rozdzielczosc(const unsigned int width, const unsigned int height) : _width(width), _height(height) {}

std::string Rozdzielczosc::print() const {
    return std::to_string(_width) + "x" + std::to_string(_height);
}
