#pragma once

#include "TwoArg.h"
#include "OneArg.h"

/**
 * @class Logical
 * @brief klasa posiadajaca jedynie funkcje statyczne, ktore pozwalaja na wykonywanie operacji logicznych z podanymi argumentami
 */
class Logical {
public:
    Logical() = delete;
    static bool eval(const TwoArg &operation, const bool cond1, const bool cond2);
    static bool eval(const OneArg &operation, const bool cond);
};