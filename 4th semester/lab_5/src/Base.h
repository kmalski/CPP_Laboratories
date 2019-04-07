#pragma once
#include <iostream>

/**
 * @class Base
 * @brief klasa bazowa posiadajaca podstawowy interfejs dla plikow i katalogow
 */
class Base {
public:
    /**
     * @fn Base
     * @brief konstruktor klasy Base
     */
    Base(const std::string& name);

    /**
     * @fn ~Base
     * @brief domyslny destruktor klasy Base
     */
    virtual ~Base() = default;

    /**
     * @fn get
     * @brief wirtualna metoda do wyszukiwania obiektu w strukturze katalogu zaimplementowana w klasach pochodnych
     */
    virtual Base * get(const std::string& name) = 0;

    /**
     * @fn print
     * @brief wirtualna metoda do wypisywania struktury katalogu zaimplementowana w klasach pochodnych
     */
    virtual void print(int size) const = 0;

    /**
     * @fn getName
     * @brief zwraca nazwe obiektu
     */
    std::string getName() const;

protected:
    /**
     * @param _name nazwa obiektu
     */
    std::string _name;
};

/**
 * @fn operator<<
 * @brief standardowe przeciazenie operatora<< pozwalajace na wypisanie obiektu, wypisuje cala strukture plikow
 */
std::ostream& operator<<(std::ostream& out, const Base& base);