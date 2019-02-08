#pragma once

/**
 * @class Frac
 * @brief klasa reprezentujaca ulamek zwykly
 */
class Frac {
    public:
        /**
         * @fn Frac
         * @brief tworzy ulamek zwykly o podanym liczniku i mianowniku
         * @param l licznik
         * @param m mianownik
         */
        Frac(const int l, const int m);

        /**
         * @fn Frac
         * @brief tworzy ulamek zwykly o podanym liczniku i mianowniku rownym 1
         * @param l licznik
         */
        Frac(const int l);

        /**
         * @fn Frac
         * @brief tworzy ulamek zwykly z liczby zmiennoprzecinkowej
         * @param number liczba zmiennoprzecinkowa
         */
        Frac(const double number);

        /**
         * @fn add
         * @brief dodaje dwa ulamki zwykle
         */
        Frac add(const Frac &frac) const;

        /**
         * @fn print
         * @brief wypisuje ulamek zwykly
         */
        void print() const;

        /**
         * @fn print
         * @brief wypisuje ulamek zwykly i podana stala znakowa
         */
        void print(const char *str) const;

        /**
         * @fn setCnvPrecision
         * @brief ustawia precyzje do jakiej stowrzony zostanie ulamek zwykly z liczby zmiennoprzecinkowej
         */
        static void setCnvPrecision(const int precision);

        /**
         * @operator double
         * @brief zwraca ulamek zwykly jako liczbe zmiennoprzecinkowa
         */
        operator double() const;

    private:
        /**
         * @param _l licznik ulamka zwyklego
         */
        int _l;

        /**
         * @param _m mianownik ulamka zwyklego
         */
        int _m;

        /**
         * @param _precision precyzja do jakiej bedziemy tworzyc ulamek zwykly z liczby zmiennoprzecinkowej
         */
        static int _precision;
};