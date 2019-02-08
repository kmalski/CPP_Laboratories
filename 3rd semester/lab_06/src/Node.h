#pragma once

/**
 * @class Node
 * @brief klasa reprezentujaca wezel listy
 */
class Node {
    public:
        /**
         * @fn Node
         * @brief konstruktor tworzacy nowy wezel z wartoscia podana jako parametr
         */
        Node(int data);

        /**
         * @fn Node
         * @brief konstruktor tworzacy nowy pusty wezel
         */
        Node();

        /**
         * @fn ~Node
         * @brief destruktor domyslny
         */
        ~Node() = default;

        /**
         * @fn data
         * @brief zwraca wartosc w wezle
         */
        int data() const;

        /**
         * @fn getNext
         * @brief zwraca wskaznik do kolejnego wezla
         */
        Node* getNext() const;

        /**
         * @fn getPrevious
         * @brief zwraca wskaznik do poprzedniego wezla
         */
        Node* getPrevious() const;

        /**
         * @fn setNext
         * @brief ustawia wskaznik na kolejny wezel na ten podany jako parametr
         */
        void setNext(Node *const next);
        
        /**
         * @fn setPrevious
         * @brief ustawia wskaznik na poprzedni wezel na ten podany jako parametr
         */
        void setPrevious(Node *const previous);
    
    private:
        /**
         * @param wartosc trzymana w wezle
         */
        int _data;

        /**
         * @param wskaznik na kolejny wezel
         */
        Node *_next;

        /**
         * @param wskaznik na poprzedni wezel
         */
        Node *_previous;
};