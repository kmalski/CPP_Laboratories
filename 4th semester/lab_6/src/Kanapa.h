#pragma once

#include "Lozko.h"
#include "Sofa.h"

class Kanapa :  public Sofa, public Lozko {
public:
    Kanapa(const int width, const int height, const int length, const int seat, const int forSleep);
    ~Kanapa();
    void print() const;

private:

};