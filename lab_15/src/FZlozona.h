#pragma once

#include "Fun.h"

/*
*   @brief klasa dziedziczy po klasie Fun, ponieważ implementuje interfejs klasy bazowej (Fun)
*/

class FZlozona : public Fun {
    public:
        FZlozona(Fun* fun1, Fun* fun2);

        double wartosc(double value);

    private:
        Fun* _fun1;

        Fun* _fun2;
};