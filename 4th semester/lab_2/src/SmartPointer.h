#pragma once

#include "TestClassA.h"

/**
 * @class SmartPointer
 * @brief klasa reprezentujaca sprytny wskaznik, czyli klasa, ktora opakowuje wskaznik, tak aby procz samego skaznika przetrzymywac licznik 
 * referencji, czyli licznik, ktory mowi, ile sprytnych wskaznikow wskazuje na ten sam obiekt
 */
class SmartPointer {
public:

    /**
    * @fn SmartPointer
    * @brief tworzy sprytny wskaznik. Przechowuje wskaznik do przekazanego obiektu oraz tworzy licznik, ktory przechowuje ilosc referencji
    *   (czyli ile innych sprytnych wskaznikow, wskazuje na ten sam obiekt) do przechowywanego obiektu
    * @param ptr wskaznik do obiektu, ktory bedziemy przetrzymywac
    */
    SmartPointer(TestClassA *ptr);

    /**
    * @fn SmartPointer
    * @brief tworzy sprytny wskaznik, ktory bedzie wskazywal na ten sam obiekt co przekazany sprytny wskaznik. Zwieksza przy tym licznik 
    *   referencji 
    * @param copy sprytny wskaznik, ktory chcemy skopiowac
    */
    SmartPointer(const SmartPointer &copy);

    /**
    * @fn ~SmartPointer
    * @brief usuwa sprytny wskaznik, zmniejsza licznik referencji, a jesli jest on rowny 0 to kasuje rowniez obiekt na ktory wskazuje
    */
    ~SmartPointer();

    /**
    * @fn operator=
    * @brief zmniejsza licznik referencji poprzedniego wskaznika i usuwa przechowywany obiekt jesli licznik jest rowny 0. Nastepnie 
    *   przypisuje do przechowywanego obiektu, obiekt na ktory wskazuje sprytny wskaznik przekazany jako parametr oraz
    *   zwieksza licznik referencji nowego wskaznika,
    * @param copy sprytny wskaznik, ktory chcemy przypisac
    */
    SmartPointer & operator=(const SmartPointer &copy);

    /**
    * @fn operator*
    * @brief zwraca referencje do obiektu, na ktory wskazuje sprytny wskaznik
    */
    TestClassA & operator*();

    /**
    * @fn const operator*
    * @brief zwraca stala referencje do obiektu, na ktory wskazuje sprytny wskaznik
    */
    const TestClassA & operator*() const;

    /**
    * @fn operator->
    * @brief zwraca wskaznik na obiekt, ktory przechowuje sprytny wskaznik
    */
    TestClassA * operator->();

    /**
    * @fn const operator->
    * @brief zwraca staly wskaznik na obiekt, ktory przechowuje sprytny wskaznik
    */
    const TestClassA * operator->() const;

private:
    /**
    * @param _ptr wskaznik na obiekt, ktory opakowuje sprytny wskaznik
    */
    TestClassA *_ptr;

    /**
    * @param _count licznik referencji na aktualnie przechowywany wskaznik
    */
    int *_count;

};
