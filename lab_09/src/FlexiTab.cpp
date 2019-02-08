#include <iostream>
#include "FlexiTab.h"

using std::cout;
using std::endl;

FlexiTab::FlexiTab(const int begin, const int end) : _begin(begin), _end(end) {
    _tab = new double[_end - _begin];
}

FlexiTab::FlexiTab(const FlexiTab &copy) : _begin(copy.getMinIndex()), _end(copy.getMaxIndex()) {
    _tab = new double[copy.getSize()];
    int index = copy.getMinIndex();
    for (int i = 0; i < copy.getSize(); i++, index++) {
        _tab[i] = copy.at(index);
    }
}

FlexiTab::FlexiTab(const FlexiTab &copy, const int begin, const int end) : _begin(begin), _end(end) {
    int size = _end - _begin;
    int index = _begin;
    _tab = new double[size];
    for(int i = 0; i < size; i++, index++) {
        _tab[i] = copy.at(index);
    }
}

FlexiTab::~FlexiTab() {
    delete[] _tab;
}

void FlexiTab::setAll(const double value) {
    for(int i = 0; i < this->getSize(); i++) {
        _tab[i] = value;
    }
}

int FlexiTab::getSize() const {
    return _end - _begin;
}

int FlexiTab::getMaxIndex() const {
    return _end;
}
        
int FlexiTab::getMinIndex() const {
    return _begin;
}

double & FlexiTab::at(const int index) const {
    return _tab[index - _begin];
}

bool FlexiTab::inRange(const int index) const {
    if (index >= _begin && index < _end) {
        return true;
    }
    return false;
}

void FlexiTab::print(const FlexiTab &tab) {
    int index = tab.getMinIndex();
    for (int i = 0; i < tab.getSize(); i++, index++) {
        cout << index << ":" << tab.at(index) << " ";
    }
}
