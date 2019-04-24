#pragma once
#include "Drukarka.h"
#include "Skaner.h"
#include "Ksero.h"

/**
 * @class Wielofunkcyjne
 * @brief klasa reprezentujaca urzadzenie wielofunkcyjne jako polaczenie drukarki, skanera i ksera
 */
class Wielofunkcyjne : public Drukarka, public Skaner, public Ksero {
    public:
        Wielofunkcyjne(const Rozdzielczosc roz1, const Rozdzielczosc roz2);
        std::string rodzaj() const override;
};