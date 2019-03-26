#include "Logical.h"

bool Logical::eval(const TwoArg &operation, const bool cond1, const bool cond2) {
    return operation.result(cond1, cond2);
}

bool Logical::eval(const OneArg &operation, const bool cond) {
    return operation.result(cond);
}

