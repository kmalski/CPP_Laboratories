#include <string>
#include "Ksero.h"


Ksero::Ksero(Rozdzielczosc roz) : _roz(roz) {}

std::string Ksero::rodzaj() const {
    return "Ksero";
}

std::string Ksero::rozdzielczosc() const {
    return _roz.print();
}

