#pragma once

#include "Fun.h"

class ProstaRozniczka {
    public:
        ProstaRozniczka(double h);

        ProstaRozniczka* z(Fun* fun);

        double  w(double x);

    private:
        double _h;

        Fun* _fun;
};