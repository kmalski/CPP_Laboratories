#pragma once

/**
 * @class Angle
 * @brief klasa reprezentujaca kat
 */
class Angle {
    public:

        /**
         * @fn fromRadians
         * @brief funkcja sluzaca do stworzenia nowego obiektu Angle podajac wartosc kata w radianach
         * @return kopia nowo powstalego obiektu
         */
        static Angle fromRadians(const double value);

        /**
         * @fn fromDegrees
         * @brief funkcja sluzaca do stworzenia nowego obiektu Angle podajac wartosc kata w stopniach
         * @return kopia nowo powstalego obiektu
         */
        static Angle fromDegrees(const double value);

        /**
         * @fn distance
         * @brief tworzy obiekt o wartosci kata rownej odlegosci dwoch katow podanych jako parametry
         * @return kopia nowo powstałego obiektu
         */
        static Angle distance(const Angle & angle1, const Angle & angle2);

        /**
         * @fn toRad
         * @brief funkcja pobiera wartosc kata w radianach
         * @return wartosc kata w radianach
         */
        double toRad() const;

        /**
         * @fn toDeg
         * @brief funkcja pobiera wartosc kata w stopniach
         * @return wartosc kata w stopniach
         */
        double toDeg() const;

        /**
         * @fn add
         * @brief funkcja dodajaca wartosci katow
         */
        void add(const Angle & angle);

    private:

        /**
         * @param _inRad zmienna przetrzymujaca wartosc kata w radianach
         */
        double _inRad;

        /**
         * @fn Angle
         * @brief konstruktor towrzacy nowy obiekt Angle
         * @param inRad wartosc kata w radianach
         */
        Angle(double inRad);

};