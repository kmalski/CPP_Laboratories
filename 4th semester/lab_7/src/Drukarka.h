#pragma once
#include "Papierozerne.h"
#include "Rozdzielczosc.h"

/**
 * @class Drukarka
 * @brief klasa reprezentujaca urzadzenie typu drukarka, dziedziczy po Pepierozernych, poniewaz pozera papier :)
 *        Dziedziczenie bylo rowniez potrzebne do uzywania dynamic_cast z klas bazowych w pliku mtest
 */
class Drukarka : public virtual Papierozerne {
    public:
        Drukarka(const Rozdzielczosc roz);
        std::string rodzaj() const override;
        std::string rozdzielczosc() const;

    private:
        Rozdzielczosc _roz;
};