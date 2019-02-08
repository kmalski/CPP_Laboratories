#include "FElementarne.h"

double Liniowa::wartosc(double value) {
    return _a * value + _b;
}

Liniowa* Liniowa::utworz() {
    return new Liniowa();
}

Liniowa* Liniowa::a(double value) {
    _a = value;
    return this;
}

Liniowa* Liniowa::b(double value) {
    _b = value;
    return this;
}

////////////////////////////////////////////////////

double Kwadratowa::wartosc(double value) {
    return _a * value * value + _b * value + _c;
}

Kwadratowa* Kwadratowa::utworz() {
    return new Kwadratowa();
}

Kwadratowa* Kwadratowa::a(double value) {
    _a = value;
    return this;
}

Kwadratowa* Kwadratowa::b(double value) {
    _b = value;
    return this;
}

Kwadratowa* Kwadratowa::c(double value) {
    _c = value;
    return this;
}