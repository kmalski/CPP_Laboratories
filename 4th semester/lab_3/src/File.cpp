#include "File.h"

File::File(std::string name) : _name(name) {}

File * File::get(std::string name) {
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

std::string File::getName() const {
    return _name;
}

std::ostream& operator<<(std::ostream& out, const File& file) {
    file.print(0);
    return out << "";
}
