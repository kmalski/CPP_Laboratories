#include "Dir.h"

Dir::Dir(const std::string& name) : Base(name) {}

Dir::~Dir() {
    std::cout << "Deleting Dir: " << _name << std::endl;
    for (int i = 0; i < _size; i++) {
        std::cout << "About to delete " << _subdir[i]->getName() << std::endl;
        delete _subdir[i];
    }
}

Base * Dir::get(const std::string& name) {
    if(name == _name) {
        return this;
    }
    Base *tmp = nullptr;
    for (int i = 0; i < _size; i++) {
        tmp = _subdir[i]->get(name);
        if(tmp) {
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
        _subdir[i]->print(size + 1);
    }
}

void Dir::operator+=(Base *base) {
    _subdir[_size] = base;
    _size++;
}

Dir * Dir::findDir(const std::string& name) {
    Base *tmp = this->get(name);
    if(tmp && dynamic_cast<Dir *>(tmp)) {
        return dynamic_cast<Dir *>(tmp);
    }
    return nullptr;
}

void Dir::add(Dir *dir) {
    *this += dir;
}
