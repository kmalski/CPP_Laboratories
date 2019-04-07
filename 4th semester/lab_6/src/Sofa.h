#pragma once

#include "Mebel.h"

class Sofa : virtual public Mebel {
public:
    Sofa(const int width, const int height, const int length, const int seat);
    Sofa(const int seat);
    ~Sofa();
    void print() const;

protected:
    int _seat;
};