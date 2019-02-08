#pragma once

/**
 * @class FVec
 * @brief klasa reprezentujaca kopiowalny i przypisywalny wektor
 */
class FVec {
    public:
        /**
         * @fn FVec
         * @brief tworzy wektor o podanym rozmiarze i wypełnia go zerami
         * @param size rozmiar
         */
        FVec(const int size);

        /**
         * @fn FVec
         * @brief kopiuje podany wektor
         * @param vec wektor, ktory chcemy skopiowac
         */
        FVec(const FVec& vec);

        /**
         * @fn ~FVec
         * @brief destruktor, zwalnia pamiec po tablicy trzymajacej wartosi wektora
         */
        ~FVec();

        /**
         * @fn set
         * @brief ustawia wartosc pod podanym indeksem na ta podana
         */
        FVec& set(const int index, const int value);

        /**
         * @fn print
         * @brief wypisuje wektor oraz jesli podano to dodatkowy napis
         * @param str dodatkowy napis do wypisania
         */
        void print(const char* str = "") const;

        /**
         * @fn operator+
         * @brief dodaje do wektora podana wartosc
         */
        FVec operator+(const int value) const;

        /**
         * @fn operator+
         * @brief dodaje wektor do wektora
         * @warning rozmiary obu wektorow musza byc takie same
         */
        FVec operator+(const FVec& vec) const;

        /**
         * @fn operator=
         * @brief przypisuje do wektora podany wektor
         */
        FVec& operator=(const FVec& vec);

    private:
        /**
         * @param _size rozmiar wektora
         */
        int _size;

        /**
         * @param _l tablica przechowujaca wartosci wektora
         */
        int *_vector;
};
