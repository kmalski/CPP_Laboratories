#pragma once

#include "Mebel.h"

class Lozko : virtual public Mebel {
public:
    Lozko(const int width, const int height, const int length, const int forSleep);
    Lozko(const int forSleep);
    ~Lozko();
    void print() const;

protected:
    int _forSleep;
};