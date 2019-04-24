#include <string>
#include "Wielofunkcyjne.h"

Wielofunkcyjne::Wielofunkcyjne(Rozdzielczosc roz1, Rozdzielczosc roz2) : Drukarka(roz1), Skaner(roz2), Ksero(roz1) {}

std::string Wielofunkcyjne::rodzaj() const {
    return "Wielofunkcyjne";
}
