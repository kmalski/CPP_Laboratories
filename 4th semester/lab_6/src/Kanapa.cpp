#include "Kanapa.h"
#include <iostream>

Kanapa::Kanapa(const int width, const int height, const int length, const int seat, const int forSleep) 
: 
Mebel(width, height, length), 
Sofa(seat),
Lozko(forSleep)
{}

Kanapa::~Kanapa() {
    std::cout << "~Kanapa" << std::endl;
}

void Kanapa::print() const {
    std::cout << "jako ";
    Mebel::print();
    std::cout << std::endl << " jako ";
    Sofa::print();
    std::cout << std::endl << " jako ";
    Lozko::print();
}
