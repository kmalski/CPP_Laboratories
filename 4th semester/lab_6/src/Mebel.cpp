#include "Mebel.h"
#include <iostream>

Mebel::Mebel(const int width, const int height, const int length) : _width(width), _height(height), _length(length) {}

Mebel::~Mebel() {
    std::cout << "~Mebel" << std::endl;
}

void Mebel::print() const {
    std::cout << "Mebel: sz: " << _width << " wys: " << _height << " dl: " << _length;
}

std::ostream& operator<<(std::ostream& out, const Mebel& mebel) {
    mebel.print();
    out << "";
    return out;
}
