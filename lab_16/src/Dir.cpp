#include "Dir.h"

Dir::Dir(std::string name) : File(name) {}

Dir::~Dir() {
    std::cout << "Deleting Dir: " << this->getName() << std::endl;
    for (int i = 0; i < _size; i++) {
        std::cout << "About to delete " << _subDir[i]->getName() << std::endl;
        delete _subDir[i];
    }
}

void Dir::operator+=(File *file) {
    _subDir[_size] = file;
    _size++;
}

File* Dir::get(std::string name) {
    if(name == this->getName()) {
        return this;
    }
    File *tmp = nullptr;
    for (int i = 0; i < _size; i++) {
        tmp = _subDir[i]->get(name);
        if(tmp != nullptr){
            return tmp;
        }
    }
    return tmp;
}

void Dir::print(int size) const {
    for(int i = 0 ; i < size; i++) {
        std::cout << " ";
    }
    std::cout << this->getName() << std::endl;
    for (int i = 0; i < _size; i++) {
        _subDir[i]->print(size + 1);
    }
}
