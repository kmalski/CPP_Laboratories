#pragma once

#include <iostream>

using namespace std;

class TestClassA {
public:
    TestClassA(string name);

    ~TestClassA();

    string name() const;

private:
    string _name;
	
};
