#pragma once

/**
*@class Bit
*@brief klasa reprezentujaca bit
*/
class Bit {
    public:
        /**
        *@fn Bit
        *@brief tworzy obiekt reprezentujacy bit
        */
        Bit (int position, unsigned char *bit);

        /**
        *@fn operator=
        *@brief zmienia stan bitu na ten podany
        */
        void operator=(bool state);

        /**
        *@fn operator bool()
        *@brief zwraca stan Bitu w postaci bool
        */
        operator bool() const;

    private:
        /**
        *@param _bit indeks tablicy pod ktorym znajduje sie bit
        */
        unsigned char *_bit;

        /**
        *@param _position pozycja bitu w indeksie talbicy
        */
        int _position;
};