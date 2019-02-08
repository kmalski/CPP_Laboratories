#pragma once

/**
 * @class FlexiTab
 * @brief klasa reprezentujaca tablice o dowolnie ustalonych indeksach poczatkowym i koncowym
 */
class FlexiTab {
    public:
        /**
         * @fn FlexiTab
         * @brief tworzy obiekt o podanych wartosciach indeksow
         * @param begin indeks poczatkowy
         * @param end indeks koncowy
         */
        FlexiTab(const int begin, const int end);

        /**
         * @fn FlexiTab
         * @brief konstruktor kopiujacy 
         * @param copy obiekt z ktorego kopiujemy
         */
        FlexiTab(const FlexiTab &copy);

        /**
         * @fn FlexiTab
         * @brief konstruktor kopiujacy z innego obiektu wartosci pomiedzy podanymi indeksami 
         * @param begin indeks poczatkowy
         * @param end indeks koncowy
         * @param copy obiekt z ktorego kopiujemy
         */
        FlexiTab(const FlexiTab &copy, const int begin, const int end);

        /**
         * @fn ~FlexiTab
         * @brief destruktor zwalniajacy pamiec po tablicy
        */
        ~FlexiTab();

        /**
         * @fn setAll
         * @brief ustawia wszystkie wartosci w tablicy na podana wartosc
         */
        void setAll(const double value);

        /**
         * @fn getSize
         * @brief funkcja zwracajaca rozmiar tablicy
         */
        int getSize() const;

        /**
         * @fn getMaxIndex
         * @brief funkcja zwracajaca maksymalny + 1 indeks w tablicy
         */
        int getMaxIndex() const;

        /**
         * @fn getMinIndex
         * @brief funkcja zwracajaca minimalny indeks w tablicy
         */
        int getMinIndex() const;

        /**
         * @fn at
         * @brief funkcja zwracajaca referencje do wartosci odpowiadajacej indeksowi w tablicy
         */
        double &at(const int index) const;

        /**
         * @fn inRange
         * @brief funkcja sprawdzajaca czy podany indeks jest w zakresie 
         */
        bool inRange(const int index) const;

        /**
         * @fn print
         * @brief funkcja wypisujaca tablice
         */
        static void print(const FlexiTab &tab);

    private:
        /**
         * @param _begin minimalny indeks w tablicy
         */
        int _begin;

        /**
         * @param _end maksymalny + 1 indeks w tablicy
         */
        int _end;

        /**
         * @param _tab tablica przechowujaca wartosci 
         */
        double *_tab;

};
