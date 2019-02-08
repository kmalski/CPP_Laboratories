#include "List.h"
#include <iostream>

Node *prepareNewNode(const int array[][2]) {
    Node *tmp = new Node();

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            tmp->data[i][j] = array[i][j];
        }
    }
    
    tmp->next = nullptr;
    return tmp;
}

void prepare(List *list) {
    list->head = nullptr;
    list->tail = nullptr;
}

void prepare(List *to, const List *from) {
    Node *tmp = from->head;
    while(tmp != nullptr) {
        add(to, tmp->data);
        tmp = tmp->next;
    }
}

void add(List *list, int array[][2]) {
    if(empty(list)) {
        list->head = list->tail = prepareNewNode(array);
    } else {
        list->tail->next = prepareNewNode(array);
        list->tail = list->tail->next;
    }
}

bool empty(const List *list) {
    return list->head == nullptr;
}

void print(const List *list) {
    for(int i = 0; i < 2; i++) {
        Node *tmp = list->head;
        while(tmp != nullptr) {
            for(int j = 0; j < 2; j++) {
                std::cout << tmp->data[i][j] << " ";
            }
            std::cout << "  ";
            tmp = tmp->next;
        }
        std::cout << std::endl;
    }
}

void clear(List *list) {
    Node *tmp = list->head;
    Node *toDelete;
    while(tmp != nullptr) {
        toDelete = tmp;
        tmp = tmp->next;
        delete toDelete;
    }
    list->head = list->tail = nullptr;
}

