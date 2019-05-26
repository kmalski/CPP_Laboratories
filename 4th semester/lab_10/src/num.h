#pragma once

#include <cmath>

namespace num {
    /**
     * @fn srednia
     * @brief szablon funkcji, ktora oblicza srednia arytmetyczna podanej ilosci elementow z przekazanej tablicy
     * @param T typ przekazywanej tablicy
     * @param size rozmiar przekazywanej tablicy
     * @param n ilosc elementow, z ktorych chcemy policzyc srednia
     * @warning jesli ilosc podanych elementow jest wieksza od rozmiaru tablicy, funkcja zwraca 0
     */
    template <typename T, int size>
    double srednia(const T (&array)[size], int n) {
        double sum = 0.;
        if (n <= size) {
            for (int i = 0; i < n; i++) {
                sum += array[i];
            }
        }
        return sum / n;
    }

    /**
     * @fn srednia
     * @brief szablon funkcji, ktora oblicza srednia arytmetyczna elementow z przekazanej tablicy
     * @param T typ przekazywanej tablicy
     * @param size rozmiar przekazywanej tablicy
     */
    template <typename T, int size>
    double srednia(const T (&array)[size]) {
        return srednia(array, size);
    }

    /**
     * @fn czyWszystkiePierwszwe
     * @brief szablon funkcji, ktora sprawdza czy wszystkie liczby miedzy podanym zakresem (indeksami) [a, b) w tablicy sa liczbami pierwszymi
     * @param a indeks poczatkowy
     * @param b indeks koncowy (sprawdzane sa elementy do b-1 wlacznie)
     * @param size rozmiar przekazywanej tablicy
     * @warning jesli indeks koncowy jest wiekszy od rozmiaru tablicy funkcja zwraca false
     */
    template <int a, int b, int size>
    bool czyWszystkiePierwszwe(const int (&array)[size]) {
        if (b > size)
            return false;
        for (int i = a; i < b; i++) {
            for (int j = 2; i < abs(b / 2); j++) {
                if (!(i % j))
                    return false;
            }
        }
        return true;
    }

    /**
     * @fn text
     * @brief funkcja, ktora zwraca string "TRUE" lub "FALSE", w zaleznosci odpowiednio czy podany warunek ma wartosc logiczna true lub false
     * @param condition warunek logiczny
     */
    std::string text(bool condition) {
        return condition ? "TRUE" : "FALSE";
    }
}
