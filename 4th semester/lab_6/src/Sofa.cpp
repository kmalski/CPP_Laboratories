#include "Sofa.h"
#include <iostream>

Sofa::Sofa(const int width, const int height, const int length, const int seat) : Mebel(width, height, length), _seat(seat) {}

Sofa::Sofa(const int seat) : _seat(seat) {}

Sofa::~Sofa() {
    std::cout << "~Sofa" << std::endl;
}

void Sofa::print() const {
    std::cout << "Sofa: ";
    Mebel::print();
    std::cout << "  siedzisko: " << _seat;
}
