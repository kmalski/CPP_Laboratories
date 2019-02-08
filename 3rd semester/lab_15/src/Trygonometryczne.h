#pragma once

#include "Fun.h"

/*
*   @brief klasa dziedziczy po klasie Fun, ponieważ implementuje interfejs klasy bazowej (Fun)
*/

class Sinus : public Fun {
    public:
        Sinus() = default;

        double wartosc(double value);

};