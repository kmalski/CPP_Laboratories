#pragma once
#include "DoUndoAction.h"

/**
 * @class KeepInt
 * @brief klasa pozwalajaca opakowac int, aby w przypadku niepowodzenia operacji przywrocic jego wartosc 
 */
class KeepInt : public DoUndoAction {
public:
    /**
     * @fn KeepInt
     * @brief konstruktor przyjmujacy referencje do int'a, ktory chcemy opakowac
     */
    KeepInt(int &account);

    /**
     * @fn dodo
     * @brief metoda, ktora zostanie wykonana podczas rozpoczecia operacji
     */
    void dodo() override; 

    /**
     * @fn dodo
     * @brief metoda, ktora zostanie wykonana jesli operacja sie powiedzie
     */
    void undoOk() override;

    /**
     * @fn dodo
     * @brief metoda, ktora zostanie wykonana jesli operacja sie ne powiedzie, przywraca wartosc przechowywanego int'a sprzed rozpoczecia operacji
     */
    void undoFail() override;

private:
    /**
     * @param _account referencja do opakowywanego int'a
     */ 
    int &_account;

    /**
     * @param _startValue wartosc jaka mial opakowywany int przed rozpoczeciem operacji
     */ 
    const int _startValue;
};