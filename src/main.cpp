#include <iostream>
#include "lists/arraylist.h"
#include "lists/singlyll.h"
#include "lists/doublyll.h"
using namespace std;

int main() {
    List* list = new DoublyLinkedList();
    list->addLast(20);
    list->addFirst(10);
    list->addLast(30);
    list->print();
    cout << "Element at position 2: " << list->get(2) << endl;
    // list->removeLast();
    // list->print();
    delete list;
}