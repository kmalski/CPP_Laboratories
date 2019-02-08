#pragma once

#include <iostream>

/*
* klasa File jest klasą bazową, ponieważ posiada metody oraz argument _name, które używa również klasa Dir. Ten sposób dziedziczenia pozwala
* również na tworzenie drzewka katalogow bez wiedzy o tym czy skladowa jest plikiem czy katalogiem. Klasa Dir uzywa wszystkich metod z klasy 
* File, ale posiada również dodatkowe metody i dodatkowe argumenty, więc dziedziczenie w drugą strone nie jest dobrym pomysłem.
*/

class File {
    public:
        File(std::string name);

        virtual ~File();

        virtual File* get(std::string name);

        virtual void print(int size) const;

        std::string getName() const;

    private:
        std::string _name;
};

std::ostream& operator<<(std::ostream& out, const File& file);
