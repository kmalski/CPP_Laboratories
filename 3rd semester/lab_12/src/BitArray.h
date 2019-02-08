#pragma once

#include "Bit.h"

/**
*@class BitArray
*@brief klasa reprezentujaca tablice bitow
*/
class BitArray {
    public:

        /**
        *@fn BitArray
        *@brief tworzy tablice bitow o podanym rozmiarze i poczatkowym stanie
        */
        BitArray(int size, bool state = false);

        /**
        *@fn ~BitArray
        *@brief zwalnia pamiec po tablicy bitow
        *@param size rozmiar
        */
        ~BitArray();

        /**
        *@fn print
        *@brief wypisuje tablice bitow
        */
        void print() const;

        /**
        *@fn operator[]
        *@brief zwraca obiekt Bit o podanym indeksie, ktory reprezentuje miejsce w tablicy bitow
        */
        Bit operator[](int index);

        /**
        *@fn operator[]
        *@brief zwraca staly obiekt Bit o podanym indeksie, ktory reprezentuje miejsce w tablicy bitow
        */
        const Bit operator[](int index) const;

    private:
        /**
        *@param _bits tablica charow przechowujaca bity
        */
        unsigned char *_bits;

        /**
        *@param _size ilosc bitow
        */
        int _size;

};
