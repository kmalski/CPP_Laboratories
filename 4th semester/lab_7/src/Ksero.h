#pragma once
#include "Papierozerne.h"
#include "Rozdzielczosc.h"

/**
 * @class Ksero
 * @brief klasa reprezentujaca urzadzenie typu ksero, dziedziczy po Pepierozernych, poniewaz pozera papier :)
 *        Dziedziczenie bylo rowniez potrzebne do uzywania dynamic_cast z klas bazowych w pliku mtest
 */
class Ksero : public virtual Papierozerne {
    public:
        Ksero(const Rozdzielczosc roz);
        std::string rodzaj() const override;
        std::string rozdzielczosc() const;

    private:
        Rozdzielczosc _roz;
};