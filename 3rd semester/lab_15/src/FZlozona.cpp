#include "FZlozona.h"

FZlozona::FZlozona(Fun* fun1, Fun* fun2) : _fun1(fun1), _fun2(fun2) {}

double FZlozona::wartosc(double value) {
    return _fun1->wartosc(_fun2->wartosc(value));
}