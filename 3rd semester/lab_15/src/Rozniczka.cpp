#include "Rozniczka.h"

ProstaRozniczka::ProstaRozniczka(double h) : _h(h) {}

ProstaRozniczka* ProstaRozniczka::z(Fun* fun) {
    _fun = fun;
    return this;
}

double  ProstaRozniczka::w(double x) {
    return (_fun->wartosc(x + _h) - _fun->wartosc(x - _h)) / (2. * _h);
}