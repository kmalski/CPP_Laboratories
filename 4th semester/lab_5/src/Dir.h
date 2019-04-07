#pragma once

#include <iostream>
#include "Base.h"

/**
 * @class Dir
 * @brief kalasa reprezentujaca katalog, dziedziczaca po klasie Base, poniewaz korzysta z jej interfejsu
 */
class Dir final : public Base {
public:
    /**
     * @fn Dir
     * @brief konstruktor klasy Dir, towrzy katalog o podanej nazwie
     */
    Dir(const std::string& name);

    /**
     * @fn ~Dir
     * @brief destruktor, usuwa podkatalogi oraz pliki znajdujace sie w katalogu
     */
    ~Dir();

    /**
     * @fn get
     * @brief zwraca szukany obiekt (PLIK LUB KATALOG) o podanej nazwie, jesli znajduje sie w katalogu lub jakims podkatalogu, lub zwraca nullptr
     *        jesli nie ma takiego obiektu
     */
    Base * get(const std::string& name) override;

    /**
     * @fn print
     * @brief wypisuje cala strukture katalogu, wszystkie pliki oraz podkatalogi znajdujace sie w nim
     */
    void print(int size) const override;

    /**
     * @fn operator+=
     * @brief dodaje do katalogu przekazany PLIK LUB KATALOG
     */
    void operator+=(Base *base);

    /**
     * @fn findDir
     * @brief sprawdza czy KATALOG o podanej nazwie znajduje sie w katalogu lub jakims podkatalogu, jesli tak to go zwaca, a jesli nie to zwraca nullptr
     */
    Dir * findDir(const std::string& name);

    /**
     * @fn add
     * @brief dodaje do katalogu przekazany KATALOG
     */
    void add(Dir *dir);

private:
    /**
     * @param _subdir tablica maksymalnie 10 elementow, ktora przechowuje podkatalogi/pliki 
     */
    Base *_subdir[10];

    /**
     * @param _size ilosc podkatalogow/plikow w folderze
     */
    int _size = 0;
};
