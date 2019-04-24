#include "KeepInt.h"

KeepInt::KeepInt(int &account) : _account(account), _startValue(account) {}

void KeepInt::dodo() {}

void KeepInt::undoOk() {}

void KeepInt::undoFail() {
    _account = _startValue;
}