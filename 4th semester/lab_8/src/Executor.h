#pragma once

#include <iostream>

/**
 * @namespace Executor
 * @brief przestrzen nazw dla narzedzia "secureRun" oraz potrzebnych klas pozwalajacych na sprytna obsluge wyjatkow dla operacji matematycznych
 */
namespace Executor {
    /**
     * @class Function
     * @brief klasa abstrakcyjna reprezentujaca funkcja
     */
    class Function {
        public:
            /**
             * @fn operator()
             * @brief pozwala uzywac obiektu jak funkcji, udostepnia funktory
             */
            virtual double operator()(double x) const = 0;
    };

    /**
     * @class Result
     * @brief klasa reprezentujaca wynik operacji matematycznej
     */
    class Result {
        public:
            /**
             * @fn Result
             * @brief konstruktor domyslny
             */
            Result() = default;

            /**
             * @fn Result
             * @brief kontruktor pozwalajacy utworzyc obiekt z podana wartoscia, poprawnoscia operacji oraz ewentualnym problemem
             */
            Result(const double value, const bool valid, const std::string problem); 

            /**
             * @fn operator double
             * @brief pozwala zrzutowac klase na typ double
             * @warning jesli operacja matematyczna sie nie powidola rzuca wyjatek
             */
            operator double() const;

            /**
             * @param value wynik wykonywanej operacji matematycznej
             */
            double value;

            /**
             * @param valid flaga mowiaca czy operacja se powiodla
             */            
            bool valid = false;

            /**
             * @param problem opis bledu
             */            
            std::string problem = "";
    };

    /**
     * @fn secureRun
     * @brief pozwala w bezpieczny sposob wywolac podana funkcje (fun), dla podanego argumentu (x). Zapisuje wynik operacji oraz 
     *        ewentualne bledy w zwracanej klasie wynikowej
     */
    Result secureRun(const Function &fun, const double x);
}

/**
 * @fn operator<<
 * @brief pozwala wypisac komunikat bledu
 */
std::ostream & operator<<(std::ostream &out, const Executor::Result &r);