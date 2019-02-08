#include "List.h"
#include <iostream>

List::List(){
    _head = nullptr;
    _tail = nullptr;
}

List::List(const List& a) {
    _head = new Node(a._head->data());
    Node *current = _head;
    Node *tmp = a._head->getNext();
    while (tmp != nullptr) {
        Node *copy = new Node(tmp->data());
        current->setNext(copy);
        copy->setPrevious(current);
        current = current->getNext();
        tmp = tmp->getNext();
    }
    _tail = current;
}

List::~List() {
    Node *tmp = _head;
    Node *toDelete;
    while (tmp != nullptr) {
        toDelete = tmp;
        tmp = tmp->getNext();
        delete toDelete;
    }
}

const Node* List::find(int value) const{
    Node *tmp = _head;
    while (tmp != nullptr && tmp->data() != value) {
        tmp = tmp->getNext();
    }
    return tmp;
}

List& List::insert(int value, const mode m) {
    Node *tmp = new Node(value);
    if(!_head) {
        _head = _tail = tmp;
    } else if (m == Begin) {
        _head->setPrevious(tmp);
        tmp->setNext(_head);
        _head = tmp;
    }
    else {
        _tail->setNext(tmp);
        tmp->setPrevious(_tail);
        _tail = tmp;
    }
    return *this;
}

void List::print() const {
    std::cout << "[";
    Node *tmp = _head;
    while(tmp != nullptr) {
        std::cout << " " << tmp->data();
        tmp = tmp->getNext();
    }
    std::cout << "]"<< std::endl;
}