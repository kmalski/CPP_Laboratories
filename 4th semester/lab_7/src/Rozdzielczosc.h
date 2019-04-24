#pragma once

/**
 * @class Rozdzielczosc
 * @brief klasa reprezentujaca rozdzielczosc urzadzen
 */
class Rozdzielczosc {
public:
    Rozdzielczosc(const unsigned int width, const unsigned int height);
    std::string print() const;

private:
    unsigned int _width;
    unsigned int _height;
};