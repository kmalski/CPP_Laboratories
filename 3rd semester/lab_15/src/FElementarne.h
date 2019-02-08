#pragma once

#include "Fun.h"

/*
*   @brief klasa dziedziczy po klasie Fun, ponieważ implementuje interfejs klasy bazowej (Fun)
*/

class Liniowa : public Fun {
    public:
        double wartosc(double value);

        static Liniowa* utworz();

        Liniowa* a(double value);

        Liniowa* b(double value);

    private:
        explicit Liniowa() = default;

        double _a;

        double _b;    
};

/*
*   @brief klasa dziedziczy po klasie Fun, ponieważ implementuje interfejs klasy bazowej (Fun)
*/

class Kwadratowa : public Fun {
    public:
        double wartosc(double value);

        static Kwadratowa* utworz();

        Kwadratowa* a(double value);

        Kwadratowa* b(double value);

        Kwadratowa* c(double value);

    private:
        explicit Kwadratowa() = default;

        double _a;

        double _b;    

        double _c;
};