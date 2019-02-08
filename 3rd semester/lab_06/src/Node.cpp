#include "Node.h"

Node::Node(int data) {
    _data = data;
    _next = nullptr;
    _previous = nullptr;
}

Node::Node() {
    _next = nullptr;
    _previous = nullptr;
}

Node::~Node() {}

int Node::data() const {
    return _data;
}

Node* Node::getNext() const {
    return _next;
}

Node* Node::getPrevious() const {
    return _previous;
}

void Node::setNext(Node *const next) {
    _next = next;
}

void Node::setPrevious(Node *const previous) {
    _previous = previous;
}