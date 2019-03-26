#pragma once

#include <iostream>
#include "File.h"

/**
 * @class Dir
 * @brief klasa reprezentujaca katalog, pozwala na przechowywanie w sobie innych katalogow lub plikow
 *      klasa dziedziczy po klasie File, aby mozliwe bylo dodawanie i uzywanie innych katalogow/plikow operujac na tych obiektach 
 *      metodami z klasy File, ktore pelnia funkcje interfejsu
 */
class Dir : public File {
public:
    /**
     * @fn Dir
     * @brief konstruktor klasy Dir, towrzy katalog o podanej nazwie
     */
    Dir(std::string name);

    /**
     * @fn ~Dir
     * @brief usuwa podkatalogi oraz pliki znajdujace sie w katalogu
     */
    ~Dir();

    /**
     * @fn print
     * @brief wypisuje cala strukture katalogu, wszystkie pliki oraz podkatalogi znajdujace sie w nim
     */
    virtual void print(int size) const;

    /**
     * @fn get
     * @brief zwraca szukany obiekt o podanej nazwie, jesli znajduje sie w katalogu lub jakims podkatalogu, lub zwraca nullptr
     *      jesli nie ma takiego obiektu
     */
    virtual File * get(std::string name);

    /**
     * @fn operator+=
     * @brief dodaje do katalogu przekazany plik/katalog
     */
    void operator+=(File *file);

private:
    /**
     * @param _subdir tablica maksymalnie 10 elementow, ktora przechowuje podkatalogi/pliki 
     */
    File *_subdir[10];

    /**
     * @param _size ilosc podkatalogow/plikow w folderze
     */
    int _size = 0;
};
