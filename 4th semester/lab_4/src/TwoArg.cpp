#include "TwoArg.h"

bool OR::result(const bool cond1, const bool cond2) const {
    return cond1 || cond2; 
}

bool AND::result(const bool cond1, const bool cond2) const {
    return cond1 && cond2;
}
