#pragma once
#include "Urzadzenie.h"

/**
 * @class Papierozerne
 * @brief pusta klasa sluzaca do tagowania urzadzen, ktore pozeraja papier, dziedziczy po Urzadzeniu, poniewaz wszystko co jest papierozerne
 *        jest urzadzeniem, a nie odwrotnie
 */
class Papierozerne : public virtual Urzadzenie {
};