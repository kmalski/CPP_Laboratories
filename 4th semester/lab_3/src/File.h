#pragma once

#include <iostream>

/**
 * @class File
 * @brief klasa File jest klasą bazową, ponieważ posiada metody oraz argument _name, które używa również klasa Dir. Ten sposób dziedziczenia pozwala
 *      również na tworzenie drzewka katalogow bez wiedzy o tym czy skladowa jest plikiem czy katalogiem. Klasa Dir uzywa wszystkich metod z klasy 
 *      File, ale posiada również dodatkowe metody i dodatkowe argumenty, więc dziedziczenie w drugą strone nie jest dobrym pomysłem.
 */
class File {
public:
    /**
     * @fn File
     * @brief konstruktor klasy File, ktory towrzy plik o podanej nazwie
     */
    File(std::string name);

    /**
     * @fn ~File
     * @brief domyslny destruktor klasy File
     */
    virtual ~File() = default;

    /**
     * @fn get
     * @brief sprawdza czy szukany obiekt jest tym plikiem, jesli tak to go zwraca, a jesli nie to zwraca nullptr
     */
    virtual File * get(std::string name);

    /**
     * @fn print
     * @brief wypisuje plik z podana iloscia spacji przed nazwa
     */
    virtual void print(int size) const;

    /**
     * @fn getName
     * @brief zwraca nazwe pliku
     */
    std::string getName() const;

protected:
    /**
     * @param _name nazwa pliku
     */
    std::string _name;
};

/**
 * @fn operator<<
 * @brief standardowe przeciazenie operatora<< pozwalajace na wypisanie obiektu, wypisuje cala strukture katalogu
 */
std::ostream& operator<<(std::ostream& out, const File& file);
