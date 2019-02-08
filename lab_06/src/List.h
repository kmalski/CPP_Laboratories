#pragma once
#include "Node.h"

/**
 * @class List
 * @brief klasa reprezentujaca kopiowalna liste polaczona
 */
class List {
    public:

        enum mode {
            /**
             * @param wartosc symbolizujaca poczatek listy
             */
            Begin,

            /**
             * @param wartosc symbolizujaca koniec listy
             */
            End
        };

        /**
         * @fn List
         * @brief konstruktor tworzacy pusta liste
         */
        List(); //konstruktor

        /**
         * @fn List
         * @brief konstruktor tworzacy nowa liste na podstawie podanej
         */
        List(const List& list);

        /**
         * @fn ~List
         * @brief destruktor zwalniajacy pamiec po liscie
         */
        ~List();

        /**
         * @fn find
         * @brief sprawdza czy podana wartosc znajduje sie w liscie
         */
        const Node* find(int value) const;
        
        /**
         * @fn insert
         * @brief dodaje do listy nowy element na poczatek lub koniec, w zaleznosci od parametru mode
         */
        List& insert(int value, const mode m = End);

        /**
         * @fn print
         * @brief wypisuje liste
         */
        void print() const;

    private:
        /**
         * @param wskaznik na pierwszy wezel
         */
        Node *_head;

        /**
         * @param wskaznik na ostatni wezel
         */
        Node *_tail;
};