#include "TestClassA.h"

TestClassA::TestClassA(string name) : _name(name) {
    cout << ".. Konstruuje TestClassA " << _name << endl;
}

TestClassA::~TestClassA() {
    cout << ".. Usuwam  TestClassA " << _name << endl;
}

string TestClassA::name() const{
    return _name;
}
