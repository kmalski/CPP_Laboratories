#pragma once

#include "Base.h"
#include <iostream>

/**
 * @class File
 * @brief klasa reprezentujaca plik, dziedziczaca po klasie Base, poniewaz korzysta z jej interfejsu
 */
class File final : public Base {
public:
    /**
     * @fn File
     * @brief konstruktor klasy File, ktory towrzy plik o podanej nazwie
     */
    File(const std::string& name);

    /**
     * @fn get
     * @brief sprawdza czy szukany obiekt jest tym plikiem, jesli tak to go zwraca, a jesli nie to zwraca nullptr
     */
    Base * get(const std::string& name) override;

    /**
     * @fn print
     * @brief wypisuje nazwe pliku z podana iloscia spacji przed nazwa
     */
    void print(int size) const override;
};

