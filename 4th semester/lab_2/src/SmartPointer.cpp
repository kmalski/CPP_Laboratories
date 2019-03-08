#include "SmartPointer.h"

SmartPointer::SmartPointer(TestClassA *ptr) : _ptr(ptr) {
    _count = new int;
    *_count = 1;
}

SmartPointer::SmartPointer(const SmartPointer &copy) {
    _count = copy._count;
    (*_count)++;
    _ptr = copy._ptr;
}

SmartPointer::~SmartPointer() {
    *_count -= 1;
    if (*_count == 0) {
        delete _ptr;
        delete _count;
    }
}

SmartPointer & SmartPointer::operator=(const SmartPointer &copy) {
    if(&copy == this)
        return *this;
    *(_count) -= 1;
    if(*(_count) == 0) {
        delete _ptr;
        delete _count;
    }
    _count = copy._count;
    _ptr = copy._ptr;
    *(_count) += 1;
    return *this;
}

TestClassA & SmartPointer::operator*() {
    return *_ptr;
}

const TestClassA & SmartPointer::operator*() const {
    return *_ptr;
}

TestClassA * SmartPointer::operator->() {
    return _ptr;
}

const TestClassA * SmartPointer::operator->() const {
    return _ptr;
}
