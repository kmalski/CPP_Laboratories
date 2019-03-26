#include "Dir.h"

Dir::Dir(std::string name) : File(name) {}

Dir::~Dir() {
    std::cout << "Deleting Dir: " << _name << std::endl;
    for (int i = 0; i < _size; i++) {
        std::cout << "About to delete " << _subdir[i]->getName() << std::endl;
        delete _subdir[i];
    }
}

void Dir::print(int size) const {
    for(int i = 0 ; i < size; i++) {
        std::cout << " ";
    }
    std::cout << this->getName() << std::endl;
    for (int i = 0; i < _size; i++) {
        _subdir[i]->print(size + 1);
    }
}

File * Dir::get(std::string name) {
    if(name == _name) {
        return this;
    }
    File *tmp = nullptr;
    for (int i = 0; i < _size; i++) {
        tmp = _subdir[i]->get(name);
        if(tmp) {
            return tmp;
        }
    }
    return tmp;
}

void Dir::operator+=(File *file) {
    _subdir[_size] = file;
    _size++;
}
