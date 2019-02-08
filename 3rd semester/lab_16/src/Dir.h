#pragma once

#include "File.h"

/*
* klasa Dir dziediczy po klasie File, ponieważ używa jej interfejsu.
*/

class Dir : public File {
    public:
        Dir(std::string name);

        ~Dir();

        void operator+=(File *file);

        File* get(std::string name) ;

        void print(int size) const;

    private:
        File *_subDir[10];
        int _size = 0;
};
