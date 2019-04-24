#pragma once

/**
 * @class DoUndoAction
 * @brief klasa bazowa dla wszystkich klas, ktore pozwalaja na cofniecie operacji z pomoca klasy DoUndo
 */
class DoUndoAction {
public:
    /**
     * @fn dodo
     * @brief metoda, ktora zostanie wykonana podczas rozpoczecia operacji
     */
    virtual void dodo() = 0; 

    /**
     * @fn undoOk
     * @brief metoda, ktora zostanie wykonana jesli operacja sie powiedzie
     */
    virtual void undoOk() = 0;

    /**
     * @fn undoFail
     * @brief metoda, ktora zostanie wykonana jesli operacja sie nie powiedzie
     */
    virtual void undoFail() = 0;

    /**
     * @fn ~DoUndoAction
     * @brief wirtualny destruktor
     */
    virtual ~DoUndoAction() = default;
};