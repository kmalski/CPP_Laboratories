#include "File.h"

File::File(const std::string& name) : Base(name) {}

Base * File::get(const std::string& name) {
    if(name == _name) {
        return this;
    }
    return nullptr;
}

void File::print(int size) const {
    for (int i = 0; i < size; i++) {
        std::cout << " ";
    }
    std::cout << _name << std::endl;
}


