#pragma once

/*
*@struct Node
*@brief struktura zastepujaca wezel listy
*/
struct Node{
    int data[2][2];
    Node *next;
};

/*
*@struct List
*@brief struktura zastepujaca liste
*/
struct List{
    Node *head;
    Node *tail;
};

/*
*@fn prepare
*@brief funkcja przygotowujaca liste
*/
void prepare(List *list);

/*
*@fn prepare
*@brief funkcja kopiujaca druga liste do pierwszej
*@param to lista do kotrej kopiujemy
*@param from lista z ktorej kopiujemy
*/
void prepare(List *to, const List *from);

/*
*@fn add
*@brief  funkcja dodajaca nowe element do list
*/
void add(List *list, int array[][2]);

/*
*@fn empty
*@brief funkcja sprawdzajaca czy lista jest pusta
*/
bool empty(const List *list);

/*
*@fn print
*@brief funkcja wypisujaca liste
*/
void print(const List *list);

/*
*@fn clear
*@brief funkcja zwalniajaca liste
*/
void clear(List *list);