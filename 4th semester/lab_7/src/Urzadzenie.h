#pragma once

/**
 * @class Urzedzenie
 * @brief czysto wirtualna klasa bazowa dla wszystkich urzadzen, poniewaz wszystkie posiadaja metode rodzaj (linia 20 mtest.cpp) 
 */
class Urzadzenie {
public:
    Urzadzenie() = default;
    virtual ~Urzadzenie() = default;
    virtual std::string rodzaj() const = 0;
};