#pragma once

#include "DoUndoAction.h"
#include "KeepInt.h"

/**
 * @class DoUndo
 * @brief klasa pozwalajaca na cofniecie wykonywanych operacji w przypadku jej niepowodzenia 
 */
class DoUndo {
public:
    /**
     * @fn DoUndo
     * @brief konstruktor przyjmujacy wskaznik do operacji, ktora chcemy wykonac
     */
    DoUndo(DoUndoAction *action);

    /**
     * @fn ~DoUndo
     * @brief destruktor, "zatwierdza" wykonane operacje, jesli status operacji jest true
     */
    ~DoUndo();

    /**
     * @fn allok
     * @brief zmienia status na true
     */
    static void allok();

private:
    /**
     * @param _action wskaznik do operacji, ktora mozemy cofnac
     */ 
    DoUndoAction *_action;

    /**
     * @param _actionStatus przechowuje status wszystkich wykonywanych operacji
     */ 
    static bool _actionStatus;
};