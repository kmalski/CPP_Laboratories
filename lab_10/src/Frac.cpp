#include <iostream>
#include "Frac.h"

int Frac::_precision = 1;

Frac::Frac(const int l, const int m) : _l(l), _m(m) {}

Frac::Frac(const int l) : _l(l), _m(1) {}

Frac::Frac(const double number) {
    double tmp = number;
    int tmp2 = (int)tmp;
    _m = 1;
    while (_m < _precision && (tmp - double(tmp2)) != 0) {
        tmp *= 10;
        tmp2 = (int)tmp;
        _m *= 10;
    }
    _l = (int)tmp;
}

Frac Frac::add(const Frac &frac) const {
    int m = this->_m * frac._m;
    int l = (this->_l * frac._m) + (frac._l * this->_m);
    return Frac(l, m);
}

void Frac::print() const {
    std::cout << _l << "/" << _m;
}

void Frac::print(const char *str) const {
    std::cout << _l << "/" << _m << str;
}

void Frac::setCnvPrecision(const int precision) {
    _precision = precision;
}

Frac::operator double() const {
    return (double)_l/(double)_m;
}
