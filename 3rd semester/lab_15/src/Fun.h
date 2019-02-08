#pragma once

/*
*   @brief abstrakcyjna klasa bazowa, po której dziedzicżą klasy reprezentujące funkcje i zawierające metodę wartosc.
*   Dziedziczymy w ten sposób, ponieważ chcemy, żeby każda z klas miała własną implementację metody wartosc, ale jednocześnie
*   chcemy każdą z klas pochodnych móc przypisać do wskaźnika klasy bazowej (Fun)
*/

class Fun {
    public:
    /*
    *   @fn wartosc
    *   @brief metoda wirtualna, obliczająca wartość funkcji w danym punkcie, której implementacji wymagamy w klasach pochodncych
    */
        virtual double wartosc(double value) = 0;

    /*
    *   @fn ~Fun
    *   @brief destruktor wirtualny
    */
        virtual ~Fun() = default;
};