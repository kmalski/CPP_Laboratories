#include <string>
#include "Drukarka.h"

Drukarka::Drukarka(Rozdzielczosc roz) : _roz(roz) {}

std::string Drukarka::rodzaj() const {
    return "Drukarka";
}

std::string Drukarka::rozdzielczosc() const {
    return _roz.print();
}
