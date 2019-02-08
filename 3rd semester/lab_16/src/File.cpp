#include "File.h"

File::File(std::string name) : _name(name) {}

File::~File() {}

File* File::get(std::string name) {
    if(name == _name) {
        return this;
    }
    return nullptr;
}

std::string File::getName() const {
    return _name;
}

void File::print(int size) const {
    for(int i = 0 ; i < size; i++) {
        std::cout << " ";
    }
    std::cout << _name << std::endl;
}

std::ostream& operator<<(std::ostream& out, const File& file) {
    file.print(0);
    return out << "";
}
