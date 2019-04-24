#include <stdexcept>
#include "DoUndo.h"

bool DoUndo::_actionStatus = true;

DoUndo::DoUndo(DoUndoAction *action) : _action(action) {
    _action->dodo();
    _actionStatus = false;
}

DoUndo::~DoUndo() {
    if(_actionStatus) {
        _action->undoOk();
    } else {
        _action->undoFail();
    }
    delete _action;
}

void DoUndo::allok() {
    _actionStatus = true;
}
