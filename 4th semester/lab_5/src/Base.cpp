#include "Base.h"

Base::Base(const std::string& name) : _name(name) {}

std::string Base::getName() const {
    return _name;
}

std::ostream& operator<<(std::ostream& out, const Base& base) {
    base.print(0);
    return out << "";
}
