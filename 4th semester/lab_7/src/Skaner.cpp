#include <string>
#include "Skaner.h"

Skaner::Skaner(Rozdzielczosc roz) : _roz(roz) {}

std::string Skaner::rodzaj() const {
    return "Skaner";
}

std::string Skaner::rozdzielczosc() const {
    return _roz.print();
}
