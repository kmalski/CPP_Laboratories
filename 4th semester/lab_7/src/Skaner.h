#pragma once
#include "Urzadzenie.h"
#include "Rozdzielczosc.h"

/**
 * @class Skaner
 * @brief klasa reprezentujaca urzadzenie typu skaner, dziedziczy po Urzadzeniu, poniewaz implementuje jej funkcje.
 *        Dziedziczenie bylo rowniez potrzebne do uzywania dynamic_cast z klas bazowych w pliku mtest
 */
class Skaner : public virtual Urzadzenie {
    public:
        Skaner(const Rozdzielczosc roz);
        std::string rodzaj() const override;
        std::string rozdzielczosc() const;

    private:
        Rozdzielczosc _roz;
};