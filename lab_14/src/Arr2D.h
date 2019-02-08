#pragma once

#include <iostream>

class Arr2D {
    public:
        Arr2D(int height, int width, bool memoryAdmin = true);

        Arr2D(const Arr2D& arr);

        ~Arr2D();

        static Arr2D adopt(int *data, int height, int width);

        void operator=(const Arr2D& arr);

        void print() const;

        int* operator[](int raw);

    private:
        int _height;

        int _width;

        int *_data;

        bool _memoryAdmin;

};

void operator<<=(std::string txt, const Arr2D& arr);
