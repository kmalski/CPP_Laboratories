#include "Lozko.h"
#include <iostream>

Lozko::Lozko(const int width, const int height, const int length, const int forSleep) : Mebel(width, height, length), _forSleep(forSleep) {}

Lozko::Lozko(const int forSleep) : _forSleep(forSleep) {}

Lozko::~Lozko() {
    std::cout << "~Lozko" << std::endl;
}

void Lozko::print() const {
    std::cout << "Lozko: ";
    Mebel::print();
    std::cout << "  sz.spania: " << _forSleep;
}
