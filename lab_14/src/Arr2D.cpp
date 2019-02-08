#include "Arr2D.h"

void operator<<=(std::string txt, const Arr2D& arr) {
    std::cout << txt << std::endl;
    arr.print();
    std::cout << txt << std::endl;
}

Arr2D::Arr2D(int height, int width, bool memoryAdmin) : _height(height), _width(width), _memoryAdmin(memoryAdmin) {
    if(_memoryAdmin) {
        _data = new int[height * width];
        for (int i = 0; i < height * width; i++) {
            _data[i] = 0;
        }
    }
}

Arr2D::Arr2D(const Arr2D& arr) : _height(arr._height), _width(arr._width) {
    _memoryAdmin = true;
    _data = new int[_height * _width];
    for (int i = 0; i < _height * _width; i++) {
        _data[i] = arr._data[i];
    }
}

Arr2D::~Arr2D() {
    if (_memoryAdmin) {
        delete[] _data;
    }
}

Arr2D Arr2D::adopt(int *data, int height, int width) {
    Arr2D tmp(height, width, false);
    tmp._data = data;
    return tmp;
}

void Arr2D::operator=(const Arr2D& arr) {
    _height = arr._height;
    _width = arr._width;
    if (_memoryAdmin) {
        delete[] _data;
    }
    _memoryAdmin = true;
    _data = new int[_height * _width];
    for (int i = 0; i < _height * _width; i++) {
        _data[i] = arr._data[i];
    }
}

void Arr2D::print() const {
    for (int i = 0; i < _height; i++) {
        for (int j = 0; j < _width; j++) {
            std::cout << _data[i * _width + j] << " ";
        }
        std::cout << std::endl;
    }
}

int* Arr2D::operator[](int raw) {
    return _data + raw * _width;
}
